#include "get_next_line.h"
#include <stdio.h>

char	*check_remainder(char **str, char **line)
{
	char		*result;

	result = NULL;
	if (*str)
	{
		result = ft_strchr(*str, '\n');
		if (result)
		{
			*result = '\0';
			result++;
			*line = ft_strdup(*str);
			*str = ft_strdup(result);
		}
		else
		{
			*line = ft_strdup(*str);
			ft_strclr(*str);
		}
	}
	else
	{
		*line = ft_strnew(1);
	}
	return (result);
}

int	get_next_line(int fd, char **line)
{
	int			res;
	char		buf[BUF_SIZE + 1];
	static char	*str;
	char		*position_n;
    char        *temp;

	if (fd < 0 || line == NULL)
		return (-1);
	position_n = check_remainder(&str, line);
    while (!position_n && (res = read(fd, buf, BUF_SIZE)))
	{
		buf[res] = '\0';
		position_n = ft_strchr(buf, '\n');
		if (position_n)
		{
			*position_n = '\0';
			position_n++;
			str = ft_strdup(position_n);
		}
        temp = *line;
		*line = ft_strjoin(*line, buf);
        free(temp);
	}
	if (ft_strlen(*line) || res)
		return (1);
	else
		return (0);
}

int	main(void) {
    int		fd;
    char    *line;
    
    fd = open("/Users/jmacmill/Desktop/42/gnl/sample.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("open() unable to open the file");
        return (1);
    }
    while ((get_next_line(fd, &line)))
        printf("Result # : %s\n", line);
    if (close(fd) == -1)
    {
        printf("close() error");
        return (1);
    }
    return (0);
}
