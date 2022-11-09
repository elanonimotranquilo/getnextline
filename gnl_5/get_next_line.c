/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/09 03:37:06 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*eol;
	char		*readl;

	readl = ft_read_fd(fd);
	if (readl)
	{
		if (line)
			readl = ft_strjoin(line, readl);
		eol = ft_strchr(readl, '\n');
		if (eol)
		{
			readl = ft_get_line(readl, eol);
			line = ft_save_line(eol);
		}
	}
	else
	{
		eol = ft_strchr(line, '\n');
		if (eol)
		{
			readl = ft_get_line(line, eol);
			line = ft_save_line(eol);
		}
	}
	return (readl);
}

char	*ft_read_fd(int fd)
{
	int		n_read;
	char	*buff;
	char	*actual_line;
	char	*prev_line;

	if (fd < 0)
		return (NULL);
	n_read = 1;
	actual_line = "";
	prev_line = "";
	buff = (char *)malloc (((BUFFER_SIZE) + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (n_read != 0)
	{
		if (ft_strchr(actual_line, '\n'))
			return (actual_line);
		n_read = read(fd, buff, BUFFER_SIZE);
		if (n_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n_read + 1] = '\0';
		actual_line = ft_strjoin(prev_line, buff);
		if (ft_strchr(buff, '\n'))
		{
			free(buff);
			return (actual_line);
		}
		else
			prev_line = actual_line;
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
	ft_strlcpy(returnline, line, (l1 - l2 + 1));
	return (returnline);
}

char	*ft_save_line(char	*eol)
{	
	char	*saveline;

	saveline = ft_strjoin(eol + 1, "");
	return (saveline);
}
