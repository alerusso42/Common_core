#include <unistd.h>

int	is_unique(int sr_len, char *search, char character)
{
	int	diff;
	int	is_unique;

	is_unique = 1;
	diff = sr_len - 1;
	while (diff != -1)
	{
		if (character == search[diff])
		{
			is_unique = 0;
			break ;
		}
		--diff;
	}
	return (is_unique);
}

int	char_sr(int len, char *needle, char *str, char *search)
{
	int	ned_len;
	int	sr_len;

	ned_len = 0;
	sr_len = 0;
	while (needle[ned_len])
	{
		len = 0;
		while(str[len])
		{
			if (needle[ned_len] == str[len])
			{
				if (is_unique(sr_len, search, str[len]) == 1)
				{
					search[sr_len] = needle[ned_len];
					++sr_len;
				}
				break ;
			}
			++len;
		}
		++ned_len;
	}
	return (sr_len);
}

int	main(int argc, char *argv[])
{
	int	len;
	char	search[50];

	if (argc != 3)
	{
		write(1, "\n", 1);
		return (0);
	}
	len = 0;
	len = char_sr(len, argv[1], argv[2], search);
	write(1, &search[0], len);
	write(1, "\n", 1);
       	return (0);
}
