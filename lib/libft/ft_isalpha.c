/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:16:55 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/01 17:48:47 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
	{
		return (1);
	}
	return (0);
}
/*
int     main(void)
{
        int     prt;

        prt = ft_isalpha('c');
        printf("%d", prt);
        prt = ft_isalpha('5');
        printf("%d", prt);
        prt = ft_isalpha(' ');
        printf("%d", prt);
        prt = ft_isalpha('X');
        printf("%d", prt);
        return (0);
}*/
