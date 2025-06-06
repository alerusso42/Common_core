#include "philo_bonus.h"

int	main(int arc, char **argv)
{
	t_table	table;

	if (arc != 5 && arc != 6)
		return (printf("WRONG NUMBER OF ARGUMENTS!!\n"), 1);
	if (parsing(argv) == 0 || ft_atol(argv[1]) == 0)
		return (printf("NOT CORRECT ARGUMENT, PLEASE TRY AGAIN!!\n"), 1);
	table = (t_table){0};
	table.n_philo = ft_atol(argv[1]);
	table.t_death = ft_atol(argv[2]) * 1e3;
	table.t_eat = ft_atol(argv[3]) * 1e3;
	table.t_sleep = ft_atol(argv[4]) * 1e3;
	if (arc == 6)
		table.max_dinner = ft_atol(argv[5]);
	else
		table.max_dinner = -1;
	init_table(&table);
	//GO FILO GO
	clear(&table);
}