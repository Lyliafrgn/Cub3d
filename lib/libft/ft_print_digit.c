/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_digit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:23:24 by lylfergu          #+#    #+#             */
/*   Updated: 2024/08/18 17:01:21 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_number(int n, int *count, int *error)
{
	if (n == -2147483648)
	{
		ft_print_char('-', count, error);
		ft_print_char('2', count, error);
		n = 147483648;
	}
	if (n < 0)
	{
		ft_print_char('-', count, error);
		n *= -1;
	}
	if (n >= 10)
	{
		ft_print_number(n / 10, count, error);
		ft_print_number(n % 10, count, error);
	}
	else
	{
		ft_print_char((n + 48), count, error);
	}
}

void	ft_unsigned_int(unsigned int u, int *count, int *error)
{
	if (u >= 10)
	{
		ft_unsigned_int(u / 10, count, error);
		ft_unsigned_int(u % 10, count, error);
	}
	else
	{
		ft_print_char((u + 48), count, error);
	}
}
/*int main (void)
{
	int	*count;

	count = 0;
	ft_print_number(15, count);
	write(1, "\n", 1);
	ft_unsigned_int(36, count);
	return (0);
}*/
