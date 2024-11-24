#include <stdio.h>
#include <unistd.h>

int	change13(int len, char *str)
{
	while (str[len])
	{
		if (str[len] >= 65 && str[len] <= 90)
		{
			str[len] = str[len] + 13;
			if (str[len] >= 91)
			{
				str[len] = str[len] - 91;
				str[len] = str[len] + 'A';	
			}		
		}
		else if (str[len] >= 97 && str[len] <= 122)
		{
			if ((str[len] + 13) <= 122)
				str[len] = str[len] + 13;
			else
			{
				str[len] = 122 - str[len];
				str[len] = 'm' - str[len];	
			}	
		}
		++len;
	}
	return (len);
}

int	main(int argc, char *argv[])
{
	int	len;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	len = 0;
	len = change13(len, argv[1]);
	write(1, &argv[1][0], len);
	write(1, "\n", 1);
       	return (0);
}
