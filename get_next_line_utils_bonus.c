#include "get_next_line_bonus.h"
//#include <stdio.h>

size_t	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
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

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strdup(char *s1)
{
	char	*new;
	size_t	counter;
	size_t	len;

	len = ft_strlen(s1) + 1;
	counter = 0;
	new = (char *)malloc(sizeof(char) * len);
	if (new == NULL)
		return (NULL);
	while (s1[counter] != '\0')
	{
		new[counter] = s1[counter];
		counter++;
	}
	new[counter] = '\0';
	return (new);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	size_t	length;
	char	*res;

	i = 0;
	j = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (length + 1));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	if (s2)
	{
		while (s2[j])
			res[i++] = s2[j++];
	}
	res[i] = '\0';
	if (s1)
	    free(s1);
	return (res);
}

char	*ft_strcpy(char *dest, char *src)
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