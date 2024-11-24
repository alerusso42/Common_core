#include <unistd.h>

int	main(int argc, char *argv[])
{
	int	index;
	int	alpha;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (42);
	}
	index = 0;
	while (argv[1][index])
	{
		if (argv[1][index] >= 65 && argv[1][index] <= 90)
		{
			alpha = argv[1][index] - 63;
			while (--alpha != 0)
				write(1, &argv[1][index], 1);
		}
		else if (argv[1][index] >= 97 && argv[1][index] <= 122)
		{
			alpha = argv[1][index] - 95;		
			while (--alpha != 0)
				write(1, &argv[1][index], 1);
		}
		else
			write(1, &argv[1][index], 1);
		++index;
	}
	write(1, "\n", 1);
	return (0);
}
