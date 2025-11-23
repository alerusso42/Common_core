/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_methods.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:23:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/23 19:47:45 by codespace        ###   ########.fr       */
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
t_str	*_str_set_error(t_str *str, int err, char *func_name);
void	_str_set(t_str *this);
t_str	*_str_reset(t_str *this, int i);

# define str_check(name, other)	STR_OVERLOAD_CHECK(str_check, name, other)
bool	str_check_char(t_str *this, const char *other);
bool	str_check_str(t_str *this, t_str *other);
bool	str_check_this(t_str *this, void *empty);

# define str_m(name, ...)	t_str	*(*name)(t_str *, __VA_ARGS__);

# define STR_METHODS	\
	int32_t	(*get_len)(t_str *);\
	void	(*set_i)(t_str *, int32_t);\
	int32_t	(*get_i)(t_str *);\
	int32_t	(*cmp_char)(t_str *, char *);\
	int32_t	(*cmp_str)(t_str *, t_str *);\
	str_m(cut_str, int32_t, int32_t)\
	str_m(diff_chr, char)\
	str_m(diff_char, const char *)\
	str_m(diff_str, t_str *)\
	str_m(find_chr, char)\
	str_m(find_char, const char *)\
	str_m(find_str, t_str *)\
	str_m(first_chr, char)\
	str_m(first_char, char *)\
	str_m(first_str, t_str *)\
	str_m(itoa_str, int32_t)\
	str_m(join_char, const char *, int32_t n)\
	str_m(join_str, t_str *, int32_t n)\
	str_m(last_chr, char)\
	str_m(last_char, char *)\
	str_m(last_str, t_str *)\
	t_str	*(*lower_str)(t_str *);\
	int32_t	(*ncmp_char)(t_str *, char *, int32_t);\
	int32_t	(*ncmp_str)(t_str *, t_str *, int32_t);\
	t_str	*(*reverse_str)(t_str *);\
	str_m(rdiff_chr, char)\
	str_m(rdiff_char, const char *)\
	str_m(rdiff_str, t_str *)\
	str_m(rfind_chr, char)\
	str_m(rfind_char, const char *)\
	str_m(rfind_str, t_str *)\
	str_m(sdup_char, const char *)\
	str_m(sdup_str, t_str *)\
	err		(*satoi_str)(t_str *, int32_t *);\
	t_str	*(*sort_str)(t_str *);\
	t_str	*(*upper_str)(t_str *);\

# define get_len(name)		str_get_len(name)
int		str_get_len(t_str *str);
# define get_i(name)		str_get_start_index(name)
int		str_get_start_index(t_str *str);
# define set_i(name, T)		str_set_start_index(name, T)
void	str_set_start_index(t_str *str, int i);

#define cmp(name, T)      		STR_OVERLOAD(cmp, name, T)
int32_t	str_cmp_char(t_str *this, char *other);
int32_t	str_cmp_str(t_str *this, t_str *other);

#define cut(name, T1, T2)	str_cut(name, T1, T2)
t_str	*str_cut(t_str *this, int32_t start, int32_t end);

# define diff(name, T1, T2)		STR_OVERLOAD_2(diff, name, T1)
t_str	*str_diff_chr(t_str *this, char other);
t_str	*str_diff_char(t_str *this, const char *other);
t_str	*str_diff_str(t_str *this, t_str *other);

# define find(name, T)		STR_OVERLOAD(find, name, T)
t_str	*str_find_chr(t_str *this, char other);
t_str	*str_find_char(t_str *this, const char *other);
t_str	*str_find_str(t_str *this, t_str *other);

# define first(name, T1)		STR_OVERLOAD_2(first, name, T1)
t_str	*str_first_chr(t_str *this, char other);
t_str	*str_first_char(t_str *this, const char *other);
t_str	*str_first_str(t_str *this, t_str *other);

#define itoa(name, T)			STR_OVERLOAD(itoa, name, T)
t_str	*str_itoa(t_str *this, int32_t value);

#define join(name, T1, T2)			STR_OVERLOAD_2(join, name, T1, T2)
t_str	*str_join_char(t_str *this, const char *other, int32_t n);
t_str	*str_join_str(t_str *this, t_str *other, int32_t n);

# define last(name, T1)		STR_OVERLOAD_2(last, name, T1)
t_str	*str_last_chr(t_str *this, char other);
t_str	*str_last_char(t_str *this, const char *other);
t_str	*str_last_str(t_str *this, t_str *other);

# define lower(name)			str_lower(name)
t_str	*str_lower(t_str *str);

#define ncmp(name, T1, T2)  	STR_OVERLOAD_2(ncmp, name, T1, T2)
int32_t	str_ncmp_char(t_str *this, char *other, int32_t n);
int32_t	str_ncmp_str(t_str *this, t_str *other, int32_t n);

# define rdiff(name, T1, T2)		STR_OVERLOAD_2(rdiff, name, T1)
t_str	*str_rdiff_chr(t_str *this, char other);
t_str	*str_rdiff_char(t_str *this, const char *other);
t_str	*str_rdiff_str(t_str *this, t_str *other);

# define reverse(name)			str_reverse(name)
t_str	*str_reverse(t_str *str);

# define rfind(name, T1)	STR_OVERLOAD_2(rfind, name, T1)
t_str	*str_rfind_chr(t_str *this, char other);
t_str	*str_rfind_char(t_str *this, const char *other);
t_str	*str_rfind_str(t_str *this, t_str *other);

# define satoi(name, T)	str_satoi(name, T)
err		str_satoi(t_str *str, int *n);

# define sdup(name, T)			STR_OVERLOAD(sdup, name, T)
t_str	*str_sdup_char(t_str *this, const char *other);
t_str	*str_sdup_str(t_str *this, t_str *other);

# define sort(name)				str_sort(name)
t_str	*str_sort(t_str *str);

# define upper(name)			str_upper(name)
t_str	*str_upper(t_str *str);

#endif