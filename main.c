/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgamil <mgamil@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 15:37:24 by mohazerr          #+#    #+#             */
/*   Updated: 2022/09/26 19:57:34 by mgamil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	lenmax(int max)
{
	int	i;

	i = -1;
	while (max > 0 && ++i >= 0)
		max /= 10;
	return (i);
}

int	main(int argc, char const *argv[])
{
	int		fd;
	int		i;
	int		max;
	char	*s;

	i = 0;
	if (argc != 3)
		return (printf("./a.out [file] [xnumberlines]\n"));
	fd = open(argv[1], O_RDONLY);
	if (fd < 3)
		return (printf("error while reading %s\n", argv[1]));	
	max = atoi(argv[2]);
	while (++i <= max && s)
	{
		s = get_next_line(fd);
		if (s == NULL)
			break ;
		printf("[%.*i/%.i] %s", lenmax(max) + 1, i, max, s);
	}
	printf("\nEOL\n");
	return (0);
}
