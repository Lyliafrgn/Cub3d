/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:31:09 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/01 18:11:36 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}
/*int     main(void)
{
        int     prt;

        prt = ft_isdigit('c');
        printf("%d", prt);
        prt = ft_isdigit('5');
        printf("%d", prt);
        prt = ft_isdigit(' ');
        printf("%d", prt);
        prt = ft_isdigit('X');
        printf("%d", prt);
       return (0);
}*/
