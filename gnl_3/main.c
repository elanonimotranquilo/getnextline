/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novasol <novasol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:43:37 by novasol           #+#    #+#             */
/*   Updated: 2022/11/07 18:27:47 by novasol          ###   ########.fr       */
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
/*	while (line != NULL)
	{ */
		line = get_next_line(fd);
		printf("Linea Leida:%s", line);
		line = get_next_line(fd);
		printf("Linea Leida:%s", line);
		line = get_next_line(fd);
		printf("Linea Leida:%s", line);
		line = get_next_line(fd);
		printf("Linea Leida:%s", line);
/*	}  */
	fd = close(fd);
	return (0);
}
