/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yadereve <yadereve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 18:59:46 by yadereve          #+#    #+#             */
/*   Updated: 2023/11/27 16:52:36 by yadereve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;
	int			i;
	int			flag;

	i = 0;
	flag = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		while (BUFFER_SIZE > i)
			buffer[i++] = 0;
		return (NULL);
	}
	line = NULL;
	while (flag && (buffer[0] || (read(fd, buffer, BUFFER_SIZE) > 0)))
	{
		line = ft_strjoin(line, buffer);
		ft_freebuffer(&flag, buffer);
		if (line == NULL)
			return (NULL);
	}
	return (line);
}

/*
int	main()
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("file opening filed");
		return (1);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("line: %s", line);
		free(line);
	}
	close(fd);
	return (0);
} */
