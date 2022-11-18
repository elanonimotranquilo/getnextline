/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/18 01:59:26 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*sline;
	char		*read_gnl;
	char		*out_line;
	char		*save_line;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	read_gnl = ft_read_fd(fd);
	out_line = ft_get_line(read_gnl);
	save_line = ft_save_line(read_gnl);
	free(read_gnl);
	read_gnl = ft_strjoin(sline, out_line);
	free(sline);
	free(out_line);
	out_line = ft_strjoin(read_gnl, NULL);
	free(read_gnl);
	sline = ft_strjoin(save_line, NULL);
	free(save_line);
	if ((!out_line) || (*out_line == '\0'))
	{
		free(out_line);
		free(sline);
		out_line = (NULL);
	}
	return (out_line);
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
		buff = NULL;
		return (NULL);
	}
	buff[n_read] = '\0';
	return (buff);
}

char	*ft_read_fd(int fd)
{
	char	*buff;
	char	*store_pre;
	char	*store_post;

	store_pre = NULL;
	buff = ft_read_buffer(fd);
	while (buff)
	{
		store_post = ft_strjoin (store_pre, buff);
		free(store_pre);
		store_pre = ft_strjoin (store_post, NULL);
		free(store_post);
		if (ft_strchr(store_pre, '\n'))
		{
			free(buff);
			return (store_pre);
		}
		free(buff);
		buff = ft_read_buffer(fd);
	}
	free(buff);
	return (store_pre);
}

char	*ft_get_line(const char	*str)
{
	int		l1;
	int		l2;
	char	*eol;
	char	*get_line;

	if (!str)
		return (NULL);
	eol = ft_strchr(str, '\n');
	if (eol)
	{
		l1 = ft_strlen(str);
		l2 = ft_strlen(eol + 1);
		get_line = (char *)malloc ((l1 - l2 + 1) * sizeof(char));
		if (get_line == NULL)
			return (NULL);
		ft_strlcpy(get_line, str, (l1 - l2 + 1));
		return (get_line);
	}
	else
		get_line = ft_strjoin(str, NULL);
	return (get_line);
}

char	*ft_save_line(const char	*str)
{
	char	*eol;
	char	*save_line;

	if (!str)
		return (NULL);
	eol = ft_strchr(str, '\n');
	if (eol)
	{
		save_line = ft_strjoin(eol + 1, NULL);
		return (save_line);
	}
	else
		return (NULL);
}
