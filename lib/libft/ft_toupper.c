/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:36:46 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/02 12:40:02 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
	{
		c -= 32;
	}
	return (c);
}
/*int	main(void)
{
	int	prt;

	prt = ft_toupper('c');
	printf("%d\n", prt);
	prt = ft_toupper('5');
        printf("%d\n", prt);
	prt = ft_toupper('L');
        printf("%d\n", prt);
	return (0);
}*/
