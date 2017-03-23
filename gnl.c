#include <stdlib.h>
#include <unistd.h>
#include "gnl.h"

static void	increment_buf(t_fd *f)
{
	char	*new;
	int		i;

	f->size *= 2;
	new = malloc(sizeof(char) * f->size);
	i = 0;
	while (f->buf[i])
		new[i] = f->buf[i++];
	new[i] = '\0';
	f->i = i;
	free(f->buf);
	f->buf = new;
}

static int	read_fd(t_fd *f, char **line)
{
	int		i;
	int		b;
	
	i = 0;
	if (f->i + BUFF_SIZE > f->size)
		increment_buf(f);
	while (f->buf[i] && f->buf[i] != '\n')
		i++;
	if (f->buf[i] == '\n')
	{
		*line = malloc(sizeof(char) * (i + 1));
		b = 0;
		while (b < i)
			line[b] = f->buf[b++];
		(*line)[b] = '\0';
		b = 0;
		while (buf[i])
			buf[b++] = buf[++i];
		buf[i] = '\0';
		f->i = i;
	}
	else
	{
		if ((b = read(f->fd, &f->buf[i], BUFF_SIZE)) == -1 || !b)
			return (b);
		f->i += b;
		f->buf[b] = '\0';
		return (read_fd(f, line));
	}
	return (1);
}

static t_fd	*add_fd(t_fd **list, int fd)
{
	t_fd	*new;

	new = malloc(sizeof(t_fd));
	new->size = BUFF_SIZE + 1;
	new->buf = malloc(sizeof(char) * new->size);
	new->buf[0] = '\0';
	new->fd = fd;
	new->i = 0;
	new->next = *list;
	*list = new;
}

static t_fd	*get_or_rm_fd(t_fd **l, int fd, int v)
{
	t_fd	*list;
	t_fd	*previous;

	previous = *l;
	list = *l;
	if (v)
		while (list)
		{
			if (list->fd == fd)
				return (list);
			list = list->next;
		}
	else
	{
		while (list)
		{
			if (list->fd == fd)
			{
				previous = list->next;
			}
			previous = list;
			list = list->next;
		}
	}
	return (NULL);
}

int			gnl(const int fd, char **line)
{
	static t_fd	*list;
	t_fd		*current;
	int			r;

	if (fd < 0)
		return (-1);
	if (!(current = get_fd(list, fd)))
		current = add_fd(&list, fd);
	r = read_fd(current, line);
	if (r == 0)
	{
		free(current->buf);
		
	}
	return (r);
}
