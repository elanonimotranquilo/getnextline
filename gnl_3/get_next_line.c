/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novasol <novasol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/07 18:45:03 by novasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*eol;
	char		*returnl;

	line = ft_read_fd(fd);
	eol = ft_strchr(line, '\n');
	if (eol)
	{
		returnl = ft_get_line(line, eol);
		line = ft_save_line(eol);
	}
	else
		returnl = line;
	return (returnl);
}

char	*ft_read_fd(int fd)
{
	int		n_read;
	char	*buff;
	char	*line;

	n_read = 1;
	line = "";
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
		line = ft_strjoin(line, buff);
		if (ft_strchr(buff, '\n'))
		{
			free(buff);
			return (line);
		}
	}
	free(buff);
	return (NULL);
}

char	*ft_get_line(char	*line, char	*eol)
{
	int		l1;
	int		l2;
	char	*returnline;

 	l1 = ft_strlen(line);
	l2 = ft_strlen(eol + 1);
	returnline = (char *)malloc ((l1 - l2 + 1) * sizeof(char));
	if (returnline == NULL)
		return (NULL);
	ft_strlcpy(returnline, line, (l1 - l2 +1));
	return (returnline);
}

char	*ft_save_line(char	*eol)
{
	return (ft_strjoin(eol + 1, ""));
}
