/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 18:30:04 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:03:43 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Computes the length of a null-terminated string.
 *
 * Counts and returns the number of characters in the string
 * before the null terminator '\0'. Does not include it.
 *
 * @param s Input string (must be null-terminated).
 * @return Length of the string (number of characters before '\0').
 */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s && s[i] != '\0')
		i++;
	return (i);
}
