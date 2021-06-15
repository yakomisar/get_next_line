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
			ft_strcpy(*str, result);
		}
		else
		{
			*line = ft_strdup(*str);
			ft_strclr(*str);
		}
	}
	else
		*line = ft_strnew(1);
	return (result);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*box;
	char		*position_n;
	int			file;
	char		*temp;

	file = 1;
	position_n = check_remainder(&box, line);
	while (!position_n && file > 0)
	{
		file = read(fd, buf, BUFFER_SIZE);
		if (file >= 0)
			buf[file] = '\0';
		else
			return (-1);
		position_n = ft_strchr(buf, '\n');
		if (position_n)
		{
			*position_n = '\0';
			position_n++;
			box = ft_strdup(position_n);
		}
		temp = *line;
		*line = ft_strjoin(*line, buf);
		free(temp);
	}
	if (ft_strlen(*line) || file)
		return (1);
	else
	{
		*line = ft_calloc(1,1);
		return (0);
	}
}

int	main(void) {
    int		fd;
    char    *line;
    
    fd = open("/Users/olegkomisarenko/Desktop/42/gnl/sample.txt", O_RDONLY);
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
