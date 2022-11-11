/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novasol <novasol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/11 18:09:17 by novasol          ###   ########.fr       */
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
//	if (line == NULL)
//		line = ft_strjoin("", readl);
//	else
//		line = ft_strjoin(line, readl);
	returnl = ft_get_line(readl);
	line = ft_save_line(readl);
	printf ("\nReadl:%s|Returnl:%s|Line:%s|", readl, returnl, line);
	return (returnl);
}

char	*ft_read_fd(int fd, char *line)
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
		if (line == NULL)
			line = "";
		line = ft_strjoin (line, buff);
		if (ft_strchr(buff, '\n'))
		{
			free(buff);
			return (line);
		}
	}
	return ("");
}

char	*ft_get_line(char	*line)
{
	int		l1;
	int		l2;
	char	*eol;
	char	*getline;

	eol = ft_strchr(line, '\n');
	l1 = ft_strlen(line);
	if (eol)
		l2 = ft_strlen(eol + 1);
	else
		l2 = 0;
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
