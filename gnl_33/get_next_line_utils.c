/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalas-s <asalas-s@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:14:57 by asalas-s          #+#    #+#             */
/*   Updated: 2022/11/21 23:12:30 by asalas-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(const char *s, const char *t)
{
	char	*strjoin;
	int		strjoin_len;

	if (((!s) && (!t)) || ((!s) && (*t == '\0')) || ((!t) && (*s == '\0')))
	{
		return (NULL);
	}
	if ((!s || *s == '\0') && (t || *t != '\0'))
	{
		strjoin_len = ft_strlen(t);
	}
	if ((!t || *t == '\0') && (s || *s != '\0'))
	{
		strjoin_len = ft_strlen(s);
	}
	if ((s && t) && (*s != '\0') && (*t != '\0'))
	{
		strjoin_len = ft_strlen(s) + ft_strlen(t);
	}
	strjoin = (char *)malloc ((strjoin_len + 1) * sizeof(char));
	if (strjoin == NULL)
		return (NULL);
	if ((!s || *s == '\0') && (t || *t != '\0'))
		ft_strlcpy(strjoin, t, strjoin_len + 1);
	if ((!t || *t == '\0') && (s || *s != '\0'))
		ft_strlcpy(strjoin, s, strjoin_len + 1);
	if ((s && t) && (*s != '\0') && (*t != '\0'))
	{
		ft_strlcpy(strjoin, s, strjoin_len + 1);
		ft_strlcat(strjoin, t, strjoin_len + 1);
	}
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

	if (!s)
		return (NULL);
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
