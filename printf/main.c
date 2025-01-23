/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:28:28 by alerusso          #+#    #+#             */
/*   Updated: 2025/01/23 16:46:13 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
int	main()
{
	printf("%d = COUNTER\n", printf("Test!"));
	printf("%d = COUNTER\n", ft_printf("Test!"));
	return (0);
}
*/

int	main(void)
{
	char	c;
	int		x;
	char	*str;

	c = 'A';
	x = -42;
	char	some_character_are_nonprintable[] = {32, 65, 48, 92, 16, 20, \
	127, 57, 0};
	printf("%d = COUNTER\n", printf("hex: %# +70.50p|\n", str));
	printf("%d = COUNTER\n", ft_printf("hex: %#+p\n", str));
	printf("%d = COUNTER\n", printf("PROVA 3: %015.1dz\n", 42));
	printf("%d = COUNTER\n", printf("PROVA 4: %+dz\n", 42));
	printf("%d = COUNTER\n", printf("PROVA 5: % dz\n", 42));
	printf("%d = COUNTER\n", printf("PROVA 6: %+ dz\n", 42));
	printf("%d = COUNTER\n", ft_printf("PROVA 3: %015.1dz\n", 42));
	printf("%d = COUNTER\n", ft_printf("PROVA 4: %+dz\n", 42));
	printf("%d = COUNTER\n", ft_printf("PROVA 5: % dz\n", 42));
	printf("%d = COUNTER\n", ft_printf("PROVA 6: %+ dz\n", 42));
	printf("%d = COUNTER\n", printf("ciao %55.7s", "Mondo !"));
	printf("%d = COUNTER\n", ft_printf("ciao %55.7s", "Mondo !"));
	printf("%d = COUNTER\n", ft_printf("PROVA 13: %s\n",\
	 some_character_are_nonprintable));
	str = "Vincere e vinceremo";
	printf("Printf vero: \n");
	printf("Char:%c\n Int:%d\n Char *:%s\n", c, x, str);
	printf("PROVA 1: %#-#-#--+ 32#.56s\n%d\n", 42);
	printf("PROVA2: %##0-#+ 15.36sz\n", "123456789");
	ft_printf("CUSTOM: %##0-#+ 15.36sz\n", "123456789");
	printf("PROVA 3: %015.1dz\n", 42);
	printf("PROVA 4: %+dz\n", 42);
	printf("PROVA 5: % dz\n", 42);
	printf("PROVA 6: %+ dz\n", 42);
	printf("PROVA 7: %#-8o\n", 42);
	printf("PROVA 8: %#08o\n", 42);
	printf("PROVA 9: %#6o\n", 0);
	printf("PROVA 10: %#8.4x\n", 42);
	printf("PROVA 11: /%c/\n", 28);
	printf("PROVA char: %#7+707.12c\n", '!');
	printf("PROVA 12: %yc\n", 'A');
	//char	some_character_are_nonprintable[] = {32, 65, 48, 92, 16, 20,\
	 127, 57, 0};
	printf("%d = COUNTER\n", ft_printf("PROVA 13: %s\n",\
	 some_character_are_nonprintable));
	printf("PROVA 14: %.70345s\n", "ROCKY");
	printf("PROVA 15: %.s\n", "ROCKY");
	printf("Printf custom: \n");
	printf("///\n\n");
	ft_printf("PROVA 12: %yc\n", 'A');
	ft_printf("%d = SIZE\n", ft_printf("PROVA char: %#7+707.12c\n", '!'));
	ft_printf("%c\n", '!');
	//ft_printf("Char:%c\n Int:%d\n Char *:%s\n", c, x, str);
	return (0);
}

	/*	unsigned int	is_minus_flag:1;
	unsigned int	is_alt_form:1;
	unsigned int	is_space_flag:1;
	unsigned int	is_expsign_flag:1;
	unsigned int	is_zero_flag:1;
	unsigned int	is_width:1;
	unsigned int	is_width_zero:1;
	unsigned int	width_value;
	unsigned int	is_precision:1;
	unsigned int	precision_length;
	void			*specifier;
	unsigned int	save_index_position;*/

