#include "get_next_line_bonus.h"
#include <stdio.h>

void	ft_strdel(char **as)
{
	if (!as)
		return ;
	if (*as)
	{
		free(*as);
		*as = NULL;
	}
}

GNL	*ft_lstnew(int fd)
{
	GNL	*head;

	head = (GNL *)malloc(sizeof(GNL));
	if (head == NULL)
		return (NULL);
	head->fd = fd;
	head->box = NULL;
	head->next = NULL;
	return (head);
}

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
		ft_strdel(box);
		result = 0;
	}
	return (result);
}

void	ft_strclr(char *s)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			s[i] = '\0';
			i++;
		}
	}
}

int	get_line(int fd, char **line, char **box)
{
	char		buf[BUFFER_SIZE + 1];
	char		*position_n;
	int			file;

	file = 1;
	while (file > 0)
	{
		file = read(fd, buf, BUFFER_SIZE);
		if (file >= 0)
			buf[file] = '\0';
		else
			return (-1);
		*box = ft_strjoin(*box, buf);
		position_n = ft_strchr(*box, '\n');
		if (position_n)
			break ;
	}
	return (save_line(line, box));
}

int	get_next_line(int fd, char **line)
{
	static GNL	*head;
	GNL			*temp;
	int			result;
	
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || (read(fd, NULL, 0) < 0))
		return (-1);
	if (head == NULL)
		head = ft_lstnew(fd);
	temp = head;
	while (temp->fd != fd)
	{
		if (temp->next == NULL)
			temp = ft_lstnew(fd);
		temp = temp->next;	
	}
	result = get_line(temp->fd, line, &temp->box);
	return (result);
}

int	main(void) {
    int		fd;
    char    *line;
	int		res;
    
    fd = open("/Users/jmacmill/Desktop/42/get_next_line/sample.txt", O_RDONLY);
    if (fd == -1)
    {
        printf("open() unable to open the file");
        return (1);
    }
    while ((res = get_next_line(fd, &line)))
	{
        printf("Result %d : %s\n", res, line);
		free(line);
	}
	printf("Result %d : %s\n", res, line);
	free(line);
	if (close(fd) == -1)
    {
        printf("close() error");
        return (1);
    }
    return (0);
}