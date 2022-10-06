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
	char		buf[BUFFER_SIZE + 1];
	int			bytes_read;
	static char	*aux = NULL;
	char		*txt = "";

	bytes_read = read(fd, buf, BUFFER_SIZE);
	buf[bytes_read] = '\0';
	if (bytes_read < 1 || fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	while (!ft_schrnl(buf))
	{
		if (!ft_schrnl(aux))
		{
			aux = ft_line(aux, buf);
			bytes_read = read(fd, buf, BUFFER_SIZE);
			buf[bytes_read] = '\0';
		}
		else
			break;
	}
	if (!ft_schrnl(aux))
	{
		txt = ft_linewr(aux, buf);
		aux = ft_liner(buf); 
	}
	else
	{
		txt = ft_totalln(aux);
		aux = ft_liner(aux);
	}
	return (txt);
}

int	main(void)
{
	int		fd;
	char	*txt;

//	fd = open("../../../francinette/tests/get_next_line/fsoares/1char.txt", O_RDONLY);
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
}
