#include "get_next_line.h"
#include <stdio.h>


char	*check_remainder(char **str, char **line)
{
    char	*result;

    result = NULL;
    if (*str)
    {
        if ((result = ft_strchr(*str, '\n')))
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
    char        *position_n;

    if (fd < 0 || line == NULL)
        return (-1);
    position_n = check_remainder(&str, line);
    while (!position_n && (res = read(fd, buf, BUF_SIZE)))
    {
        buf[res] = '\0';
        if ((position_n = ft_strchr(buf, '\n')))
        {
            *position_n = '\0';
            position_n++;
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

    fd = open("/Users/olegkomisarenko/Desktop/42/get_next_line/sample.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("open() unable to open the file");
        return (1);
    }
    get_next_line(fd, &line);
    printf("Result #1 : %s\n", line);

    get_next_line(fd, &line);
    printf("Result #2 : %s\n", line);

    get_next_line(fd, &line);
    printf("Result #3 : %s\n", line);

    get_next_line(fd, &line);
    printf("Result #4 : %s\n", line);

	get_next_line(fd, &line);
    printf("Result #5 : %s\n", line);

	get_next_line(fd, &line);
    printf("Result #6 : %s\n", line);

	get_next_line(fd, &line);
    printf("Result #7 : %s\n", line);

    if (close(fd) == -1)
    {
        printf("close() error");
        return (1);
    }
    return (0);
}