#include "ft_printf.h"

/*
int	main(void)
{
	char	c;
	int		x;
	char	*str;

	c = 'A';
	x = -42;
	char	some_character_are_nonprintable[] = {32, 65, 48, 92, 16, 20, 127, 57, 0};
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
	printf("%d = COUNTER\n", ft_printf("PROVA 13: %s\n", some_character_are_nonprintable));
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
	//char	some_character_are_nonprintable[] = {32, 65, 48, 92, 16, 20, 127, 57, 0};
	printf("%d = COUNTER\n", ft_printf("PROVA 13: %s\n", some_character_are_nonprintable));
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
*/


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


int	main(void)
{
	char	c = 'A';
	int		x = -42;
	char	*str = "Vincere e vinceremo";
	char	some_nonprintable[] = {32, 65, 48, 92, 16, 20, 127, 57, 0};
	int		zero = 0;
	int		num = -42;
	unsigned int u_num = 42;
	void	*ptr = (void *)&num;

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
	printf("%d = COUNTER\n", printf("Left-aligned: |%-5c|\n", c));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-5c|\n", c));

	// Test flags with `s`
	printf("==== Flags with %%s ====\n");
	printf("%d = COUNTER\n", printf("Basic string: |%s|\n", str));
	printf("%d = COUNTER\n", ft_printf("Basic string: |%s|\n", str));
	printf("%d = COUNTER\n", printf("Left-aligned: |%-20s|\n", str));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-20s|\n", str));
	printf("%d = COUNTER\n", printf("Precision: |%.5s|\n", str));
	printf("%d = COUNTER\n", ft_printf("Precision: |%.5s|\n", str));
	printf("%d = COUNTER\n", printf("Width and precision: |%10.5s|\n", str));
	printf("%d = COUNTER\n", ft_printf("Width and precision: |%10.5s|\n", str));

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
	printf("%d = COUNTER\n", ft_printf("Width and precision: |%10.5d|\n", num));

	// Test flags with `u`
	printf("==== Flags with %%u ====\n");
	printf("%d = COUNTER\n", printf("Basic unsigned: |%u|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Basic unsigned: |%u|\n", u_num));
	printf("%d = COUNTER\n", printf("Left-aligned: |%-10u|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-10u|\n", u_num));
	printf("%d = COUNTER\n", printf("Zero-padded: |%010u|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Zero-padded: |%010u|\n", u_num));
	printf("%d = COUNTER\n", printf("Width and precision: |%10.5u|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Width and precision: |%10.5u|\n", u_num));

	// Test flags with `x` and `X`
	printf("==== Flags with %%x and %%X ====\n");
	printf("%d = COUNTER\n", printf("Basic hex lowercase: |%x|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Basic hex lowercase: |%x|\n", u_num));
	printf("%d = COUNTER\n", printf("Basic hex uppercase: |%X|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Basic hex uppercase: |%X|\n", u_num));
	printf("%d = COUNTER\n", printf("With # flag (lowercase): |%#x|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("With # flag (lowercase): |%#x|\n", u_num));
	printf("%d = COUNTER\n", printf("With # flag (uppercase): |%#X|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("With # flag (uppercase): |%#X|\n", u_num));
	printf("%d = COUNTER\n", printf("Left-aligned: |%-10x|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-10x|\n", u_num));
	printf("%d = COUNTER\n", printf("Zero-padded: |%010x|\n", u_num));
	printf("%d = COUNTER\n", ft_printf("Zero-padded: |%010x|\n", u_num));

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
	printf("%d = COUNTER\n", printf("Basic pointer: |%p|\n", ptr));
	printf("%d = COUNTER\n", ft_printf("Basic pointer: |%p|\n", ptr));
	printf("%d = COUNTER\n", printf("Left-aligned: |%-20p|\n", ptr));
	printf("%d = COUNTER\n", ft_printf("Left-aligned: |%-20p|\n", ptr));
	printf("%d = COUNTER\n", printf("Zero-padded (ignored): |%020p|\n", ptr));
	printf("%d = COUNTER\n", ft_printf("Zero-padded (ignored): |%020p|\n", ptr));


	// Precision
	printf("==== Precision ====\n");
	printf("%d = COUNTER\n", printf("Precision on int: %.5d\n", x));
	printf("%d = COUNTER\n", ft_printf("Precision on int: %.5d\n", x));
	printf("%d = COUNTER\n", printf("Precision on string: %.5s\n", str));
	printf("%d = COUNTER\n", ft_printf("Precision on string: %.5s\n", str));

	// Non-printable characters
	printf("==== Non-Printable Characters ====\n");
	printf("%d = COUNTER\n", printf("Non-printable: %s\n", some_nonprintable));
	printf("%d = COUNTER\n", ft_printf("Non-printable: %s\n", some_nonprintable));

	// unsigned
	printf("==== Unsigned ====\n");
	printf("%d = COUNTER\n", printf("Unsigned: %u\n", 42));
	printf("%d = COUNTER\n", ft_printf("Unsigned: %u\n", 42));

	// Extra formatting
	printf("==== Additional Formatting ====\n");
	printf("%d = COUNTER\n", printf("Hex uppercase: %#X\n", 42));
	printf("%d = COUNTER\n", ft_printf("Hex uppercase: %#X\n", 42));
	printf("%d = COUNTER\n", printf("Multiple specifiers: Char: %c Int: %d String: %s\n", c, x, str));
	printf("%d = COUNTER\n", ft_printf("Multiple specifiers: Char: %c Int: %d String: %s\n", c, x, str));

	// Invalid format specifiers
	printf("==== Invalid Specifiers ====\n");
	printf("%d = COUNTER\n", printf("Invalid specifier: %y\n", c));
	printf("%d = COUNTER\n", ft_printf("Invalid specifier: %y\n", c));

	return 0;
}
