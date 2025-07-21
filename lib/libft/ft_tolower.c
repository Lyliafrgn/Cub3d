/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:42:37 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/02 13:23:40 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
	{
		c += 32;
	}
	return (c);
}
/*
int     main(void)
{
        int     prt;

        prt = ft_tolower('c');
        printf("%d\n", prt);
        prt = ft_tolower('5');
        printf("%d\n", prt);
        prt = ft_tolower('L');
        printf("%d\n", prt);
        return (0);
}*/
