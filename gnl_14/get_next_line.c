/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas <asalas@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/14 04:31:45 by asalas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*line;
	char		*returnl;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	returnl = ft_read_fd(fd, line);
	if (returnl)
	{
		line = ft_save_line(returnl);
		returnl = ft_get_line(returnl);
		printf("GNL RETURNL NOT NULL returnl:%s\n", returnl);
		printf("GNL RETURNL NOT NULL line:%s\n", line);
		return (returnl);
	}
	else
	{
		printf("GNL ANTES DEL WHILE\n");
		while (line)
		{
			printf("GNL DENTRO DEL WHILE\n");
			returnl = ft_get_line(line);
			line = ft_save_line(line);
			printf("GNL RETURNL NULL WHILE LINE NOT NULL returnl:%s\n", returnl);
			printf("GNL RETURNL NULL WHILE LINE NOT NULL line:%s\n", line);
			return (returnl);
		}
		printf("GNL RETURNL NULL OUT WHILE\n");
		return (returnl);
	}
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

char	*ft_read_fd(int fd, char *sline)
{
	char	*buff;

	buff = ft_read_buffer(fd);
	while (buff)
	{
		if (sline == NULL)
			sline = ft_strjoin ("", buff);
		else
			sline = ft_strjoin (sline, buff);
		if (ft_strchr(buff, '\n'))
			return (sline);
		buff = ft_read_buffer(fd);
	}
	if (ft_strlen(sline) != 0)
		return (sline);
	else
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

	eol = ft_strchr(sline, '\n');
	if (eol != NULL)
		sline = ft_strjoin(eol + 1, "");
	else
		sline = NULL;
	return (sline);
}
