/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:15:21 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/27 18:25:09 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_free_clean(char	**str)
{
	if (*str != NULL)
	{
		free(*str);
		*str = NULL;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*sline[1024];
	char		*read_aux;
	char		*out_line;
	int			n_read;

	n_read = 1;
	if ((fd < 0) || (fd > 1024) || (BUFFER_SIZE <= 0))
		return (NULL);
	read_aux = ft_read_fd(fd, &n_read, &sline[fd]);
	if (n_read == -1)
		return (ft_free_clean(&sline[fd]), NULL);
	out_line = ft_get_line(read_aux);
	ft_free_clean(&read_aux);
	if (!out_line)
		ft_free_clean(&sline[fd]);
	return (out_line);
}

char	*ft_read_fd(int fd, int *n_read, char **sline)
{
	char	*buff;
	char	*store;

	buff = (char *)malloc (((BUFFER_SIZE) + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	while (*n_read > 0)
	{
		*n_read = read(fd, buff, BUFFER_SIZE);
		if (*n_read == -1)
			return (ft_free_clean(&buff), NULL);
		buff[*n_read] = '\0';
		store = ft_strjoin(*sline, buff);
		ft_free_clean(sline);
		if (ft_strchr(store) || (*n_read == 0))
			break ;
		*sline = store;
	}
	*sline = ft_save_line(store);
	return (ft_free_clean(&buff), store);
}

char	*ft_get_line(char	*str)
{
	char	*eol;
	char	*get_line;

	if (!str)
		return (NULL);
	if (((str) && (*str == '\0')))
		return (NULL);
	eol = ft_strchr(str);
	if (eol)
		*(eol + 1) = '\0';
	get_line = ft_strjoin(str, NULL);
	return (get_line);
}

char	*ft_save_line(const char	*str)
{
	char	*eol;
	char	*save_line;

	if (!str)
		return (NULL);
	if ((str) && (*str == '\0'))
		return (NULL);
	eol = ft_strchr(str);
	if (eol)
	{
		save_line = ft_strjoin(eol + 1, NULL);
		return (save_line);
	}
	else
		return (NULL);
}
