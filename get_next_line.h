#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

// Additional functions
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strnew(size_t size);
char    *ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	ft_strclr(char *s);
int     get_next_line(int fd, char **line);
char    *ft_strcpy(char *dest, char *src);
void    *ft_calloc(int a, int b);

#endif
