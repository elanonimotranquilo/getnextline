/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/05 20:18:21 by asalas-s         ###   ########.fr       */
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
	char	*lineread;
	char	*lastread;

	n_read = 1;
	buff = (char *)malloc (((BUFFER_SIZE) + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (n_read != 0)
	{
		n_read = read(fd, buff, BUFFER_SIZE);
		if (n_read == -1)
			return (NULL);
		ft_strlcat(buff, "\0", ((BUFFER_SIZE) + 1));
		eol = ft_strchr(buff, '\n');
		if (eol == NULL)
			lineread = ft_strjoin(lastread, buff);
		else
			ft_strlcat(lineread, buff, (BUFFER_SIZE) - ft_strlen(eol));
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
