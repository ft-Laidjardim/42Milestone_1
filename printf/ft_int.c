/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:47:44 by ljessica          #+#    #+#             */
/*   Updated: 2025/04/25 15:51:44 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(unsigned int n)
{
	int	count;

	count = 0;
	if (!n)
		count = 1;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

void	print_unsigned_decimal(unsigned int n, int *count)
{
	char	str[11];
	int		total_digits;

	total_digits = count_digits(n);
	str[total_digits] = '\0';
	if (!n)
		str[0] = '0';
	while (n)
	{
		str[total_digits - 1] = (n % 10) + 48;
		n /= 10;
		total_digits--;
	}
	print_str_count(str, count);
}

void	print_decimal(int n, int *count)
{
	char			number[11];
	unsigned int	n_absolute;
	int				digits;

	n_absolute = n;
	if (n < 0)
	{
		n_absolute = -n;
		print_char_count('-', count);
	}
	if (!n)
		return (print_char_count('0', count));
	digits = count_digits(n_absolute);
	number[digits] = '\0';
	while (n_absolute)
	{
		number[digits - 1] = (n_absolute % 10) + 48;
		n_absolute = n_absolute / 10;
		digits--;
	}
	print_str_count(number, count);
}
