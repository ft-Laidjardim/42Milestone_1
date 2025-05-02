/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ljessica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 13:43:39 by ljessica          #+#    #+#             */
/*   Updated: 2025/04/22 16:45:11 by ljessica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_hex(unsigned long n)
{
	int	count;

	count = 0;
	if (!n)
		count = 1;
	while (n)
	{
		n /= 16;
		count++;
	}
	return (count);
}

void	print_hex_universal(unsigned int n, int *count, int type)
{
	char	*base_l;
	char	*base_u;
	char	str[9];
	int		total_digits;

	total_digits = count_hex(n);
	str[total_digits] = '\0';
	base_l = "0123456789abcdef";
	base_u = "0123456789ABCDEF";
	if (!n)
		str[0] = '0';
	while (n)
	{
		if (type == 'C')
			str[total_digits -1] = base_u[n % 16];
		else if (type == 'c')
			str[total_digits - 1] = base_l[n % 16];
		n /= 16;
		total_digits--;
	}
	print_str_count(str, count);
}

void	print_pointer(void *ptr, int *count)
{
	unsigned long	num;
	char			str[17];
	char			*base;
	int				total_digits;

	base = "0123456789abcdef";
	if (!ptr)
		return (print_str_count("(nil)", count));
	num = (unsigned long)ptr;
	total_digits = count_hex(num);
	str[total_digits] = '\0';
	while (num)
	{
		str[total_digits - 1] = base[num % 16];
		num /= 16;
		total_digits--;
	}
	print_str_count("0x", count);
	print_str_count(str, count);
}
