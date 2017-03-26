/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: varnaud <varnaud@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/23 23:41:30 by varnaud           #+#    #+#             */
/*   Updated: 2017/03/23 23:59:58 by varnaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "gnl.h"

static void	list_list(t_fd *list)
{
	while (list)
	{
		printf("%d\n", list->fd);
		list = list->next;
	}
}

int			main(int argc, char **argv)
{
	int		fd;
	int		r;
	char	*line;

	if (argc > 1 && argv[1][0] == '-' && argv[1][1] == 'f' && argv[1][2] == 'd' && argv[1][3] == '\0')
	{
		t_fd	*head = NULL;
		
		add_fd(&head, 1);
		add_fd(&head, 2);
		add_fd(&head, 3);
		add_fd(&head, 4);
		add_fd(&head, 5);
		add_fd(&head, 6);
		add_fd(&head, 7);
		list_list(head);
		printf("-----\n");
		
		get_or_rm_fd(&head, 5, 1);
		get_or_rm_fd(&head, 7, 1);
		get_or_rm_fd(&head, 1, 1);
		add_fd(&head, 8);
		get_or_rm_fd(&head, 6, 1);
		add_fd(&head, 9);
		get_or_rm_fd(&head, 2, 1);
		get_or_rm_fd(&head, 9, 1);
		get_or_rm_fd(&head, 4, 1);
		get_or_rm_fd(&head, 8, 1);
		get_or_rm_fd(&head, 3, 1);
		add_fd(&head, 10);
		list_list(head);
	}
	else if (argc > 1)
	{
		while (*++argv)
		{
			fd = open(*argv, O_RDONLY);
			if (fd == -1)
			{
				perror(*argv);
				continue ;
			}
			printf("%s:\n", *argv);
			while ((r = gnl(fd, &line)) && r != -1)
			{
				printf("%d:|%s|\n", r, line);
				free(line);
			}
			close(fd);
			printf("-----\n");
		}
	}
	else
	{
		printf("stdin:\n");
		while ((r = gnl(0, &line)) && r != -1)
		{
			printf("%d:|%s|\n", r, line);
			free(line);
		}
		printf("-----\n");
	}
}
