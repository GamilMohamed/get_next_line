/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 15:46:50 by mohazerr          #+#    #+#             */
/*   Updated: 2022/11/09 20:32:59 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#include <stdio.h>
#include <fcntl.h>

char	*get_next_line(int fd);
char	*read_first_line(int fd, char *buffer);
char	*get_first_line(char *buffer);
char	*erase_first_line(char *buffer);

char	*erase_first_line(char *buffer)
{
	size_t	i;
	size_t	x;
	char	*new;

	x = 0;
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	new = ft_calloc(ft_strlen(buffer) - i + 1);
	if (!new)
		return (NULL);
	i++;
	while (buffer[i])
		new[x++] = buffer[i++];
	new[x] = 0;
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
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	return (line);
}

char	*read_first_line(int fd, char *buffer)
{
	int		output;
	char	*temp;
	char	*line;

	output = 1;
	if (!buffer)
		buffer = ft_calloc(1);
	temp = ft_calloc(BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	while (output > 0 && !ft_strchr(buffer, '\n'))
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
	buffer = read_first_line(fd, buffer);
	line = get_first_line(buffer);
	buffer = erase_first_line(buffer);
	return (line);
}

// #include <stdio.h>

// int main()
// {
// 	int fd;
// 	char *s;

// 	fd = open("gnlTester/files/big_line_no_nl", O_RDONLY);
// 	s = get_next_line(fd);	
// 	printf("%i\n", fd);
// 	printf("%s\n", s);
// }