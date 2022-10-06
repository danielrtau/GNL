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

int	ft_linelen(char *str, int sch)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != sch)
		i++;
	return (i);
}

char	*ft_linenl(char *src1, char *src2)
{
	char	*aux;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlennl(src1, src2);
	aux = malloc(sizeof(char) * (len + 2));
	if (src1 != NULL)
	{
		while (src1[i] != 0)
		{
			aux[i] = src1[i];
			i++;
		}
	}
	while (src2[j] != 10)
	{
		aux[i] = src2[j];
		i++;
		j++;
	}
	aux[i++] = 10;
	aux[i] = 0;
	return (aux);
}

int	ft_strlennl(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str1 != NULL)
	{
		while (str1[i])
			i++;
	}
	while (str2[j] != 10)
	{
		i++;
		j++;
	}
	return (i);
}

int	ft_strlen(char *str1, char *str2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str1 != NULL)
	{
		while (str1[i])
			i++;
	}
	while (str2[j])
	{
		i++;
		j++;
	}
	return (i);
}

char	*ft_liner(char *src)
{
	char	*aux;
	int		i;
	int		j;
	int		len;

	i = 0;
	while (src[i] != 10)
		i++;
	len = 0;
	j = i + 1;
	while (src[i] != 0)
	{
		len++;
		i++;
	}
	aux = malloc(sizeof(char) * (len + 1));
	i = 0;
//	printf("--i: %d--", i);
	while (src[j])
	{
		aux[i] = src[j];
		i++;
		j++;
	}
	aux[i] = 0;
	return (aux);
}

char	*ft_line(char *src1, char *src2)
{
	char	*aux;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_strlen(src1, src2);
	aux = malloc(sizeof(char) * (len + 1));
	if (src1 != NULL)
	{
		while (src1[i] != 0)
		{
			aux[i] = src1[i];
			i++;
		}
	}
	while (src2[j])
	{
		aux[i] = src2[j];
		i++;
		j++;
	}
	aux[i] = 0;
	return (aux);
}

char	*ft_linewr(char *src1, char *src2)
{
	char	*aux;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = i;
	len = ft_linelen(src1, 0);
	len += ft_linelen(src2, 10);
	aux = malloc(sizeof(char) * (len + 2));
	while (src1 && src1[i])
	{
		aux[i] = src1[i];
		i++;
	}
	while (src2[j] != 10)
	{
		aux[i] = src2[j];
		i++;
		j++;
	}
	aux[i++] = 10;
	aux[i] = 0;
	return (aux);
}

char	*ft_totalln(char *str)
{
	char	*aux;
	int		i;
	int		len;

	i = 0;
	len = ft_linelen(str, 10);
	aux = malloc(sizeof(char) * (len + 2));
	while (str[i] != 10)
	{
		aux[i] = str[i];
		i++;
	}
	aux[i++] = 10;
	aux[i] = 0;
	return (aux);
}

char	*ft_nextln(char *str)
{
	int		i;
	char	*txt;

	i = 0;
	while (str[i] != '\0' && str[i] != 10)
		i++;
	txt = str + i;
	return (txt);
}

int	ft_schrnl(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != 0)
	{
		if(str[i] == 10)
			return(1);
		str++;
	}
	return (0);
}
