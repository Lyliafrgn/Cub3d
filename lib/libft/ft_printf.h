/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 14:20:18 by lylfergu          #+#    #+#             */
/*   Updated: 2024/08/17 15:08:20 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_print_number(int n, int *count, int *error);
void	ft_unsigned_int(unsigned int u, int *count, int *error);
void	ft_print_hexa(unsigned int num, int *count, int *error, char x_X);
void	ft_print_pointer(size_t ptr, int *count, int *error);
void	ft_check_type(va_list args, char c, int *count, int *error);
void	ft_print_char(char c, int *count, int *error);
int		ft_printf(const char *str, ...);
void	ft_print_str(char *str, int *count, int *error);

#endif
