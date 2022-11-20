/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:15:55 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/20 20:07:11 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*gnl;

	(void)argc;
	fd = open (argv[1], O_RDONLY);
	gnl = "";
	while (gnl)
	{
		gnl = get_next_line(fd);
		printf("%s", gnl);
	}
	fd = close(fd);
	return (0);
}
