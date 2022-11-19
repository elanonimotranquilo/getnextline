/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas <asalas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:00:32 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/19 13:18:04 by asalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int			fd;
	char		*gnl;
	int			n_read;
	static char	*sline;

	(void)argc;
	fd = open (argv[1], O_RDONLY);
	gnl = "";
	n_read = 1;
	gnl = ft_read_fd(fd, &n_read, &sline);
	printf("GNL:%s\n", gnl);
	gnl = ft_read_fd(fd, &n_read, &sline);
	printf("GNL:%s\n", gnl);
	fd = close(fd);
	return (0);
}
