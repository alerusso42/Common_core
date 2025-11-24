/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_methods.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 13:23:44 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/24 23:04:27 by alerusso         ###   ########.fr       */
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
void	_str_destructor(t_str *str);
err		_str_get_methods(t_str *s);
t_str	*str_p_constructor(t_str *str, char *init);
t_str	*_str_set_error(t_str *str, int err, char *func_name);
void	_str_set(t_str *this);
t_str	*_str_reset(t_str *this, int i);
bool	_str_identifier(const void *p);

# define str_check(name, other)	STR_OVERLOAD_CHECK(str_check, name, other)
bool	str_check_char(t_str *this, const char *other);
bool	str_check_str(t_str *this, const t_str *other);
bool	str_check_this(t_str *this, const void *empty);

# define str_m(name, ...)	t_str	*(*name)(t_str *, __VA_ARGS__);

# define STR_METHODS	\
	int32_t	(*get_len)(t_str *);\
	void	(*set_i)(t_str *, int32_t);\
	int32_t	(*get_i)(t_str *);\
	str_m(str_addl, char c)\
	str_m(str_addr, char c)\
	int32_t	(*str_cmp)(t_str *, const void *);\
	str_m(str_cpy, const void *)\
	str_m(str_cut, int32_t, int32_t)\
	str_m(str_diff, const void *)\
	str_m(str_excpy, const void *, const void *)\
	str_m(str_find, const void *)\
	str_m(str_first, const void *)\
	str_m(str_incpy, const void *, const void *)\
	str_m(str_itoa, int32_t)\
	str_m(str_join, const void *, int32_t n)\
	str_m(str_last, const void *)\
	t_str	*(*str_lower)(t_str *);\
	int32_t	(*str_ncmp)(t_str *, const void *, int32_t);\
	str_m(str_ncpy, const void *, int32_t, int32_t)\
	t_str	*(*str_reverse)(t_str *);\
	str_m(str_rdiff, const void *)\
	str_m(str_rfind, const void *)\
	str_m(str_sdup, const void *)\
	err		(*str_satoi)(t_str *, int32_t *);\
	t_str	*(*str_sort)(t_str *);\
	t_str	*(*str_sfree)(t_str *);\
	str_m(str_srealloc, int32_t)\
	t_str	*(*str_upper)(t_str *);

# define get_len(name)		str_get_len(name)
int		str_get_len(t_str *str);
# define get_i(name)		str_get_start_index(name)
int		str_get_start_index(t_str *str);
# define set_i(name, T)		str_set_start_index(name, T)
void	str_set_start_index(t_str *str, int i);

# define addl(name, ...)	str_addl(name, __VA_ARGS__)
t_str	*str_addl(t_str *this, char c);

# define addr(name, ...)	str_addr(name, __VA_ARGS__)
t_str	*str_addr(t_str *this, char c);

#define cmp(name, ...)		str_cmp(name, __VA_ARGS__)
int32_t	str_cmp(t_str *this, const void *other);
int32_t	str_cmp_char(t_str *this, const char *other);
int32_t	str_cmp_str(t_str *this, const t_str *other);

# define cpy(name, ...)		str_cpy(name, __VA_ARGS__)
t_str	*str_cpy(t_str *this, const void *other);
t_str	*str_cpy_char(t_str *this, const char *other);
t_str	*str_cpy_str(t_str *this, const t_str *other);

#define cut(name, ...)	str_cut(name, __VA_ARGS__)
t_str	*str_cut(t_str *this, int32_t start, int32_t end);

# define diff(name, ...)		str_diff(name, __VA_ARGS__)
t_str	*str_diff(t_str *this, const void *other);
t_str	*str_diff_chr(t_str *this, const char other);
t_str	*str_diff_char(t_str *this, const char *other);
t_str	*str_diff_str(t_str *this, const t_str *other);

# define excpy(name, ...)	str_excpy(name, __VA_ARGS__)
t_str	*str_excpy(t_str *this, const void *other, const void *set);

