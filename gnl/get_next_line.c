/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/05 21:37:03 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*lineread;
}

int	ft_read_fd(int fd)
{
	int		n_read;
	char	*buff;
	char	*eol;
	char	*line;
	char	*lastline;

	n_read = 1;
	buff = (char *)malloc (((BUFFER_SIZE) + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (n_read != 0)
	{
		n_read = read(fd, buff, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(buff)
			return (NULL);
		}
		ft_strlcat(buff, "\0", ((BUFFER_SIZE) + 1));
		eol = ft_strchr(buff, '\n');
		if (eol == NUL)
			line = ft_strjoin(lastline, buff);
		else
		{
			ft_save_line(eol);
			ft_get_line(line);
			free(line);
			return (0);
		}
	}
}

int	ft_get_line(void)
{
	return (0);
}

int	ft_save_line(void)
{
	return (0);
}