/*

int	main(void)
{
	char	c = 'A';
	int		x = INT_MAX;
	char	*str = "KONO DIO DA";
	char	some_nonprintable[] = {32, 65, 48, 92, 16, 20, 127, 57, 0};
	int		zero = 0;
	int		num = INT_MIN;
	unsigned int u_num = UINT_MAX - 1;
	void	*ptr = NULL;

	// TEST
	printf("%d = COUNTER\n", printf("Basic hex lowercase: |%x|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Basic hex lowercase: |%x|\n", u_num));
	// Compare basic functionality
	printf("==== Basic Tests ====\n");
	printf("%d = COUNTER\n", printf("Char: %c\n", c));
	printf("%d = COUNTER\n", ft_printf("Char: %c\n", c));
	printf("%d = COUNTER\n", printf("Int: %d\n", x));
	printf("%d = COUNTER\n", ft_printf("Int: %d\n", x));
	printf("%d = COUNTER\n", printf("String: %s\n", str));
	printf("%d = COUNTER\n", ft_printf("String: %s\n", str));
	printf("%d = COUNTER\n", printf("Pointer: %p\n", (void *)str));
	printf("%d = COUNTER\n", ft_printf("Pointer: %p\n", (void *)str));

	// Edge cases
	printf("==== Edge Cases ====\n");
	printf("%d = COUNTER\n", printf("Null string: %s\n", (char *)NULL));
	printf("%d = COUNTER\n", ft_printf("Null string: %s\n", (char *)NULL));
	printf("%d = COUNTER\n", printf("Empty string: %s\n", ""));
	printf("%d = COUNTER\n", ft_printf("Empty string: %s\n", ""));
	printf("%d = COUNTER\n", printf("Zero value: %d\n", zero));
	printf("%d = COUNTER\n", ft_printf("Zero value: %d\n", zero));

	// Flags and combinations
	printf("==== Flags and Width/Precision ====\n");
	printf("%d = COUNTER\n", printf("Zero-padded: %05d\n", x));
	printf("%d = COUNTER\n", ft_printf("Zero-padded: %05d\n", x));
	printf("%d = COUNTER\n", printf("Left-aligned: %-10d|\n", x));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: %-10d|\n", x));
	printf("%d = COUNTER\n", printf("Plus sign: %+d\n", x));
	printf("%d = COUNTER\n", ft_printf("Plus sign: %+d\n", x));
	printf("%d = COUNTER\n", printf("Space flag: % d\n", x));
	printf("%d = COUNTER\n", ft_printf("Space flag: % d\n", x));
	printf("%d = COUNTER\n", printf("Hex with # flag: %#x\n", x));
	printf("%d = COUNTER\n", ft_printf("Hex with # flag: %#x\n", x));

	// Test flags with `c`
	printf("==== Flags with %%c ====\n");
	printf("%d = COUNTER\n", printf("Basic char: |%c|\n", c));
	printf("%d = COUNTER\n", ft_printf("Basic char: |%c|\n", c));
	printf("%d = COUNTER\n", printf("Zero precision: |%.c|\n", c));
	printf("%d = COUNTER\n", ft_printf("Zero precision: |%.c|\n", c));
	printf("%d = COUNTER\n", printf("Left-aligned: |%-5c|\n", c));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-5c|\n", c));
	printf("%d = COUNTER\n", printf("Paco test  1: |%c %c %c|\n", '0', 0, '1')\
	);
	printf("%d = COUNTER\n", ft_printf("Paco test  1: |%c %c %c|\n", '0', 0, '\
	1'));
	printf("%d = COUNTER\n", printf("Paco test  2: |%c %c %c|\n", '2', '1', 0)\
	);
	printf("%d = COUNTER\n", ft_printf("Paco test  2: |%c %c %c|\n", '2', '1',\
	 0));
	printf("%d = COUNTER\n", printf("Paco test  3: |%c %c %c|\n", 0, '1', '2')\
	);
	printf("%d = COUNTER\n", ft_printf("Paco test  3: |%c %c %c|\n", 0, '1', '\
	2'));
	printf("%d = COUNTER\n", printf("Paco Weird stuff: |%%%c%%%s%%%d%%%i\
	%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%\
	%%x%%%X%%%% %c%%|\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42,\
	 -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));
	printf("%d = COUNTER\n", ft_printf("Paco Weird stuff: |%%%c%%%s%%%d%%%i\
	%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%%%%%c%%%s%%%d%%%i%%%u%%%\
	x%%%X%%%% %c%%|\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,\
	-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0));

	// Test flags with `s`
	printf("==== Flags with %%s ====\n");
	printf("%d = COUNTER\n", printf("Basic string: |%s|\n", str));
	printf("%d = COUNTER\n", ft_printf("Basic string: |%s|\n", str));
	printf("%d = COUNTER\n", printf("Left-aligned: |%-20s|\n", str));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-20s|\n", str));
	printf("%d = COUNTER\n", printf("Precision: |%.5s|\n", str));
	printf("%d = COUNTER\n", ft_printf("Precision: |%.5s|\n", str));
	printf("%d = COUNTER\n", printf("Width and precision: |%10.5s|\n", str));
	printf("%d = COUNTER\n", ft_printf("Width and precision: |%10.5s|\n",\
	 str));
	printf("%d = COUNTER\n", printf("Flags and NULL: |%-+ #10.5s|\n", NULL));
	printf("%d = COUNTER\n", ft_printf("Flags and NULL: |%-+ #10.5s|\n",\
	 NULL));

	// Test flags with `d` and `i`
	printf("==== Flags with %%d and %%i ====\n");
	printf("%d = COUNTER\n", printf("Basic int: |%d|\n", num));
	printf("%d = COUNTER\n", ft_printf("Basic int: |%d|\n", num));
	printf("%d = COUNTER\n", printf("Left-aligned: |%-10d|\n", num));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-10d|\n", num));
	printf("%d = COUNTER\n", printf("Zero-padded: |%010d|\n", num));
	printf("%d = COUNTER\n", ft_printf("Zero-padded: |%010d|\n", num));
	printf("%d = COUNTER\n", printf("Plus flag: |%+d|\n", num));
	printf("%d = COUNTER\n", ft_printf("Plus flag: |%+d|\n", num));
	printf("%d = COUNTER\n", printf("Space flag: |% d|\n", num));
	printf("%d = COUNTER\n", ft_printf("Space flag: |% d|\n", num));
	printf("%d = COUNTER\n", printf("Width and precision: |%10.5d|\n", num));
	printf("%d = COUNTER\n", ft_printf("Width and precision: |%10.5d|\n",\
	 num));

	// Test flags with `u`
	printf("==== Flags with %%u ====\n");
	printf("%d = COUNTER\n", printf("Basic unsigned: |%u|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Basic unsigned: |%u|\n", u_num));
	printf("%d = COUNTER\n", printf("Left-aligned: |%-10u|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-10u|\n", u_num));
	printf("%d = COUNTER\n", printf("Zero-padded: |%010u|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Zero-padded: |%010u|\n", u_num));
	printf("%d = COUNTER\n", printf("Width and precision: |%10.5u|\n", 42));
	printf("%d = COUNTER\n", ft_printf("Width and precision: |%10.5u|\n", 42));
	printf("%d = COUNTER\n", printf("Weird stuff: |%+ 10.7u|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Weird stuff: |%+ 10.7u|\n", u_num));

	// Test flags with `x` and `X`
	printf("==== Flags with %%x and %%X ====\n");
	printf("%d = COUNTER\n", printf("Basic hex lowercase: |%x|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Basic hex lowercase: |%x|\n", u_num));
	printf("%d = COUNTER\n", printf("Basic hex uppercase: |%X|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Basic hex uppercase: |%X|\n", u_num));
	printf("%d = COUNTER\n", printf("With # flag (lowercase): |%#x|\n",\
	 u_num));
	printf("%d = COUNTER\n", ft_printf("With # flag (lowercase): |%#x|\n",\
	 u_num));
	printf("%d = COUNTER\n", printf("With # flag (uppercase): |%#X|\n",\
	 u_num));
	printf("%d = COUNTER\n", ft_printf("With # flag (uppercase): |%#X|\n",\
	 u_num));
	printf("%d = COUNTER\n", printf("Left-aligned: |%-10x|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-10x|\n", u_num));
	printf("%d = COUNTER\n", printf("Zero-padded: |%010x|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Zero-padded: |%010x|\n", u_num));
	printf("%d = COUNTER\n", printf("Zero-padded with #: |%#010x|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Zero-padded with #: |%#010x|\n",\
	 u_num));
	 printf("%d = COUNTER\n", printf("Left-aligned: |%-10x|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-10x|\n", u_num));
	printf("%d = COUNTER\n", printf("Weird stuff #: |%#-+ 010x|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Weird stuff #: |%#-+ 010x|\n", u_num));
	printf("%d = COUNTER\n", printf("Weird stuff #: |%#-+ 010X|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Weird stuff #: |%#-+ 010X|\n", u_num));
	printf("%d = COUNTER\n", printf("Weird stuff zero: |%#-+ 010x|\n", 0));
	printf("%d = COUNTER\n", ft_printf("Weird stuff zero: |%#-+ 010x|\n", 0));
	printf("%d = COUNTER\n", printf("Weird stuff zero: |%#-+ 010X|\n", 0));
	printf("%d = COUNTER\n", ft_printf("Weird stuff zero: |%#-+ 010X|\n", 0));

	// Test flags with `%`
	printf("==== Flags with %%%% ====\n");
	printf("%d = COUNTER\n", printf("Basic percent: |%%|\n"));
	printf("%d = COUNTER\n", ft_printf("Basic percent: |%%|\n"));
	printf("%d = COUNTER\n", printf("Width: |%10%|\n"));
	printf("%d = COUNTER\n", ft_printf("Width: |%10%|\n"));
	printf("%d = COUNTER\n", printf("Left-aligned: |%-10%|\n"));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-10%|\n"));

	// Test flags with `p`
	printf("==== Flags with %%p ====\n");
	printf("%d = COUNTER\n", printf("Basic pointer: |%p|\n", NULL));
	printf("%d = COUNTER\n", ft_printf("Basic pointer: |%p|\n", NULL));
	printf("%d = COUNTER\n", printf("Left-aligned: |%-20p|\n", &ptr));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-20p|\n", &ptr));
	printf("%d = COUNTER\n", printf("Zero-padded (ignored): |%020p|\n", &ptr));
	printf("%d = COUNTER\n", ft_printf("Zero-padded (ignored): |%020p|\n",\
	 &ptr));
	printf("%d = COUNTER\n", printf("Weird stuff: |%###  0+ 20.7p|\n", &ptr));
	printf("%d = COUNTER\n", ft_printf("Weird stuff: |%###  0+ 20.7p|\n",\
	 &ptr));

	// Precision
	printf("==== Precision ====\n");
	printf("%d = COUNTER\n", printf("Precision on int: %.5d\n", x));
	printf("%d = COUNTER\n", ft_printf("Precision on int: %.5d\n", x));
	printf("%d = COUNTER\n", printf("Precision on string: %.5s\n", str));
	printf("%d = COUNTER\n", ft_printf("Precision on string: %.5s\n", str));
	printf("%d = COUNTER\n", printf("null Precision on int: %.d\n", x));
	printf("%d = COUNTER\n", ft_printf("null Precision on int: %.d\n", x));
	printf("%d = COUNTER\n", printf("null Precision on string: %.s\n", str));
	printf("%d = COUNTER\n", ft_printf("null Precision on string:\
	 %.s\n", str));

	// Non-printable characters
	printf("==== Non-Printable Characters ====\n");
	printf("%d = COUNTER\n", printf("Non-printable: %s\n", some_nonprintable));
	printf("%d = COUNTER\n", ft_printf("Non-printable: %s\n",\
	 some_nonprintable));

	// unsigned
	printf("==== Unsigned ====\n");
	printf("%d = COUNTER\n", printf("Unsigned: %u\n", 42));
	printf("%d = COUNTER\n", ft_printf("Unsigned: %u\n", 42));

	// Extra formatting
	printf("==== Additional Formatting ====\n");
	printf("%d = COUNTER\n", printf("Hex uppercase: %#X\n", 42));
	printf("%d = COUNTER\n", ft_printf("Hex uppercase: %#X\n", 42));
	printf("%d = COUNTER\n", printf("Multiple specifiers: Char: %c Int: %d\
	 String: %s\n", c, x, str));
	printf("%d = COUNTER\n", ft_printf("Multiple specifiers: Char: %c Int: \
	%d String: %s\n", c, x, str));

	// Invalid format specifiers
	printf("==== Invalid Specifiers ====\n");
	printf("%d = COUNTER\n", printf("Invalid specifier: %y\n%", c));
	printf("%d = COUNTER\n", ft_printf("Invalid specifier: %y\n%", c));

	// Failed paco test:
printf("FAILED PACO TEST: \n\n");
printf("%d = COUNTER\n", ft_printf("1: %.s\n", NULL));   // TEST n. 1
printf("%d = COUNTER\n\n", printf("1: %.s\n", NULL));   // TEST n. 1
printf("%d = COUNTER\n", ft_printf("2: %.s\n", "hello"));   // TEST n. 2
printf("%d = COUNTER\n\n", printf("2: %.s\n", "hello"));   // TEST n. 2
printf("%d = COUNTER\n", ft_printf("3: %.s\n", "NULL"));   // TEST n. 3
printf("%d = COUNTER\n\n", printf("3: %.s\n", "NULL"));   // TEST n. 3
printf("%d = COUNTER\n", ft_printf("4: %.s\n", "s_hidden"));   // TEST n. 4
printf("%d = COUNTER\n\n", printf("4: %.s\n", "s_hidden"));   // TEST n. 4
printf("%d = COUNTER\n", ft_printf("5: %3.s\n", "s_hidden"));   // TEST n. 5
printf("%d = COUNTER\n\n", printf("5: %3.s\n", "s_hidden"));   // TEST n. 5
printf("%d = COUNTER\n", ft_printf("6: %10.s\n", "s_hidden"));   // TEST n. 6 
printf("%d = COUNTER\n\n", printf("6: %10.s\n", "s_hidden"));   // TEST n. 6
printf("%d = COUNTER\n", ft_printf("7: %3.s\n", NULL));   // TEST n. 7
printf("%d = COUNTER\n\n", printf("7: %3.s\n", NULL));   // TEST n. 7
printf("%d = COUNTER\n", ft_printf("8: %10.s\n", NULL));   // TEST n. 8
printf("%d = COUNTER\n\n", printf("8:%10.s\n", NULL));   // TEST n. 8
printf("%d = COUNTER\n", ft_printf("9: %-3.s\n", "s_hidden"));   // TEST n. 9
printf("%d = COUNTER\n\n", printf("9: %-3.s\n", "s_hidden"));   // TEST n. 9
printf("%d = COUNTER\n", ft_printf("10: %-8.s\n", "s_hidden"));   // TEST n. 10
printf("%d = COUNTER\n\n", printf("10: %-8.s\n", "s_hidden"));   // TEST n. 10
printf("%d = COUNTER\n", ft_printf("11: %-3.s\n", NULL));   // TEST n. 11
printf("%d = COUNTER\n\n", printf("11: %-3.s\n", NULL));   // TEST n. 11
printf("%d = COUNTER\n", ft_printf("12: %-8.s\n", NULL));   // TEST n. 12
printf("%d = COUNTER\n\n", printf("12: %-8.s\n", NULL));   // TEST n. 12
printf("%d = COUNTER\n", ft_printf("13: %.4i\n", 5263));   // TEST n. 13
printf("%d = COUNTER\n\n", printf("13: %.4i\n", 5263));   // TEST n. 13
printf("%d = COUNTER\n", ft_printf("14: %.4i\n", -2372));   // TEST n. 14
printf("%d = COUNTER\n\n", printf("14: %.4i\n", -2372));   // TEST n. 14
printf("%d = COUNTER\n", ft_printf("15: %-8.5i\n", 34));   // TEST n. 15
printf("%d = COUNTER\n\n", printf("15: %-8.5i\n", 34));   // TEST n. 15
printf("%d = COUNTER\n", ft_printf("16: %-10.5i\n", -216));   // TEST n. 16
printf("%d = COUNTER\n\n", printf("16: %-10.5i\n", -216));   // TEST n. 16
printf("%d = COUNTER\n", ft_printf("17: %-8.5i\n", 0));   // TEST n. 17
printf("%d = COUNTER\n\n", printf("17: %-8.5i\n", 0));   // TEST n. 17
printf("%d = COUNTER\n", ft_printf("18: %-3.7i\n", 3267));   // TEST n. 18
printf("%d = COUNTER\n\n", printf("18: %-3.7i\n", 3267));   // TEST n. 18
printf("%d = COUNTER\n", ft_printf("19: %-3.7i\n", -2375));   // TEST n. 19
printf("%d = COUNTER\n\n", printf("19: %-3.7i\n", -2375));   // TEST n. 19
printf("%d = COUNTER\n", ft_printf("20: %.0i\n", 0));   // TEST n. 20
printf("%d = COUNTER\n\n", printf("20: %.0i\n", 0));   // TEST n. 20
printf("%d = COUNTER\n", ft_printf("21: %.c\n", 'a'));   // TEST n. 21
printf("%d = COUNTER\n\n", printf("21: %.c\n", 'a'));   // TEST n. 21
printf("%d = COUNTER\n", ft_printf("22: %5.0i\n", 0));   // TEST n. 22
printf("%d = COUNTER\n\n", printf("22: %5.0i\n", 0));   // TEST n. 22
printf("%d = COUNTER\n", ft_printf("23: %5.i\n", 0));   // TEST n. 23
printf("%d = COUNTER\n\n", printf("23: %5.i\n", 0));   // TEST n. 23
printf("%d = COUNTER\n", ft_printf("24: %-5.0i\n", 0));   // TEST n. 24
printf("%d = COUNTER\n\n", printf("24: %-5.0i\n", 0));   // TEST n. 24
printf("%d = COUNTER\n", ft_printf("25: %-5.i\n", 0));   // TEST n. 25
printf("%d = COUNTER\n\n", printf("25: %-5.i\n", 0));   // TEST n. 25
printf("%d = COUNTER\n", ft_printf("26: %5.0i\n", 0));   // TEST n. 26
printf("%d = COUNTER\n\n", printf("26: %5.0d\n", 0));   // TEST n. 26
printf("%d = COUNTER\n", ft_printf("27: %5.d\n", 0));   // TEST n. 27
printf("%d = COUNTER\n\n", printf("27: %5.d\n", 0));   // TEST n. 27
printf("%d = COUNTER\n", ft_printf("28: %-5.0d\n", 0));   // TEST n. 28
printf("%d = COUNTER\n\n", printf("28: %-5.0d\n", 0));   // TEST n. 28
printf("%d = COUNTER\n", ft_printf("29: %-5.d\n", 0));   // TEST n. 29
printf("%d = COUNTER\n\n", printf("29: %-5.d\n", 0));   // TEST n. 29
printf("%d = COUNTER\n", ft_printf("30: %-8.5u\n", 34));   // TEST n. 30
printf("%d = COUNTER\n\n", printf("30: %-8.5u\n", 34));   // TEST n. 30
printf("%d = COUNTER\n", ft_printf("31: %-8.5u\n", 0));   // TEST n. 31
printf("%d = COUNTER\n\n", printf("31: %-8.5u\n", 0));   // TEST n. 31
printf("%d = COUNTER\n", ft_printf("32: %-3.7u\n", 3267));   // TEST n. 32
printf("%d = COUNTER\n\n", printf("32: %-3.7u\n", 3267));   // TEST n. 32
printf("%d = COUNTER\n", ft_printf("33: %.0u\n", 0));   // TEST n. 33
printf("%d = COUNTER\n\n", printf("33: %.0u\n", 0));   // TEST n. 33
printf("%d = COUNTER\n", ft_printf("34: %.u\n", 0));   // TEST n. 34
printf("%d = COUNTER\n\n", printf("34: %.u\n", 0));   // TEST n. 34
printf("%d = COUNTER\n", ft_printf("35: |%5.0u|\n", 0));   // TEST n. 35
printf("%d = COUNTER\n\n", printf("35: |%5.0u|\n", 0));   // TEST n. 35
printf("%d = COUNTER\n", ft_printf("36: |%5.u|\n", 0));   // TEST n. 36
printf("%d = COUNTER\n\n", printf("36: |%5.u|\n", 0));   // TEST n. 36
printf("%d = COUNTER\n", ft_printf("37: %-5.0u\n", 0));   // TEST n. 37
printf("%d = COUNTER\n\n", printf("37: %-5.0u\n", 0));   // TEST n. 37
printf("%d = COUNTER\n", ft_printf("38: %-5.u\n", 0));   // TEST n. 38
printf("%d = COUNTER\n\n", printf("38: %-5.u\n", 0));   // TEST n. 38
printf("%d = COUNTER\n", ft_printf("39: %-8.5x\n", 34));   // TEST n. 39
printf("%d = COUNTER\n\n", printf("39: %-8.5x\n", 34));   // TEST n. 39
printf("%d = COUNTER\n", ft_printf("40: %-8.5x\n", 0));   // TEST n. 40
printf("%d = COUNTER\n\n", printf("40: %-8.5x\n", 0));   // TEST n. 40
printf("%d = COUNTER\n", ft_printf("41: %5.0i\n", 0));   // TEST n. 41
printf("%d = COUNTER\n\n", printf("41: %5.0i\n", 0));   // TEST n. 41
printf("%d = COUNTER\n", ft_printf("42: %5.i\n", 0));   // TEST n. 42
printf("%d = COUNTER\n\n", printf("42: %5.i\n", 0));   // TEST n. 42
printf("%d = COUNTER\n", ft_printf("43: %-5.0i\n", 0));   // TEST n. 43
printf("%d = COUNTER\n\n", printf("43: %-5.0i\n", 0));   // TEST n. 43
printf("%d = COUNTER\n", ft_printf("44: %-5.i\n", 0));   // TEST n. 44
printf("%d = COUNTER\n\n", printf("44: %-5.i\n", 0));   // TEST n. 44
printf("%d = COUNTER\n", ft_printf("45: %5.0d\n", 0));   // TEST n. 45
printf("%d = COUNTER\n\n", printf("45: %5.0d\n", 0));   // TEST n. 45
printf("%d = COUNTER\n", ft_printf("46: |%5.d|\n", 0));   // TEST n. 46
printf("%d = COUNTER\n\n", printf("46: |%5.d|\n", 0));   // TEST n. 46
printf("%d = COUNTER\n", ft_printf("47: |%-5.0d|\n", 0));   // TEST n. 47
printf("%d = COUNTER\n\n", printf("47: |%-5.0d|\n", 0));   // TEST n. 47
printf("%d = COUNTER\n", ft_printf("48: |%-5.d|\n", 0));   // TEST n. 48
printf("%d = COUNTER\n\n", printf("48: |%-5.d|\n", 0));   // TEST n. 48
printf("%d = COUNTER\n", ft_printf("49: |%.0x|\n", 0));   // TEST n. 49
printf("%d = COUNTER\n\n", printf("49: |%.0x|\n", 0));   // TEST n. 49
printf("%d = COUNTER\n", ft_printf("50: |%.x|\n", 0));   // TEST n. 50
printf("%d = COUNTER\n\n", printf("50: |%.x|\n", 0));   // TEST n. 50
printf("%d = COUNTER\n", ft_printf("51: |%5.0x|\n", 0));   // TEST n. 51
printf("%d = COUNTER\n\n", printf("51: |%5.0x|\n", 0));   // TEST n. 51
printf("%d = COUNTER\n", ft_printf("52: |%5.x|\n", 0));   // TEST n. 52
printf("%d = COUNTER\n\n", printf("52: |%5.x|\n", 0));   // TEST n. 52
printf("%d = COUNTER\n", ft_printf("53: |%-5.0x|\n", 0));   // TEST n. 53
printf("%d = COUNTER\n\n", printf("53: |%-5.0x|\n", 0));   // TEST n. 53
printf("%d = COUNTER\n", ft_printf("54: |%-5.x|\n", 0));   // TEST n. 54
printf("%d = COUNTER\n\n", ft_printf("54: |%-5.x|\n", 0));   // TEST n. 54
printf("%d = COUNTER\n\n", printf("54: |%-5.x|\n", 0));   // TEST n. 54
printf("%d = COUNTER\n\n", ft_printf("55: |%.0x|\n", 0)); // TEST n. 55
printf("%d = COUNTER\n\n", printf("55: |%.0x|\n", 0)); // TEST n. 55
printf("%d = COUNTER\n\n", ft_printf("56: |%.x|\n", 0)); // TEST n. 56
printf("%d = COUNTER\n\n", printf("56: |%.x|\n", 0)); // TEST n. 56
printf("%d = COUNTER\n\n", ft_printf("57: |%5.0x|\n", 0)); // TEST n. 57
printf("%d = COUNTER\n\n", printf("57: |%5.0x|\n", 0)); // TEST n. 57
printf("%d = COUNTER\n\n", ft_printf("58: |%5.x|\n", 0)); // TEST n. 58
printf("%d = COUNTER\n\n", printf("58: |%5.x|\n", 0)); // TEST n. 58
printf("%d = COUNTER\n\n", ft_printf("59: |%-5.0x|\n", 0)); // TEST n. 59
printf("%d = COUNTER\n\n", printf("59: |%-5.0x|\n", 0)); // TEST n. 59
printf("%d = COUNTER\n\n", ft_printf("60: |%-5.x|\n", 0)); // TEST n. 60
printf("%d = COUNTER\n\n", printf("60: |%-5.x|\n", 0)); // TEST n. 60
printf("%d = COUNTER\n\n", ft_printf("61: |%.0x|\n", 0)); // TEST n. 61
printf("%d = COUNTER\n\n", printf("61: |%.0x|\n", 0)); // TEST n. 61
printf("%d = COUNTER\n\n", ft_printf("62: |%.x|\n", 0)); // TEST n. 62
printf("%d = COUNTER\n\n", printf("62: |%.x|\n", 0)); // TEST n. 62
printf("%d = COUNTER\n\n", ft_printf("63: |%5.0x|\n", 0)); // TEST n. 63
printf("%d = COUNTER\n\n", printf("63: |%5.0x|\n", 0)); // TEST n. 63
printf("%d = COUNTER\n\n", ft_printf("64: |%5.x|\n", 0)); // TEST n. 64
printf("%d = COUNTER\n\n", printf("64: |%5.x|\n", 0)); // TEST n. 64
printf("%d = COUNTER\n\n", ft_printf("65: |%-5.0x|\n", 0)); // TEST n. 65
printf("%d = COUNTER\n\n", printf("65: |%-5.0x|\n", 0)); // TEST n. 65
printf("%d = COUNTER\n\n", ft_printf("66: |%-5.x|\n", 0)); // TEST n. 66
printf("%d = COUNTER\n\n", printf("66: |%-5.x|\n", 0)); // TEST n. 66
printf("%d = COUNTER\n\n", ft_printf("67: |%.0X|\n", 0)); // TEST n. 67
printf("%d = COUNTER\n\n", printf("67: |%.0X|\n", 0)); // TEST n. 67
printf("%d = COUNTER\n\n", ft_printf("68: |%.X|\n", 0)); // TEST n. 68
printf("%d = COUNTER\n\n", printf("68: |%.X|\n", 0)); // TEST n. 68
printf("%d = COUNTER\n\n", ft_printf("69: |%5.0X|\n", 0)); // TEST n. 69
printf("%d = COUNTER\n\n", printf("69: |%5.0X|\n", 0)); // TEST n. 69
printf("%d = COUNTER\n\n", ft_printf("70: |%5.X|\n", 0)); // TEST n. 70
printf("%d = COUNTER\n\n", printf("70: |%5.X|\n", 0)); // TEST n. 70
printf("%d = COUNTER\n\n", ft_printf("71: |%-5.0X|\n", 0)); // TEST n. 71
printf("%d = COUNTER\n\n", printf("71: |%-5.0X|\n", 0)); // TEST n. 71
printf("%d = COUNTER\n\n", ft_printf("72: |%-5.X|\n", 0)); // TEST n. 72
printf("%d = COUNTER\n\n", printf("72: |%-5.X|\n", 0)); // TEST n. 72
printf("%d = COUNTER\n\n", ft_printf("73: |%-2c%-3c%-4c%-1c%-2c%-3c\
%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c\
%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c|\n", (char)1, (char)2, (char)3, \
(char)4, (char)5, (char)6, (char)7, (char)8, (char)9, (char)10, \
(char)11, (char)12, (char)13, (char)14, (char)15, (char)16, \
(char)17, (char)18, (char)19, (char)20, (char)21, (char)22, (char)23, \
(char)24, (char)25, (char)26, (char)27, (char)28, (char)29, (char)30, \
(char)31)); // TEST n. 73
printf("%d = COUNTER\n\n", printf("73: |%-2c%-3c%-4c%-1c%-2c%-3c\
%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c\
%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c|\n", (char)1, (char)2, (char)3, \
(char)4, (char)5, (char)6, (char)7, (char)8, (char)9, (char)10, \
(char)11, (char)12, (char)13, (char)14, (char)15, (char)16, \
(char)17, (char)18, (char)19, (char)20, (char)21, (char)22, (char)23, \
(char)24, (char)25, (char)26, (char)27, (char)28, (char)29, (char)30, \
(char)31)); // TEST n. 73
printf("%d = COUNTER\n\n", ft_printf("74: |%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c\
%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c\
%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c\
%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c\
%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c\
%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c\
%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c\
%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c|\n", (char)128, (char)129, (char)130, \
(char)131, (char)132, (char)133, (char)134, (char)135, (char)136, (char)137, \
(char)138, (char)139, (char)140, (char)141, (char)142, (char)143, (char)144, \
(char)145, (char)146, (char)147, (char)148, (char)149, (char)150, (char)151, \
(char)152, (char)153, (char)154, (char)155, (char)156, (char)157, (char)158, \
(char)159, (char)160, (char)161, (char)162, (char)163, (char)164, (char)165, \
(char)166, (char)167, (char)168, (char)169, (char)170, (char)171, (char)172, \
(char)173, (char)174, (char)175, (char)176, (char)177, (char)178, (char)179, \
(char)180, (char)181, (char)182, (char)183, (char)184, (char)185, (char)186, \
(char)187, (char)188, (char)189, (char)190, (char)191, (char)192, (char)193, \
(char)194, (char)195, (char)196, (char)197, (char)198, (char)199, (char)200, \
(char)201, (char)202, (char)203, (char)204, (char)205, (char)206, (char)207, \
(char)208, (char)209, (char)210, (char)211, (char)212, (char)213, (char)214, \
(char)215, (char)216, (char)217, (char)218, (char)219, (char)220, (char)221, \
(char)222, (char)223, (char)224, (char)225, (char)226, (char)227, (char)228, \
(char)229, (char)230, (char)231, (char)232, (char)233, (char)234, (char)235, \
(char)236, (char)237, (char)238, (char)239, (char)240, (char)241, (char)242, \
(char)243, (char)244, (char)245, (char)246, (char)247, (char)248, (char)249, \
(char)250, (char)251, (char)252, (char)253, (char)254, \
(char)255)); // TEST n. 74
printf("%d = COUNTER\n\n", printf("74: |%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c\
%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c\
%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c\
%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c\
%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c\
%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c\
%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c\
%-3c%-4c%-1c%-2c%-3c%-4c%-1c%-2c%-3c%-4c|\n", (char)128, (char)129, (char)130, \
(char)131, (char)132, (char)133, (char)134, (char)135, (char)136, (char)137, \
(char)138, (char)139, (char)140, (char)141, (char)142, (char)143, (char)144, \
(char)145, (char)146, (char)147, (char)148, (char)149, (char)150, (char)151, \
(char)152, (char)153, (char)154, (char)155, (char)156, (char)157, (char)158, \
(char)159, (char)160, (char)161, (char)162, (char)163, (char)164, (char)165, \
(char)166, (char)167, (char)168, (char)169, (char)170, (char)171, (char)172, \
(char)173, (char)174, (char)175, (char)176, (char)177, (char)178, (char)179, \
(char)180, (char)181, (char)182, (char)183, (char)184, (char)185, (char)186, \
(char)187, (char)188, (char)189, (char)190, (char)191, (char)192, (char)193, \
(char)194, (char)195, (char)196, (char)197, (char)198, (char)199, (char)200, \
(char)201, (char)202, (char)203, (char)204, (char)205, (char)206, (char)207, \
(char)208, (char)209, (char)210, (char)211, (char)212, (char)213, (char)214, \
(char)215, (char)216, (char)217, (char)218, (char)219, (char)220, (char)221, \
(char)222, (char)223, (char)224, (char)225, (char)226, (char)227, (char)228, \
(char)229, (char)230, (char)231, (char)232, (char)233, (char)234, (char)235, \
(char)236, (char)237, (char)238, (char)239, (char)240, (char)241, (char)242, \
(char)243, (char)244, (char)245, (char)246, (char)247, (char)248, (char)249, \
(char)250, (char)251, (char)252, (char)253, (char)254, \
(char)255)); // TEST n. 74


	return 0;
}
*/
