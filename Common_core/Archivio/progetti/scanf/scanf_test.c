#include <unistd.h>
#include <stdarg.h>
#include "ft_printf.h"

void	ft_scanf(const char *format, ...);
int		ft_read_int(void);
void	ft_read_string(char *str, int max_length);

int	main(void)
{
	int		x;
	char	str[100];

	ft_printf("Inserisci un intero: ");
	ft_scanf("%d", &x);
	ft_printf("Hai inserito: %d\n", x);

	ft_printf("Inserisci una stringa: ");
	ft_scanf("%s", str);
	ft_printf("Hai inserito: %s\n", str);

	return (0);
}

void	ft_scanf(const char *str, ...)
{
	va_list	args;
	int		index;
	int		*int_ptr;
	char	*str_ptr;

	index = -1;
	va_start(args, str);
	while (str[++index] != '\0')
	{
		if (str[index] == '%' && str[index + 1] != '\0')
		{
			if (str[++index] == 'd')
			{
				int_ptr = va_arg(args, int *);
				*int_ptr = ft_read_int();
			}
			if (str[index] == 's')
			{
				str_ptr = va_arg(args, char *);
				ft_read_string(str_ptr, 100);
			}
		}
	}
	va_end(args);
}

int	ft_read_int(void)
{
	char	str[40];
	int		index;
	char	c;
	int		num;
	int		is_negative;

	index = 0;
	num = 0;
	is_negative = 0;
	while (read(STDIN_FILENO, &c, 1) > 0 && c != '\n')
		str[index++] = c;
	str[index] = '\0';
	index = 0;
	if (str[0] == '-')
	{
		is_negative = 1;
		index++;
	}
	while (str[index] != '\0')
		num = num * 10 + (str[index++] - '0');
	if (is_negative == 1)
		return (-num);
	return (num);
}

void	ft_read_string(char *str, int max_length)
{
	char	c;
	int		index;

	index = 0;
	while (read(STDIN_FILENO, &c, 1) > 0)
	{
		if (c == '\n')
			break ;
		if (index == max_length - 1)
			break ;
		str[index++] = c;
	}
	str[index] = '\0';
}
