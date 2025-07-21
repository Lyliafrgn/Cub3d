/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 18:37:03 by lylfergu          #+#    #+#             */
/*   Updated: 2024/08/17 18:29:10 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		count;
	int		error;
	int		i;

	i = 0;
	count = 0;
	error = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			ft_check_type(args, str[++i], &count, &error);
		else
			ft_print_char(str[i], &count, &error);
		if (error == -1)
		{
			count = -1;
			break ;
		}
		i++;
	}
	va_end(args);
	return (count);
}
/*int	main(void)
{
	char	c = 'D';
	char	*str = "Hello tout le monde";
	char	*strn = NULL;
	int	ii = -2147483648;
	int digit = 2147483647;
	unsigned int uns = 31;
	int	*ptr = &ii;
	char	*test = str;
	void	*nil = NULL;
	int	count;
	int	ocount;
	
	ft_printf("Test de fonction reproduite pour : cspdiuxX\n");
	ft_printf("Pour un c et une s, cela donne: %c et %s\n", c, str);
	ft_printf("Pour un pointer: %p\n", ptr);
	ft_printf("Pour un digit i et d ainsi qu'un unsigned int
	: %i et %d ainsi que %u\n", ii, digit, uns);
	ft_printf("Pour un hexa min puis maj: %x puis %X\n", uns, uns);
	ft_printf("Enfin pour un pourcent voila ce que ca donne: %%\n");
	ft_printf("le pointeur de chaine donne: %p\n", test);
	ft_printf("le pointeur null donne: %p\n", nil);
	printf("le pointeur pour la vraie: %p\n", ptr);
	ft_printf("la string null donne : %s\n", strn);
	count = ft_printf("%p\n", ptr);
	ocount = printf("%p\n", ptr);
	ft_printf("%d\n", count);
	ft_printf("%d\n", ocount);
	return (0);
}*/
