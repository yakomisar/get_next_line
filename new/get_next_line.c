#include "get_next_line.h"
//#include <stdio.h>

int	save_line(char **line, char **box)
{
	char	*position_n;
	int		result;

	position_n = ft_strchr(*box, '\n');
	if (position_n)
	{
		*position_n = '\0';
		*line = ft_strdup(*box);
		position_n++;
		ft_strcpy(*box, position_n);
		result = 1;
	}
	else
	{
		*line = ft_strdup(*box);
		free(*box);
		*box = NULL;
		result = 0;
	}
	return (result);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*box;
	char		*position_n;
	int			file;

	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	file = 1;
	while (file > 0)
	{
		file = read(fd, buf, BUFFER_SIZE);
		if (file >= 0)
			buf[file] = '\0';
		else
			return (-1);
		box = ft_strjoin(box, buf);
		position_n = ft_strchr(box, '\n');
		if (position_n)
			break ;
	}
	return (save_line(line, &box));
}

// int	main(void) {
//     int		fd;
//     char    *line;
    
//     fd = open("/Users/jmacmill/Desktop/42/get_next_line/sample.txt", O_RDONLY);
//     if (fd == -1)
//     {
//         printf("open() unable to open the file");
//         return (1);
//     }
//     while ((get_next_line(fd, &line)))
// 	{
//         printf("Result # : %s\n", line);
// 		free(line);
// 	}
// 	free(line);
//     if (close(fd) == -1)
//     {
//         printf("close() error");
//         return (1);
//     }
//     return (0);
// }
