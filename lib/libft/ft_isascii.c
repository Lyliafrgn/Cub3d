/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:45:21 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/01 18:06:00 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
	{
		return (1);
	}
	return (0);
}
/*
 * int     main(void)
{
        int     prt;

        prt = ft_isascii('c');
        printf("%d", prt);
        prt = ft_isascii('5');
        printf("%d", prt);
        prt = ft_isascii(' ');
        printf("%d", prt);
	prt = ft_isascii('X');
        printf("%d", prt);
       return (0);
}*/
