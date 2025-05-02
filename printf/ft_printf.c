/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:42:22 by ljessica          #+#    #+#             */
/*   Updated: 2025/04/25 11:28:07 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_char_count(char c, int *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	print_str_count(char *str, int *count)
{
	if (!str)
		str = "(null)";
	while (*str)
	{
		write(1, str, 1);
		(*count)++;
		str++;
	}
}

void	actions(va_list params, char c, int *count)
{
	if (c == 'c')
		print_char_count(va_arg(params, int), count);
	else if (c == 's')
		print_str_count(va_arg(params, char *), count);
	else if (c == 'd' || c == 'i')
		print_decimal(va_arg(params, int), count);
	else if (c == 'u')
		print_unsigned_decimal(va_arg(params, unsigned int), count);
	else if (c == '%')
		print_char_count('%', count);
	else if (c == 'x')
		print_hex_universal(va_arg(params, unsigned int), count, 'c');
	else if (c == 'X')
		print_hex_universal(va_arg(params, unsigned int), count, 'C');
	else if (c == 'p')
		print_pointer(va_arg(params, void *), count);
}

int	ft_printf(const char *str, ...)
{
	va_list	params;
	int		count;

	count = 0;
	va_start(params, str);
	while (*str)
	{
		if (*str != '%')
			print_char_count(*str, &count);
		else if (*str == '%')
		{
			str++;
			actions(params, *str, &count);
		}
		str++;
	}
	va_end(params);
	return (count);
}
