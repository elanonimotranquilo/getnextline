/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/19 20:37:42 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*sline;
	char		*read_aux;
	char		*out_line;
	int			n_read;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	n_read = 1;
	read_aux = ft_read_fd(fd, &n_read, &sline);
	if (n_read == -1)
	{
		free(sline);
		sline = NULL;
		return (NULL);
	}
	out_line = ft_get_line(read_aux);
	free(read_aux);
	if ((out_line) && (*out_line == '\0'))
	{
		free(out_line);
		free(sline);
		out_line = (NULL);
	}
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
		{
			free(buff);
			return (NULL);
		}
		buff[*n_read] = '\0';
		store = ft_strjoin (*sline, buff);
		free(*sline);
		*sline = ft_strjoin (store, NULL);
		free(store);
		if (ft_strchr(*sline, '\n'))
			break ;
	}
	free(buff);
	store = ft_strjoin (*sline, NULL);
	*sline = ft_save_line(store);
	return (store);
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
		if (*(eol +1) != '\0')
			l2 = ft_strlen(eol + 1);
		else
			l2 = 0;
		get_line = (char *)malloc ((l1 - l2 + 1) * sizeof(char));
		if (get_line == NULL)
			return (NULL);
		ft_strlcpy(get_line, str, (l1 - l2 + 1));
		return (get_line);
	}
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
		if (*(eol +1) != '\0')
			save_line = ft_strjoin(eol + 1, NULL);
		else
			save_line = NULL;
		return (save_line);
	}
	else
		return (NULL);
}
