/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/24 03:35:31 by mohazerr          #+#    #+#             */
/*   Updated: 2022/09/26 19:56:49 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	42
# endif

size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_calloc(size_t n);

char	*get_next_line(int fd);
char	*read_whole_file(int fd, char *buffer);
char	*get_first_line(char *buffer);
char	*erase_first_line(char *buffer);

#endif