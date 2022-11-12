/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/12 01:16:42 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*readl;
	char		*returnl;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	readl = ft_read_fd(fd, line);
	if (readl == NULL)
		return (NULL);
	else
	{
//	if (line == NULL)
//		line = ft_strjoin("", readl);
//	else
//		line = ft_strjoin(line, readl);
		returnl = ft_get_line(readl);
		line = ft_save_line(readl);
		return (returnl);
	}
}

char	*ft_read_fd(int fd, char *sline)
{
	int		n_read;
	char	*buff;

	n_read = 1;
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
		buff[n_read] = '\0';
		if (sline == NULL)
			sline = "";
		sline = ft_strjoin (sline, buff);
		if (ft_strchr(buff, '\n'))
		{
			free(buff);
			return (sline);
		}
	}
	return (NULL);
}

char	*ft_get_line(char	*sline)
{
	int		l1;
	int		l2;
	char	*eol;
	char	*getline;

	eol = ft_strchr(sline, '\n');
	l1 = ft_strlen(sline);
	if (eol)
		l2 = ft_strlen(eol + 1);
	else
		l2 = 0;
	getline = (char *)malloc ((l1 - l2 + 1) * sizeof(char));
	if (getline == NULL)
		return (NULL);
	ft_strlcpy(getline, sline, (l1 - l2 + 1));
	return (getline);
}

char	*ft_save_line(char	*sline)
{
	char	*eol;
	char	*saveline;

	eol = ft_strchr(sline, '\n');
	saveline = ft_strjoin(eol + 1, "");
	return (saveline);
}
