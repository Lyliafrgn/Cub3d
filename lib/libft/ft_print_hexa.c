/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 12:47:31 by lylfergu          #+#    #+#             */
/*   Updated: 2024/08/17 14:17:47 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_hexa(unsigned int num, int *count, int *error, char x_X)
{
	char	*base;

	if (x_X == 'X')
	{
		base = "0123456789ABCDEF";
	}
	else
	{
		base = "0123456789abcdef";
	}
	if (num >= 16)
	{
		ft_print_hexa(num / 16, count, error, x_X);
	}
	ft_print_char(base[num % 16], count, error);
}
/*int	main(void)
{
	unsigned int uns;
	int	*count;

	uns = 31;
	ft_print_hexa(uns, count, 'x');
	ft_print_hexa(uns, count, 'X');
	return (0);
}*/
