/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 13:06:59 by lylfergu          #+#    #+#             */
/*   Updated: 2024/08/17 14:14:15 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_str(char *str, int *count, int *error)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		str = "(null)";
	}
	while (str[i])
	{
		ft_print_char(str[i], count, error);
		if (*error == -1)
			break ;
		i++;
	}
}
/*int main (void)
{
	int	*count;

	count = 0;
	ft_print_str("Salut la compagnie", count, error);
	return (count);

}*/
