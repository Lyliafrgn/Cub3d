/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower copy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:33:43 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:12:54 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Converts an uppercase letter to lowercase.
 *
 * If c is an uppercase ASCII letter ('A'-'Z'),
 * converts it to the corresponding lowercase letter.
 * Otherwise, returns c unchanged.
 *
 * @param c Character to convert (as int).
 * @return Lowercase equivalent if uppercase letter, else c.
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
