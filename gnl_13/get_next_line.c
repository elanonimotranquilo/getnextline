/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/13 14:20:10 by asalas-s         ###   ########.fr       */
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
	returnl = NULL;
//	printf("gnl FIRST readl:%s\n", readl);
	if (readl == NULL)
	{
		while (line != NULL)
		{
			returnl = ft_get_line(line);
//			printf("gnl readl=NULL-line!=NULL-returnl while:%s\n", returnl);
			line = ft_save_line(line);
//			printf("gnl readl=NULL-line!=NULL-line while:%s\n", line);
			return (returnl);
		}
//		printf("gnl readl=NULL-line=NULL after while\n");
		return (returnl);
	}
	else
	{
//		printf("gnl readl!=NULL-readl:%s\n", readl);
		returnl = ft_get_line(readl);
//		printf("gnl readl!=NULL-returnl:%s\n", returnl);
		line = ft_save_line(readl);
//		printf("gnl readl!=NULL-line:%s\n", line);
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
//		printf("-\nBUFF:%s\n_", buff);
		if (sline == NULL)
			sline = "";
		sline = ft_strjoin (sline, buff);
//		printf("-\nSLINE:%s\n_", sline);
		if (ft_strchr(buff, '\n'))
		{
			free(buff);
			return (sline);
		}
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
	char	*saveline;

	eol = ft_strchr(sline, '\n');
	if (eol != NULL)
		saveline = ft_strjoin(eol + 1, "");
	else
		saveline = NULL;
	return (saveline);
}
