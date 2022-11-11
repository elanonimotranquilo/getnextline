/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/11 02:42:35 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*readl;
	char		*returnl;
	int			l;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	readl = ft_read_fd(fd);
	if (readl == NULL)
		return (NULL);
	l = ft_strlen(line);
	if (l != 0)
	{
		line = ft_strjoin(line, readl);
		returnl = ft_get_line(line);
	}
	else
	{
		line = ft_strjoin("", readl);
		returnl = ft_get_line(readl);
	}
	l = ft_strlen(returnl);
	if (l == 0)
	{
		free(returnl);
		return (NULL);
	}
	else
		return (returnl);
}

char	*ft_read_fd(int fd)
{
	int		n_read;
	char	*buff;
	char	*readline;

	buff = (char *)malloc (((BUFFER_SIZE) + 1) * sizeof(char));
	if (buff == NULL)
		return (NULL);
	n_read = read(fd, buff, BUFFER_SIZE);
	buff[n_read] = '\0';
	while (n_read != 0)
	{
		if (n_read == -1)
		{
			free(buff);
			return (NULL);
		}
		readline = ft_strjoin (readline, buff);
		if (ft_strchr(buff, '\n'))
		{
			free(buff);
			return (readline);
		}
		n_read = read(fd, buff, BUFFER_SIZE);
	}
	return (NULL);
}

char	*ft_get_line(char	*line)
{
	int		l1;
	int		l2;
	char	*eol;
	char	*getline;

	eol = ft_strchr(line, '\n');
	l1 = ft_strlen(line);
//	printf("\nl1:%i\n", l1);
	if (eol)
	{	
		l2 = ft_strlen(eol + 1);
//		printf("\nl2:%i\n", l2);
	}
	else
	{
		l2 = 0;
//		printf("\nl2:%i\n", l2);
	}
	getline = (char *)malloc ((l1 - l2 + 1) * sizeof(char));
	if (getline == NULL)
		return (NULL);
	ft_strlcpy(getline, line, (l1 - l2 + 1));
	return (getline);
}

char	*ft_save_line(char	*line)
{
	char	*eol;
	char	*saveline;

	eol = ft_strchr(line, '\n');
	saveline = ft_strjoin(eol + 1, "");
	return (saveline);
}
