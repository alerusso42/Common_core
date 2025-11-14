/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 22:08:36 by alerusso          #+#    #+#             */
/*   Updated: 2025/11/14 23:31:41 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

typedef struct str	t_str;
t_str	str_constructor(t_str *str, char *init);

#define OVERLOAD_STR(base, x) _Generic(x, \
		char*:	base ## _char,\
		t_str:	base ## _str,\
		t_str*:	base ## _ptr,\
		int:	base ## _int\
		)(x)

#define autoclean(S) __attribute__((cleanup(clean_ ## S))) 
		
#define print(x) OVERLOAD_STR(print, x)
#define STR(var_name, s) \
		t_str autoclean(str) var_name = (t_str)str_constructor(&var_name, s)
		
struct str
{
	t_str	*this;
	char	*buff;
	int		len;
	
	void	(*printer)(char *s);
};

void	print_char(const char *s) {printf("%s\n", s);}
void	print_str(t_str s) {printf("%s\n", s.buff);}
void	print_ptr(t_str *s) {printf("%s\n", s->buff);}
void	print_int(int len) {printf("%d\n", len);}
void	clean_str(t_str *str) {printf("%s:\tclean ok!\n", str->buff);}

void	printer(char *s)
{
	(void)s;
}

void	test(t_str *s, char *str)
{
	printf("%s+%s\n", s->buff, str);
}

t_str	str_constructor(t_str *str, char *init)
{
	str->buff = init;
	str->len = strlen(init);
	str->this = str;
	/*void	print_bind(char *s){
		test(str, s);
	}
	str->printer = print_bind;*/
	return (*str);
}

#define test(T) print_char(&string, T)

int	main()
{{
	char	*s = "test";
	STR(str, s);
	t_str	*ptr;

	str.buff = s;
	ptr = &str;
	print(s);
	print(str);
	print(ptr);
	print(str.len);
}
	STR(string, "Mega Rayquaza");
	print(string);
	string.printer("ciao");
}
