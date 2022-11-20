/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:16:07 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/20 18:48:44 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int			fd;
	char		*rfd;
	int			n_read;
	static char	*sline;

	(void)argc;
	fd = open (argv[1], O_RDONLY);
	rfd = "";
	n_read = 1;
	rfd = ft_read_fd(fd, &n_read, &sline);
	printf("rfd:%s\n", rfd);
	rfd = ft_read_fd(fd, &n_read, &sline);
	printf("rfd:%s\n", rfd);
	rfd = ft_read_fd(fd, &n_read, &sline);
	printf("rfd:%s\n", rfd);
	rfd = ft_read_fd(fd, &n_read, &sline);
	printf("rfd:%s\n", rfd);
	rfd = ft_read_fd(fd, &n_read, &sline);
	printf("rfd:%s\n", rfd);
	rfd = ft_read_fd(fd, &n_read, &sline);
	printf("rfd:%s\n", rfd);
	fd = close(fd);
	return (0);
}
