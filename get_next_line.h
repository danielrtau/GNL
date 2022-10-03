/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielro <danielro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 19:51:12 by danielro          #+#    #+#             */
/*   Updated: 2022/09/16 19:51:15 by danielro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

char	*get_next_line(int fd);
int		ft_linelen(char *str, char sch);
char	*ft_linewr(char *src1, char *src2);
int		ft_totalln(char *str);
char	*ft_nextln(char *str);
int		ft_schrnl(char *str);
int		ft_strlen(char *str1, char *str2);
char	*ft_line(char *src1, char *src2);
char	*ft_linenl(char *src1, char *src2);
int		ft_strlennl(char *str1, char *str2);
char	*ft_liner(char *src);

#endif
