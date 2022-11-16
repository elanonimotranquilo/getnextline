/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novasol <novasol@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 23:30:04 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/16 13:54:54 by novasol          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*strjoin;
	int		l1;
	int		l2;

	if ((!s1) && (!s2))
		return (NULL);
	if (!s1)
		l1 = 0;
	else
		l1 = ft_strlen(s1);
	if (!s2)
		l2 = 0;
	else
		l2 = ft_strlen(s2);
	strjoin = (char *)malloc ((l1 + l2 + 1) * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	if (!s1)
		ft_strlcpy(strjoin, "", l1 + 1);
	else
		ft_strlcpy(strjoin, s1, l1 + 1);
	if (!s2)
		ft_strlcat(strjoin, "", l1 + l2 + 1);
	else
		ft_strlcat(strjoin, s2, l1 + l2 + 1);
	return (strjoin);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	dst_l;
	unsigned int	src_l;

	dst_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	i = 0;
	j = 0;
	if ((dstsize == 0) || (dstsize <= dst_l))
		return (src_l + dstsize);
	while (dst[i] != '\0')
		i++;
	while ((src[j] != '\0') && (j < dstsize - dst_l - 1))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (dst_l + src_l);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	l;

	l = ft_strlen(src);
	i = 0;
	if (dstsize > 0)
	{
		while ((src[i] != '\0') && (i < dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (l);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	else
		return (NULL);
}
