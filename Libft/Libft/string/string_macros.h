/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_macros.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:50:27 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/17 19:25:37 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_MACROS_H
# define STRING_MACROS_H
# include "string.h"

typedef struct s_str			t_str;
typedef struct s_str_methods	t_str_methods;
typedef enum e_str_error		t_str_error;
typedef int32_t					err;

//REVIEW - STR_OVERLOAD
/*
	f:	 	the name of the function
	name:	the name of the string object
	T:		the type of the variable it receives

	example: #define func_name(param)	STR_OVERLOAD(func_name, obj_name, param)
	see it as a switch case:

	switch (T)
	{
		case (char*):
			f ## _char	---> example:	print_char
		case (t_str):
			f ## _str	---> example:	print_str
		case (t_str*):
			f ## _ptr	---> example:	print_ptr
	}
*/
# define STR_OVERLOAD(f, name, T) _Generic((T), \
		char*:	str_ ## f ## _char,\
		t_str*:	str_ ## f ## _str)(name, T)

# define STR_OVERLOAD_2(f, name, T1, T2) _Generic((T1), \
		char*:	str_ ## f ## _char,\
		t_str*:	str_ ## f ## _str)(name, T1, T2)

# define STR_OVERLOAD_3(f, name, T1, T2, T3) _Generic((T1), \
		char*:	str_ ## f ## _char,\
		t_str*:	str_ ## f ## _str)(name, T1, T2, T3)

# define STR_OVERLOAD_CHECK(f, name, T) _Generic((T), \
		char*:	f ## _char,\
		void*:	f ## _this,\
		t_str*:	f ## _str)(name, T)

//SECTION - destructor

//	the function given to cleanup is called when the variable exits from its
//	scope
# define clean(base) __attribute__((cleanup(base ## _destructor)))
# define clean_ptr(base) __attribute__((cleanup(base ## _ptr_destructor)))

//SECTION - constructor

//	to call the constructor:	STR(variable_name, "initial buffer"), OR:
//								STR_P(variable_name, "initial buffer)
//
//	in the first case, the object t_str is allocated on the stack (t_str);
//	in the second case, is allocated on the heap (t_str *).
//
//	first should be used as: 	string.print(&string);
//	second should be used as: 	string->print(string);
# define STR(name, init) t_str clean(str) name = str_constructor(&name, init)
# define STR_P(name, init) t_str clean(str) *name = str_p_constructor(name, init)

# ifndef SYSCALLS
#  define SYSCALLS
#  define FREE 		free
#  define MALLOC	malloc
#  define CALLOC	calloc
# endif

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

#endif