/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 22:13:01 by varnaud           #+#    #+#             */
/*   Updated: 2016/11/10 21:21:44 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 1

int				get_next_line(const int fd, char **line);

typedef struct	s_fd
{
	int			fd;
	char		*file;
	char		*line;
	int			isbinary;
	int			isdone;
	int			size;
	int			bytes_read;
}				t_fd;

#endif
