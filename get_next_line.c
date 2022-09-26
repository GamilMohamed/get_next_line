/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohazerr <mohazerr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:46:50 by mohazerr          #+#    #+#             */
/*   Updated: 2022/09/26 00:12:56 by mohazerr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*read_whole_file(int fd, char *buffer);
char	*get_first_line(char *buffer);
char	*erase_first_line(char *buffer);

char	*erase_first_line(char *buffer)
{
	size_t	lenline;
	size_t	i;
	char	*new;

	lenline = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new = ft_calloc(ft_strlen(buffer) - i + 1);
	i++;
	while (buffer[i])
		new[lenline++] = buffer[i++];
	free(buffer);
	return (new);
}

char	*get_first_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc(i + 2);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	return (line);
}

char	*read_whole_file(int fd, char *buffer)
{
	int		output;
	char	*temp;
	char	*line;

	output = 1;
	if (!buffer)
		buffer = ft_calloc(1);
	temp = ft_calloc(BUFFER_SIZE + 1);
	while (output > 0 && !strchr(buffer, '\n'))
	{
		output = read(fd, temp, BUFFER_SIZE);
		if (output == -1)
		{
			free(temp);
			return (NULL);
		}
		temp[output] = 0;
		line = ft_strjoin(buffer, temp);
		free(buffer);
		buffer = line;
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = read_whole_file(fd, buffer);
	line = get_first_line(buffer);
	buffer = erase_first_line(buffer);
	return (line);
}

// #include <fcntl.h>
// int main(void)
// {
// 	int fd;
// 	char *s;
// 	fd = open("42_with_nl", O_RDONLY);
// 	printf("appel 2\n");
// 		get_next_line(fd);
// 	s = get_next_line(fd);
// 	printf("%s", s);
// 	return 0;
// }
