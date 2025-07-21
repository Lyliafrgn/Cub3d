/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 13:34:47 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/01 17:42:12 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= 65 && c <= 90) || (c >= 97 && c <= 122)
		|| (c >= 48 && c <= 57))
	{
		return (1);
	}
	return (0);
}

/*
int     main(void)
{
        int     prt;

        prt = ft_isalnum('c');
        printf("%d", prt);
        prt = ft_isalnum('5');
        printf("%d", prt);
        prt = ft_isalnum(' ');
        printf("%d", prt);
        return (0);
}
*/
