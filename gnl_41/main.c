/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novasol <novasol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:00:32 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/24 18:14:36 by novasol          ###   ########.fr       */
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
//	int			n_read;
//	static char	*sline;

	(void)argc;
	fd = open (argv[1], O_RDONLY);
	gnl = "";
	while (gnl)
	{
		gnl = get_next_line (fd);
//		gnl = ft_read_fd(fd, &n_read, &sline);
		printf("%s", gnl);
	}
	fd = close(fd);
	return (0);
}
