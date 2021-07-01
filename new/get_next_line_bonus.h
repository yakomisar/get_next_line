#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

//# define BUFFER_SIZE 1

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

typedef struct s_get_next_line
{
    int						fd;
    char					*box;   
    struct s_get_next_line	*next;
}							GNL;

// Additional functions
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s1);
char    *ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(char *str);
int     get_next_line(int fd, char **line);
char    *ft_strcpy(char *dest, char *src);
GNL     *ft_lstnew(int fd);

#endif
