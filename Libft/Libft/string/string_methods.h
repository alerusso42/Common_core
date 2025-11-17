/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_methods.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:23:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/17 19:27:26 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_METHODS_H
# define STRING_METHODS_H
# include "string.h"
# include "string_macros.h"

typedef struct s_str			t_str;
typedef struct s_str_methods	t_str_methods;
typedef enum e_str_error		t_str_error;
typedef int32_t					err;

t_str	str_constructor(t_str *str, char *init);
err		_str_get_methods(t_str *s);
t_str	*str_p_constructor(t_str *str, char *init);
int		_str_set_error(t_str *str, int err, char *func_name);

# define str_check(name, other)	STR_OVERLOAD_CHECK(str_check, name, other)
bool	str_check_char(t_str *this, char *other);
bool	str_check_str(t_str *this, t_str *other);
bool	str_check_this(t_str *this, void *empty);

# define str_m(name, ...)	t_str	*(*name)(t_str *, __VA_ARGS__);

# define STR_METHODS	\
	int32_t	(*get_len)(t_str *);\
	err		(*set_i)(t_str *);\
	int32_t	(*get_i)(t_str *);\
	bool	(*atoi)(t_str *, int32_t *);\
	str_m(cat_char, char *, int32_t)\
	str_m(cat_str, t_str *, int32_t)\
	str_m(cmp_char, char *)\
	str_m(cmp_str, t_str *)\
	str_m(cut_char, char *, int32_t, int32_t)\
	str_m(cut_str, t_str *, int32_t, int32_t)\
	str_m(dup_char, char *)\
	str_m(dup_str, t_str *)\
	str_m(find_chr, char)\
	str_m(find_char, char *, int32_t)\
	str_m(find_str, t_str *, int32_t)\
	str_m(itoa, int32_t)\
	str_m(join_char, char *)\
	str_m(join_str, t_str *)\
	void	(*lower)(t_str *);\
	str_m(ncmp_char, char *, int32_t)\
	str_m(ncmp_str, t_str *, int32_t)\
	void	(*reverse)(t_str *);\
	str_m(rfind_chr, char)\
	str_m(rfind_char, char *, int32_t)\
	str_m(rfind_str, t_str *, int32_t)\
	void	(*sort)(t_str *);\
	str_m(sub_char, char *)\
	str_m(sub_str, t_str *)\
	str_m(trim_char, char *)\
	str_m(trim_str, t_str *)\
	void	(*upper)(t_str *);\

# define get_len(name)		str_get_len(name)
int		str_get_len(t_str *str);
# define get_i(name)		str_get_start_index(name)
int		str_get_start_index(t_str *str);
# define set_i(name, T)		str_set_start_index(name, T)
void	str_set_start_index(t_str *str, int i);

# define atoi(name, T)	str_atoi(name, T)
err		str_atoi(t_str *str, int *n);

#define cat(name, T1, T2)		STR_OVERLOAD_2(cat, name, T1, T2)
t_str	*str_cat_char(t_str *this, char *other, int32_t n);
t_str	*str_cat_str(t_str *this, t_str *other, int32_t n);

#define cmp(name, T)      		STR_OVERLOAD(cmp, name, T)
int32_t	str_cmp_char(t_str *this, char *other);
int32_t	*str_cmp_str(t_str *this, t_str *other);

#define cut(name, T1, T2)	str_cut(name, T1, T2)
t_str	*str_cut(t_str *this, int32_t start, int32_t end);

# define dup(name, T)			STR_OVERLOAD(dup, name, T)
t_str	*str_dup_char(t_str *this, const char *other);
t_str	*str_dup_str(t_str *this, t_str *other);

# define find(name, T1, T2)		STR_OVERLOAD_2(find, name, T1, T2)
t_str	*str_find_chr(t_str *this, char other, int32_t n);
t_str	*str_find_char(t_str *this, char *other, int32_t n);
t_str	*str_find_str(t_str *this, t_str *other, int32_t n);

#define itoa(name, T)			STR_OVERLOAD(itoa, name, T)
t_str	*str_itoa(t_str *this, int32_t value);

#define join(name, T)			STR_OVERLOAD(join, name, T)
t_str	*str_join_char(t_str *this, char *other);
t_str	*str_join_str(t_str *this, t_str *other);

# define lower(name)			str_lower(name)
void	str_lower(t_str *str);

#define ncmp(name, T1, T2)  	STR_OVERLOAD_2(ncmp, name, T1, T2)
t_str 	*str_ncmp_char(t_str *this, char *other, int32_t n);
t_str 	*str_ncmp_str(t_str *this, t_str *other, int32_t n);

# define reverse(name)			str_reverse(name)
void	str_reverse(t_str *str);

# define rfind(name, T1, T2)	STR_OVERLOAD_2(rfind, name, T1, T2)
t_str	*str_rfind_chr(t_str *this, char other, int32_t n);
t_str	*str_rfind_char(t_str *this, char *other, int32_t n);
t_str	*str_rfind_str(t_str *this, t_str *other, int32_t n);

# define sort(name)				str_sort(name)
void	str_sort(t_str *str);

# define sub(name, T)			STR_OVERLOAD(sub, name, T)
t_str	*str_sub_char(t_str *this, char *other);
t_str	*str_sub_str(t_str *this, t_str *other);

# define trim(name, T)			STR_OVERLOAD(trim, name, T)
t_str	*str_trim_char(t_str *this, char *other);
t_str	*str_trim_str(t_str *this, t_str *other);

# define upper(name)			str_upper(name)
void	str_upper(t_str *str);

#endif