# define find(name, ...)		str_find(name, __VA_ARGS__)
t_str	*str_find(t_str *this, const void *other);
t_str	*str_find_chr(t_str *this, char other);
t_str	*str_find_char(t_str *this, const char *other);
t_str	*str_find_str(t_str *this, const t_str *other);

# define first(name, ...)		str_first(name, __VA_ARGS__)
t_str	*str_first(t_str *this, const void *other);
t_str	*str_first_chr(t_str *this, char other);
t_str	*str_first_char(t_str *this, const char *other);
t_str	*str_first_str(t_str *this, const t_str *other);

# define incpy(name, ...)	str_incpy(name, __VA_ARGS__)
t_str	*str_incpy(t_str *this, const void *other, const void *set);
t_str	*str_scpy_char(t_str *this, const char *other, const char *set, int m);
t_str	*str_scpy_str(t_str *this, const t_str *other, const char *set, int m);

#define itoa(name, ...)			str_itoa(name, __VA_ARGS__)
t_str	*str_itoa(t_str *this, int32_t value);

#define join(name, ...)		str_join(name, __VA_ARGS__)
t_str	*str_join(t_str *this, const void *other, int32_t n);
t_str	*str_join_char(t_str *this, const char *other, int32_t n);
t_str	*str_join_str(t_str *this, const t_str *other, int32_t n);

# define last(name, ...)		str_last(name, __VA_ARGS__)
t_str	*str_last(t_str *this, const void *other);
t_str	*str_last_chr(t_str *this, char other);
t_str	*str_last_char(t_str *this, const char *other);
t_str	*str_last_str(t_str *this, const t_str *other);

# define lower(name)			str_lower(name)
t_str	*str_lower(t_str *str);

#define ncmp(name, ...)		str_ncmp(name, __VA_ARGS__)
int32_t	str_ncmp(t_str *this, const void *other, int32_t n);
int32_t	str_ncmp_char(t_str *this, const char *other, int32_t n);
int32_t	str_ncmp_str(t_str *this, const t_str *other, int32_t n);

# define ncpy(name, ...)	str_ncpy(name, __VA_ARGS__)
t_str	*str_ncpy(t_str *this, const void *other, int32_t start, int32_t n);
t_str	*str_ncpy_char(t_str *this, const char *other, int32_t strt, int32_t n);
t_str	*str_ncpy_str(t_str *this, const t_str *other, int32_t strt, int32_t n);

# define rdiff(name, ...)		str_rdiff(name, __VA_ARGS__)
t_str	*str_rdiff(t_str *this, const void *other);
t_str	*str_rdiff_chr(t_str *this, char other);
t_str	*str_rdiff_char(t_str *this, const char *other);
t_str	*str_rdiff_str(t_str *this, const t_str *other);

# define reverse(name)			str_reverse(name)
t_str	*str_reverse(t_str *str);

# define rfind(name, ...)		str_rfind(name, __VA_ARGS__)
t_str	*str_rfind(t_str *this, const void *other);
t_str	*str_rfind_chr(t_str *this, char other);
t_str	*str_rfind_char(t_str *this, const char *other);
t_str	*str_rfind_str(t_str *this, const t_str *other);

# define satoi(name, T)	str_satoi(name, T)
err		str_satoi(t_str *str, int *n);

# define sdup(name, ...)		str_sdup(name, __VA_ARGS__)
t_str	*str_sdup(t_str *this, const void *other);
t_str	*str_sdup_char(t_str *this, const char *other);
t_str	*str_sdup_str(t_str *this, const t_str *other);

# define sort(name)				str_sort(name)
t_str	*str_sort(t_str *str);

# define sfree(name)	str_sfree(name)
t_str	*str_sfree(t_str *this);

# define srealloc(name, ...)	str_srealloc(name, __VA_ARGS__)
t_str	*str_srealloc(t_str *this, int32_t n);

# define upper(name)			str_upper(name)
t_str	*str_upper(t_str *str);

#endif