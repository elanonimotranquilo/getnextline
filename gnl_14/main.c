/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas <asalas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:00:32 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/14 04:21:15 by asalas           ###   ########.fr       */
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
	int		i;

	i = 1;
	(void)argc;
	fd = open (argv[1], O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line (fd);
		printf("------------------------------------------------------------------%s", line);
		i++;
	}
	fd = close(fd);
	return (0);
}
