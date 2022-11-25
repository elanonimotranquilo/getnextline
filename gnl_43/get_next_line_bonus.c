/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:15:21 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/25 01:09:02 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

	if (ft_strchr(*sline))
	{
		store = ft_get_line(*sline);
		buff = ft_save_line(*sline);
		ft_free_clean(sline);
		return (*sline = buff, store);
	}
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
		if (ft_strchr(buff) || (*n_read == 0))
			break ;
		*sline = store;
	}
	*sline = ft_save_line(buff);
	return (ft_free_clean(&buff), store);
}

char	*ft_get_line(const char	*str)
{
	int		l1;
	int		l2;
	char	*eol;
	char	*get_line;

	if (!str)
		return (NULL);
	if (((str) && (*str == '\0')))
		return (NULL);
	eol = ft_strchr(str);
	if (eol)
	{
		l1 = ft_strlen(str);
		if (*(eol + 1) != '\0')
			l2 = ft_strlen(eol + 1);
		else
			l2 = 0;
		get_line = (char *)malloc ((l1 - l2 + 1) * sizeof(char));
		if (get_line == NULL)
			return (NULL);
		*get_line = '\0';
		ft_strlcpy(get_line, str, (l1 - l2 + 1));
		return (get_line);
	}
	return (get_line = ft_strjoin(str, NULL), get_line);
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
		if (*(eol +1) != '\0')
			save_line = ft_strjoin(eol + 1, NULL);
		else
			save_line = NULL;
		return (save_line);
	}
	else
		return (NULL);
}
