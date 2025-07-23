/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:23:10 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:12:53 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>

/**
 * @brief Converts a lowercase letter to uppercase.
 *
 * If c is a lowercase ASCII letter ('a'-'z'),
 * converts it to the corresponding uppercase letter.
 * Otherwise, returns c unchanged.
 *
 * @param c Character to convert (as int).
 * @return Uppercase equivalent if lowercase letter, else c.
 */
int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	else
		return (c);
}
/*
int main ()
{
	printf("%c\n",ft_toupper(99));
	printf("%c\n\n",toupper(99));

	printf("%c\n",ft_toupper(65));
	printf("%c\n\n",toupper(65));

	printf("%c\n",ft_toupper(6888));
	printf("%c\n\n",toupper(6888));

}
*/
