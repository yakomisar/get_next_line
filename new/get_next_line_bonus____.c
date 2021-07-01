#include "get_next_line_bonus.h"

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

int	save_line(char **line, char **box, GNL **tmp)
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
		if (*tmp)
			free(*tmp);
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

int	get_line(int fd, char **line, char **box, GNL **tmp)
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
	return (save_line(line, box, tmp));
}

void	remove_list(GNL **head, GNL **lst)
{
	GNL	*after;
	GNL	*current;

	if ((*lst)->next == NULL)
	{
		if ((*head)->next == NULL)
		{
			free(*lst);
			*lst = NULL;
			return ;
		}
		current = *head;
		while (current->next->fd != (*lst)->fd)
		{
			current = current->next;
		}
		free(current->next);
		current->next = NULL;
	}
	else
	{
		current = *head;
		while (current->next->fd != (*lst)->fd)
		{
			current = current->next;
		}
		after = current->next;
		current->next = current->next->next;
		free(after);
		after = NULL;
	}
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
	result = get_line(temp->fd, line, &temp->box, &temp);
	return (result);
}
