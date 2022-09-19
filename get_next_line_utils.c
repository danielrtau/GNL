/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:51:39 by danielro          #+#    #+#             */
/*   Updated: 2022/09/16 19:51:42 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_linelen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != 10 && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_linewr(char *src, int len)
{
	char	*txt;
	int		i;

	i = 0;
	txt = malloc((len + 1) * sizeof(char));
	while (len-- > 0)
	{
		txt[i] = src[0];
		src++;
		i++;
	}
	txt[i] = '\0';
	return (txt);
}

char	*ft_line(char *src)
{
	char		*txt;
	static int	end = 0;
	int			start;
	int			i;

	i = 0;
	start = end;
	while (src[end] != 10)
		end++;
	txt = malloc((end - start + 1) * sizeof(char));
	while (start < end)
	{
		txt[i] = src[start];
		start++;
		i++;
	}
	txt[start] = '\0';
	end++;
	return (txt);
}
