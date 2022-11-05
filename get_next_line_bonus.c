/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 14:52:01 by danielro          #+#    #+#             */
/*   Updated: 2022/11/05 14:52:04 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buff(char *aux, int fd);
char	*ft_linewr(char *aux, int n);
char	*ft_auxline(char *aux, int a);

char	*get_next_line(int fd)
{
	static char	*aux[4096];
	char		*txt;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > 4096)
		return (NULL);
	aux[fd] = ft_read_buff(aux[fd], fd);
	txt = ft_linewr(aux[fd], ft_strchr(aux[fd], 10));
	aux[fd] = ft_auxline(aux[fd], ft_strchr(aux[fd], 10));
	return (txt);
}

char	*ft_read_buff(char *aux, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;

	if (!aux)
	{
		aux = malloc(sizeof(char));
		aux[0] = 0;
	}
	bytes_read = 1;
	while (!ft_strchr(aux, 10) && bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0 || (bytes_read == 0 && !aux[0]))
		{
			free(aux);
			return (NULL);
		}
		if (bytes_read == 0)
			return (aux);
		buf[bytes_read] = 0;
		aux = ft_strjoin(aux, buf);
	}
	return (aux);
}

char	*ft_linewr(char *aux, int n)
{
	char	*txt;

	if (n == 0)
		return (aux);
	txt = malloc((n + 1) * sizeof(char));
	if (txt == NULL)
		return (NULL);
	ft_strlcpy(txt, aux, n + 1);
	txt[n] = 0;
	return (txt);
}

char	*ft_auxline(char *aux, int a)
{
	int		b;
	char	*c;

	if (a == 0)
		return (NULL);
	b = ft_strlen(aux);
	c = malloc((b - a + 1) * sizeof(char));
	if (c == NULL)
		return (NULL);
	ft_strlcpy(c, aux + a, b - a + 1);
	free(aux);
	return (c);
}
