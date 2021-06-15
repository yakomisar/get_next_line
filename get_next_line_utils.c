#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (len > 0)
	{
		((char *)b)[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (b);
}

void	ft_strclr(char *s)
{
	if (s == NULL)
		return ;
	ft_memset(s, 0, ft_strlen(s));
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

char	*ft_strdup(const char *s1)
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

char	*ft_strnew(size_t size)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	char	*res;
	size_t	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	if ((str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	res = str;
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = '\0';
	return (res);
}