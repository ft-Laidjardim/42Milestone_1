/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:26:43 by ljessica          #+#    #+#             */
/*   Updated: 2025/04/25 10:18:39 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

void	print_hex_universal(unsigned int n, int *count, int type);
void	print_pointer(void *ptr, int *count);
void	print_unsigned_decimal(unsigned int n, int *count);
void	print_decimal(int n, int *count);
void	print_str_count(char *str, int *count);
int		ft_printf(const char *str, ...);
void	print_char_count(char c, int *count);

#endif
