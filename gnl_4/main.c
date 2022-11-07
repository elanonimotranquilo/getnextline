/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:00:32 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/07 23:38:13 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(int argc, char **argv)
{
	int		fd;
	char	*line;

	(void)argc;
	fd = open (argv[1], O_RDONLY);
	line = "";
/*	while (line)
	{*/
		line = get_next_line(fd);
		printf("Linea Leida:%s", line);
		line = get_next_line(fd);
		printf("Linea Leida:%s", line);
		line = get_next_line(fd);
		printf("Linea Leida:%s", line);
		line = get_next_line(fd);
		printf("Linea Leida:%s", line);
/*	} */
	fd = close(fd);
	return (0);
}

