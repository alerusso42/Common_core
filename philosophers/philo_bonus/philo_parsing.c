
#include "philo_bonus.h"

int	is_all_digit(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < 48) || (argv[i][j] > 57))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	max_check(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (ft_atol(argv[i]) > 2147483647)
			return (0);
		i++;
	}
	return (1);
}

int	valid_time(char **argv)
{
	int	i;

	i = 0;
	while (i != 3 && argv[i])
	{
		if (ft_atol(argv[i]) < 60)
			return (0);
		i++;
	}
	return (1);
}

int	parsing(char **argv)
{
	if (is_all_digit(&argv[1]) == 0 || max_check(&argv[1]) == 0
		|| valid_time(&argv[2]) == 0)
		return (0);
	return (1);
}
