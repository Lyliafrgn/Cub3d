/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 13:21:12 by lylfergu          #+#    #+#             */
/*   Updated: 2024/08/17 17:13:10 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_pointer(size_t ptr, int *count, int *error)
{
	char	*base;

	base = "0123456789abcdef";
	if (!ptr)
	{
		ft_print_str("(nil)", count, error);
	}
	else
	{
		if (ptr < 16)
		{
			ft_print_str("0x", count, error);
		}
		if (ptr >= 16)
		{
			ft_print_pointer(ptr / 16, count, error);
		}
		ft_print_char(base[ptr % 16], count, error);
	}
}
/*
int	main(void)
{
	int	count = 0;  
	char	*str = "Hello World!";
	void	*ptr = &str;  
	void	*nil = NULL;  
	int		number = 42;  
	void	*number_ptr = &number; 
	void	*essai = &str;

	ft_print_pointer((size_t)ptr, &count);
	write(1, "\n", 1);  
	ft_print_pointer((size_t)nil, &count);
	write(1, "\n", 1);
	ft_print_pointer((size_t)number_ptr, &count);
	write(1, "\n", 1);
	ft_print_pointer((size_t)essai, &count);
	return (0);
}*/
