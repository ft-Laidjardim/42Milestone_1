/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <ljessica@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 11:27:49 by ljessica          #+#    #+#             */
/*   Updated: 2025/05/02 17:14:34 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# ifndef LIMIT_FD
#  define LIMIT_FD 1024
# endif

# include <stdlib.h>
# include <unistd.h>

//Principal function
char	*get_next_line(int fd);

//Util functions
int		ft_strlen(char *str);
char	*ft_strchr(char *buffer, char c);
char	*ft_strjoin_free(char *line, char *buffer);

#endif
