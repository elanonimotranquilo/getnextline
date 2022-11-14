/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/15 00:52:28 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*sline;
	char		*returnl;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	returnl = ft_read_fd(fd, sline);
	if (returnl)
	{
		sline = ft_save_line(returnl);
		returnl = ft_get_line(returnl);
		return (returnl);
	}
	while (sline)
	{
		returnl = ft_get_line(sline);
		sline = ft_save_line(sline);
		return (returnl);
	}
	return (returnl);
}

char	*ft_read_buffer(int fd)
{
	int		n_read;
	char	*buff;

	buff = (char *)malloc (((BUFFER_SIZE) + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	n_read = read(fd, buff, BUFFER_SIZE);
	if (n_read <= 0)
	{
		free(buff);
		return (NULL);
	}
	buff[n_read] = '\0';
	return (buff);
}

char	*ft_read_fd(int fd)
{
	char	*buff;
	char	*prev_buff;
	char	*read_l;

	prev_buff = NULL;
	buff = ft_read_buffer(fd);
	while (buff)
	{
		if (prev_buff == NULL)
			read_l = ft_strjoin (buff, "");
		else
			read_l = ft_strjoin (prev_buff, buff);
		if (ft_strchr(buff, '\n'))
		{
			free(buff);
			return (sline);
		}
		buff = ft_read_buffer(fd);
	}
	if (sline)
		return (sline);
	return (NULL);
}

char	*ft_get_line(char	*sline)
{
	int		l1;
	int		l2;
	char	*eol;
	char	*getline;

	getline = NULL;
	eol = ft_strchr(sline, '\n');
	l1 = ft_strlen(sline);
	if (eol)
		l2 = ft_strlen(eol + 1);
	else
		l2 = 0;
	ft_strlcpy(getline, sline, (l1 - l2 + 1));
	return (getline);
}

char	*ft_save_line(char	*sline)
{
	char	*eol;
	char	*rsl;

	rsl = NULL;
	eol = ft_strchr(sline, '\n');
	if (eol)
		ft_strlcpy(rsl, eol + 1, ft_strlen(eol + 1));
	else
		rsl = NULL;
	return (rsl);
}
