/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 20:00:32 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/11 22:32:53 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int	main(void)
{
	char	*line;
	char	*getline;
	char	*saveline;

	line = "nnnn\n\n1\n";
	getline = ft_get_line(line);
	printf("Get:%s", getline);
	saveline = ft_save_line(line);
	printf("Save:%s", saveline);
	return (0);
}
