/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/16 01:46:32 by asalas-s         ###   ########.fr       */
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
//	printf("\nread_gnl:%s\n", read_gnl);
	if (read_gnl)
	{
		out_line = ft_get_line(read_gnl);
//		printf("\nout_line:%s\n", out_line);
		save_line = ft_save_line(read_gnl);
//		printf("\nsave_line:%s\n", save_line);
		free(read_gnl);
//		printf("\nFREE_READ_GNL\n");
		if (sline)
		{
			sline = ft_strjoin(sline, out_line);
			free(out_line);
			out_line = ft_strjoin(sline, NULL);
			free(sline);
		}
		else
			sline = ft_strjoin(save_line, NULL);
		free(save_line);
//		printf("\nFREE_SAVE_LINE\n");
//		printf("\nsline:%s\n", sline);
//		printf("\nOUT_LINE\n");
		return (out_line);
	}
	while (sline)
	{
		out_line = ft_get_line(sline);
//		printf("\nout_line:%s\n", out_line);
		save_line = ft_save_line(sline);
//		printf("\nsave_line:%s\n", save_line);
		free(sline);
//		printf("\nFREE_SLINE\n");
		sline = ft_strjoin(save_line, "");
//		printf("\nsline:%s\n", sline);
		free(save_line);
//		printf("\nFREE_SAVE_LINE\n");
//		printf("\nOUT_LINE\n");
		return (out_line);
	}
//	printf("\nNULL\n");
	return (NULL);
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
	char	*store_pre;
	char	*store_post;

	store_pre = NULL;
	buff = ft_read_buffer(fd);
	while (buff)
	{
		if (store_pre == NULL)
			store_post = ft_strjoin (buff, "");
		else
			store_post = ft_strjoin (store_pre, buff);
		free(store_pre);
		store_pre = ft_strjoin (store_post, "");
		free(store_post);
		if (ft_strchr(buff, '\n'))
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

char	*ft_get_line(char	*str)
{
	int		l1;
	int		l2;
	char	*eol;
	char	*get_line;

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
		get_line = NULL;
	return (get_line);
}

char	*ft_save_line(char	*str)
{
	char	*eol;
	char	*save_line;

	eol = ft_strchr(str, '\n');
	if (eol)
		save_line = ft_strjoin(eol + 1, "");
	else
		save_line = NULL;
	return (save_line);
}
