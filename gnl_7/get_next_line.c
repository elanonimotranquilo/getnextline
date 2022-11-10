/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas <asalas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/10 03:12:25 by asalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_fd(int fd, char *readline)
{
	int		n_read;
	char	*buff;

	n_read = -1;
	buff = (char *)malloc (((BUFFER_SIZE) + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (n_read != 0)
	{
		n_read = read(fd, buff, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n_read + 1] = '\0';
		readline = ft_strjoin (readline, buff);
		if (ft_strchr(readline, '\n'))
		{
			free(buff);
			return (readline);
		}
	}
	return (NULL);
}
