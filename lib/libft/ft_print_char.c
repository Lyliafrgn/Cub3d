/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 12:46:58 by lylfergu          #+#    #+#             */
/*   Updated: 2024/08/17 14:09:48 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <unistd.h>

void	ft_print_char(char c, int *count, int *error)
{
	if (write(1, &c, 1) != 1)
		*error = -1;
	*count += 1;
}
/*int main (void)
{
	int	*count;

	count = 0;

	ft_print_char('D', count);
	return (0);
}*/
