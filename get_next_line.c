/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:40:40 by danielro          #+#    #+#             */
/*   Updated: 2022/11/03 19:40:07 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_buff(char *aux, int fd);
char	*ft_linewr(char *aux, int n);
char	*ft_auxline(char *aux, int a);

char	*get_next_line(int fd)
{
	static char	*aux;
	char		*txt;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	if (!aux)
	{
		aux = malloc(sizeof(char));
		aux[0] = 0;
	}
	aux = ft_read_buff(aux, fd);
	txt = ft_linewr(aux, ft_strchr(aux, 10));
	aux = ft_auxline(aux, ft_strchr(aux, 10));
	return (txt);
}

char	*ft_read_buff(char *aux, int fd)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while(!ft_strchr(aux, 10) && bytes_read > 0)
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
	ft_strlcpy(c, aux + a , b - a + 1);
	free(aux);
	return (c);
}

/*
int	main(void)
{
	int		fd;
	char	*txt;

//	fd = open("../../../francinette/tests/get_next_line/fsoares/multiple_nl.txt", O_RDONLY);
	fd = open("test.txt", O_RDONLY);
	printf("fd: %d\n", fd);
	txt = get_next_line(fd);
	printf("First line: %s", txt);
	txt = get_next_line(fd);
	printf("Second line: %s", txt);
	txt = get_next_line(fd);
	printf("Third line: %s", txt);
	txt = get_next_line(fd);
	printf("Fourth line: %s", txt);
	txt = get_next_line(fd);
	printf("Fifth line: %s", txt);
	txt = get_next_line(fd);
	printf("Sixth line: %s", txt);
	txt = get_next_line(fd);
	printf("Seventh line: %s", txt);
	close(fd);
return (0);
}*/
