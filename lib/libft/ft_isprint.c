/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:57:10 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/03 12:25:29 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
	{
		return (1);
	}
	return (0);
}
/*
int     main(void)
{
        int     prt;

        prt = ft_isprint('c');
        printf("%d\n", prt);
        prt = ft_isprint('5');
        printf("%d\n", prt);
        prt = ft_isprint(' ');
        printf("%d\n", prt);
        return (0);
}*/
