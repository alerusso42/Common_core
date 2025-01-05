#include <unistd.h>
#include <fcntl.h>

void	copy_file_to_file(int fd)
{
	int		fd_2;
	char	*temp;
	char	*temp_2;
	int		line_num;

	if (fd == -1)
		return ;
	write(fd, "SPACE FOR STRUCT DATA.\nFEEL FREE TO CHANGE THE DATA.\n\n", 54);
	write(fd, "[DEFAULT]\n", 10);
	fd_2 = open("default_values.txt", O_RDONLY);
	line_num = find_number_line(fd, "default_values.txt", 1, "[LIST]");
	if (line_num == -1)
		return ;
	line_num++;
	temp = get_next_line(fd, 0);
	if (!temp)
		return ;
	while (*temp_2 != '[')
	{
		temp = ft_strjoin_custom(temp, temp_2);
		if (!temp)
			return ;
		temp_2 = get_next_line(fd, 0);
		if (!temp_2)
			return ;
	}
	free(temp_2);
	write(fd, temp, ft_strlen(temp));
	free(temp);
	close(fd_2);
}