#include <unistd.h>

int	first_word(int len, char *str, char *first)
{
	int	f_len;

	while (str[len] == 32 || str[len] == 9 || str[len] == 11)
		++len;
	if (str[len] == '\0')
	{
		first[0] = '0';
		return (0);
	}
	f_len = 0;
	while (str[len] && str[len] != 32 && str[len] != 9 && str[len] != 11)
	{
		first[f_len] = str[len];
		++len;
		++f_len;
	}
	return (f_len);
}

int	main(int argc, char *argv[])

{
	int	len;
	char	first[50];
	
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	len = 0;
	first[0] = 'a';
	len = first_word(len, argv[1], first);
	write(1, &first[0], len);
	write(1, "\n", 1);
	return (0);
}
