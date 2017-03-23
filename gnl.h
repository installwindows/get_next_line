#ifndef GNL_H
# define GNL_H
# define BUFF_SIZE 1024

typedef struct	s_fd
{
	int				fd;
	int				i;
	int				size;
	char			*buf;
	struct s_list	*next;
}				t_fd;

#endif
