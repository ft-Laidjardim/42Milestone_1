/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 14:09:29 by ljessica          #+#    #+#             */
/*   Updated: 2025/05/02 16:51:43 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *buffer, char c)
{
	int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == c)
			return (&buffer[i]);
		i++;
	}
	if (c == '\0')
		return (&buffer[i]);
	return (NULL);
}

char	*ft_strjoin_free(char *line, char *buffer)
{
	int		i;
	int		j;
	char	*line_concatened;

	if (!line)
	{
		line = malloc(1);
		if (!line)
			return (NULL);
		line[0] = '\0';
	}
	i = -1;
	j = -1;
	line_concatened = malloc(ft_strlen(line) + ft_strlen(buffer) + 1);
	if (!line_concatened)
		return (NULL);
	while (line[++i])
		line_concatened[i] = line[i];
	while (buffer[++j])
		line_concatened[i + j] = buffer[j];
	line_concatened[i + j] = '\0';
	free(line);
	return (line_concatened);
}
