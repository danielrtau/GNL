/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:51:39 by danielro          #+#    #+#             */
/*   Updated: 2022/10/04 19:58:00 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	int	n;

	if (!s)
		return (0);
	n = 0;
	while (s[n])
		n++;
	return (n);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	a;
	unsigned int	b;
	unsigned int	c;

	a = ft_strlen(src);
	b = ft_strlen(dst);
	c = 0;
	if (dstsize > b)
	{
		while (src[c] && c < (dstsize - b - 1))
		{
			dst[b + c] = src[c];
			c++;
		}
		dst[b + c] = '\0';
		return (a + b);
	}
	return (a + dstsize);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int				a;
	unsigned int	b;

	a = ft_strlen(src);
	b = 0;
	if (dstsize != 0)
	{
		while (src[b] && b < (dstsize - 1))
		{
			dst[b] = src[b];
			b++;
		}
		dst[b] = '\0';
	}
	return (a);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		a;
	int		b;
	char	*c;

	a = ft_strlen(s1);
	b = ft_strlen(s2);
	c = malloc((a + b + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	if (s1)
	{
		ft_strlcpy(c, s1, a + 1);
		ft_strlcat(c, s2, a + b + 1);
	}
	else
		ft_strlcpy(c, s2, b + 1);
	free((void *)s1);
	return (c);
}

int	ft_strchr(const char *s, int c)
{
	int	a;

	a = 0;
	if (!s)
		return (a);
	while (s[a] && s)
	{
		if (s[a] == c)
			return (a + 1);
		a++;
	}
	return (0);
}
