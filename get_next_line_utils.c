#include "get_next_line.h"

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

// char    *ft_strjoin(char *s1, char *s2)
// {
//     int i;
//     int j;
//     char *str;
//     i = 0;
//     j = 0;
//     str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
//     if (str == NULL)
//         return (NULL);
//     while (s1[i])
//         str[j++] = s1[i++];
//     i = 0;
//     while (s2[i])
//         str[j++] = s2[i++];
//     str[j] = '\0';
//     return (str);
// }

char	*ft_strjoin(char *s1, char *s2)//(char *saved_buf, char *buf)
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
	printf("Address of box in strjoin: %p\n", &s1);
	printf("Address of box in strjoin: %p\n", s1);
	printf("Value of box: %s\n\n", s1);
	if (s1)
	    free(s1);
	printf("Address of box after free: %p\n", &s1);
	printf("Address of box after free: %p\n", s1);
	printf("Value of box: %s\n\n", s1);
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