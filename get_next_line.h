#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUF_SIZE 5;

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

#endif
