#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	int		res;
	char	buf[BUF_SIZE + 1];

	while ((res = read(fd, buf, BUF_SIZE))) {
		buf[res] = '\0';
	}
	return (0);
}

int	main(void) {
	int		fd;
	int		ret;
	char 	buf[BUF_SIZE + 1];

	fd = open("sample.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() unable to open the file");
		return (1);
	}
	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}
