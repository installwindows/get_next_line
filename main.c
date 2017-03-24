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
#include <stdlib.h>
#include "gnl.h"

int			main(int argc, char **argv)
{
	int		fd;
	int		r;
	char	*line;

	if (argc > 1)
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
