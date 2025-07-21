/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:14:42 by lylfergu          #+#    #+#             */
/*   Updated: 2024/08/17 14:56:40 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_type(va_list args, char c, int *count, int *error)
{
	if (c == 'c')
		ft_print_char(va_arg(args, int), count, error);
	else if (c == 's')
		ft_print_str(va_arg(args, char *), count, error);
	else if (c == 'p')
		ft_print_pointer(va_arg(args, size_t), count, error);
	else if (c == 'd' || c == 'i')
		ft_print_number(va_arg(args, int), count, error);
	else if (c == 'u')
		ft_unsigned_int(va_arg(args, unsigned int), count, error);
	else if (c == 'x' || c == 'X')
		ft_print_hexa(va_arg(args, unsigned int), count, error, c);
	else if (c == '%')
		ft_print_char('%', count, error);
	else if (c == '\0')
		*error = -1;
	else
		ft_print_char(c, count, error);
}
