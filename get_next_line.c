#include "get_next_line.h"
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	int			res;
	int         flag;
	char		buf[BUF_SIZE + 1];
	static char	*str;
	char        *position_n;

	if (fd < 0 || line == NULL)
		return (-1);
	flag = 1;
	if (str)
		*line = ft_strdup(str);
	else
		*line = ft_strnew(1);

	while (flag && (res = read(fd, buf, BUF_SIZE)))
	{
		buf[res] = '\0';
		if (position_n = ft_strchr(buf, '\n'))
		{
			*position_n = '\0';
			position_n++;
			flag = 0;
			str = ft_strdup(position_n);
		}
		*line = ft_strjoin(*line, buf);
	}
	return (0);
}

int	main(void) {
	int		fd;
	int		ret;
	char    *line;

	fd = open("/Users/jmacmill/Desktop/42/gnl/sample.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() unable to open the file");
		return (1);
	}
	get_next_line(fd, &line);
	printf("Result #1 : %s\n", line);

	get_next_line(fd, &line);
	printf("Result #2 : %s\n", line);

	get_next_line(fd, &line);
	printf("Result #3 : %s\n", line);

	if (close(fd) == -1)
	{
		ft_putstr("close() error");
		return (1);
	}
	return (0);
}
