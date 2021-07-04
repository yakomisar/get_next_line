#include "get_next_line_bonus.h"

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
	static char	*box[1024];
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
		box[fd] = ft_strjoin(box[fd], buf);
		position_n = ft_strchr(box[fd], '\n');
		if (position_n)
			break ;
	}
	return (save_line(line, &box[fd]));
}
