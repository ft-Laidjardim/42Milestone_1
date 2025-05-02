/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica < ljessica@student.42porto.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:57:20 by ljessica          #+#    #+#             */
/*   Updated: 2025/05/02 17:19:46 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_getrest(char *buffer)
{
	int	i;
	int	j;

	j = 0;
	i = 0;

	while (buffer[i] != '\n' && buffer[i])
		i++;
	if (buffer[i] == '\n')
		i++;
	while (buffer[i] != '\0')
	{
		buffer[j] = buffer[i];
		j++;
		i++;
	}
	while (j < BUFFER_SIZE)
	{
		buffer[j] = '\0';
		j++;
	}
}

char	*ft_readloop(int fd, char *line, char *buffer)
{
	char	*new_line;
	int		bytes;

	new_line = line;
	ft_getrest(buffer);
	while (1)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			if (line)
				free(line);
			ft_getrest(buffer);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		new_line = ft_strjoin_free(new_line, buffer);
		if (!new_line)
			return (NULL);
		if (ft_strchr(buffer, '\n'))
			break ;
		ft_getrest(buffer);
	}
	return (new_line);
}

char	*ft_getline(char *buffer, char *line)
{
	int	i;

	i = 0;
	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	line = ft_strjoin_free(line, buffer);
	while (line[i] != '\n' && line[i])
		i++;
	if (line[i] != '\0')
		line[i + 1] = '\0';
	ft_getrest(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	buffer[LIMIT_FD][BUFFER_SIZE + 1];
	char		*line;
	
	line = NULL;
	if (fd < 0)
		return (NULL);
	if (buffer[fd][0] && ft_strchr(buffer[fd], '\n'))
		return (ft_getline(buffer[fd], line));
	if (buffer[fd][0])
	{
		line = ft_strjoin_free(line, buffer[fd]);
		if (!line)
			return (NULL);
	}
	line = ft_readloop(fd, line, buffer[fd]);
	if (!line)
		return (NULL);
	line = ft_getline(buffer[fd], line);
	if (!line)
		return (NULL);
	return (line);
}
/*
#include <stdio.h>
#include <fcntl.h>
int	main()
{
	int	fd1;
	int fd2;
	char *line;
	int	x = 0;

	fd1 = open("arquivo2.txt", O_RDONLY);
	fd2 = open("arquivo1.txt", O_RDONLY);
	line = get_next_line(fd1);
	while (line)
	{
		printf("%s", line);
		free(line);
		if (x % 2 == 0)
			line = get_next_line(fd2);
		else
			line = get_next_line(fd1);
		x++;
	}

	close(fd1);
	close(fd2);
}*/
