/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 13:40:40 by danielro          #+#    #+#             */
/*   Updated: 2022/09/08 13:40:46 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int ft_linelen(char *str)
{
    int i;

    i = 0;
    while (str[i] != 10 && str[i] != '\0')
        i++;
    return (i);
}

char    *ft_line(char *src)
{
    char            *txt;
    static int      end = 0;
    int             start;
    int             i = 0;

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

char    *get_next_line(int fd)
{
    static char    *buf;
    static int      line = 0;
//    size_t          nbytes;
    ssize_t         bytes_read = 0;
    char            *txt;
    int             nlen;
    int             i = 0;

//    printf("Buffer inicio: %s\n", buf);
//    nbytes = sizeof(BUFFER_SIZE);
    if (line == 0)
    {
        buf = malloc(BUFFER_SIZE * sizeof(char));
        bytes_read = read(fd, buf, BUFFER_SIZE);
        buf[bytes_read] = '\0';
        line++;
    }
//    printf("Buffer: %s\n", buf);
//    printf("Total bytes: %zd\n", bytes_read);
//    printf("line: %d\n", line);
//    txt = ft_line(buf);
    nlen = ft_linelen(buf);
    txt = malloc((nlen + 1) * sizeof(char));
    while (nlen-- > 0)
    {
        txt[i] = buf[0];
        buf++;
        i++;
    }
    txt[i] = '\0';
    line++;
    buf++;
    return (txt);
}

int     main(void)
{
    int     fd;
    char    *txt;

    fd = open("test.txt", O_RDONLY);
    txt = get_next_line(fd);
    printf("First line: %s\n", txt);
    txt = get_next_line(fd);
    printf("Second line: %s\n", txt);
    txt = get_next_line(fd);
    printf("Third line: %s\n", txt);
//    txt = get_next_line(fd);
//    printf("Fourth line: %s\n", txt);
    return (0);
}
