/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:40:40 by danielro          #+#    #+#             */
/*   Updated: 2022/09/19 18:58:27 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*buf;
	static int	line = 0;
	static int	bytes_read = 0;
	char		*txt;
	int			nlen;

	if (line == 0)
	{
		buf = malloc(BUFFER_SIZE * sizeof(char));
		bytes_read = read(fd, buf, BUFFER_SIZE);
		buf[bytes_read] = '\0';
		line++;
	}
	if (bytes_read < 1 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	nlen = ft_linelen(buf);
	txt = ft_linewr(buf, nlen);
	bytes_read -= nlen + 1;
	line++;
	buf = buf + nlen + 1;
	return (txt);
}

int	main(void)
{
	int		fd;
	char	*txt;

	fd = open("../../../francinette/tests/get_next_line/fsoares/giant_line_nl.txt", O_RDONLY);
//	fd = open("fsoares/1char.txt", O_RDONLY);
	printf("fd: %d\n", fd);
	txt = get_next_line(fd);
	printf("First line: %s\n", txt);
	txt = get_next_line(fd);
	printf("Second line: %s\n", txt);
	txt = get_next_line(fd);
	printf("Third line: %s\n", txt);
	txt = get_next_line(fd);
	printf("Fourth line: %s\n", txt);
	txt = get_next_line(fd);
	printf("Fifth line: %s\n", txt);
	txt = get_next_line(fd);
	printf("Sixth line: %s\n", txt);
	close(fd);
	return (0);
}
