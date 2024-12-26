#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

int	main()
{
	int	fd;

	fd = open("minitest.c", O_RDONLY);
	if (fd == -1)
		return (write(1, "AAA", 3));
	char	buf[310];
	if (read(fd, buf, 310) == -1)
		return ((write(1, "BBB", 3)));
	buf[282] = 0;
	write(1, buf, 310);
}