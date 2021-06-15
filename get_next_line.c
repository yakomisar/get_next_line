#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char *ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

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
			free(*str);
			*str = NULL;
		}
	}
	else
	{
		*line = ft_strnew(1);
	}
	return (result);
}

int	get_result(char *str, int res)
{
	if (str || res)
		return (1);
	else
		return (0);
}

int	get_next_line(int fd, char **line)
{
	int			res;
	char		buf[BUFFER_SIZE + 1];
	static char	*str;
	char		*position_n;
	char		*temp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, NULL, 0) < 0))
		return (-1);
	position_n = check_remainder(&str, line);
	res = 1;
	while (!position_n && (res > 0))
	{
		res = read(fd, buf, BUFFER_SIZE);
		buf[res] = '\0';
		position_n = ft_strchr(buf, '\n');
		if (position_n)
		{
			*position_n = '\0', position_n++;
			str = ft_strdup(position_n);
		}
		temp = *line;
		*line = ft_strjoin(*line, buf);
		free(temp);
	}
	if (ft_strlen(*line))
        return (1);
	return (0);
}

int	main(void) {
    int		fd;
    char    *line;
    
    fd = open("/Users/jmacmill/Desktop/42/gnl/sample.txt", O_RDONLY);
	//fd = open("/Users/jmacmill/Desktop/42/gnl/41_no_nl", O_RDONLY);
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
	sleep(10);
    return (0);
}