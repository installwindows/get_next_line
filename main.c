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

int			main(int argc, char **argv)
{
	int		fd;
	int		r;
	char	*line;

	if (argc == 1)
	{
		int fd1 = open("file1", O_RDONLY);
		int fd2 = open("file2", O_RDONLY);
		int fd3 = open("file3", O_RDONLY);
		int fd4 = open("file4", O_RDONLY);

		r = gnl(fd1, &line);
		printf("fd1: %d:|%s|\n", r, line);
		if (r) free(line);
		r = gnl(fd2, &line);
		printf("fd2: %d:|%s|\n", r, line);
		if (r) free(line);
		r = gnl(fd3, &line);
		printf("fd3: %d:|%s|\n", r, line);
		if (r) free(line);
		r = gnl(fd4, &line);
		printf("fd4: %d:|%s|\n", r, line);
		if (r) free(line);
		r = gnl(fd3, &line);
		printf("fd3: %d:|%s|\n", r, line);
		if (r) free(line);
		r = gnl(fd2, &line);
		printf("fd2: %d:|%s|\n", r, line);
		if (r) free(line);
		r = gnl(fd1, &line);
		printf("fd1: %d:|%s|\n", r, line);
		if (r) free(line);


		r = gnl(fd4, &line);
		printf("fd4: %d:|%s|\n", r, line);
		if (r) free(line);

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
