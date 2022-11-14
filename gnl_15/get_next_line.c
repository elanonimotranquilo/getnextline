/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novasol <novasol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:28:03 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/14 18:47:31 by novasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*sline;
	char		*returnl;

	if ((fd < 0) || (BUFFER_SIZE <= 0))
		return (NULL);
	returnl = ft_read_fd(fd, sline);
	printf("\nGNL RETURNL INICIO:%s\n", returnl);
	printf("\nGNL SLINE INICIO:%s\n", sline);
	if (returnl)
	{
		sline = ft_save_line(returnl);
		returnl = ft_get_line(returnl);
		printf("\nGNL RETURNL NOT NULL RETURNL:%s\n", returnl);
		printf("\nGNL RETURNL NOT NULL SLINE:%s\n", sline);
		return (returnl);
	}
	else
	{
		while (sline)
		{
			returnl = ft_get_line(sline);
			sline = ft_save_line(sline);
			printf("\nGNL RETURNL NULL RETURNL:%s\n", returnl);
			printf("\nGNL RETURNL NULL SLINE:%s\n", sline);
			return (returnl);
		}
		printf("\nGNL RETURNL NULL SLINE NULL RETURNL:%s\n", returnl);
		printf("\nGNL RETURNL NULL SLINE NULL SLINE:%s\n", sline);
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
	if (n_read == -1)
	{
		free(buff);
		return (NULL);
	}
	if (n_read >= 0)
	{
		buff[n_read] = '\0';
	}	
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
		{
			free(buff);
			return (sline);
		}
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
	char	*rsl;

	eol = ft_strchr(sline, '\n');
	if (eol)
		rsl = ft_strjoin(eol + 1, "");
	else
		rsl = NULL;
	return (rsl);
}
