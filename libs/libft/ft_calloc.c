/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 14:38:18 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:19:27 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/**
 * @brief Allocates and zero-initializes memory for an array.
 *
 * @param count Number of elements.
 * @param size Size of each element.
 * @return Pointer to the allocated zero-initialized memory,
 * or NULL on failure.
*/
void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*call;
	size_t			i;

	i = 0;
	call = malloc(count * size);
	if (!call)
		return (NULL);
	while (i < count * size)
	{
		call[i] = 0;
		i++;
	}
	return (call);
}

/*
int main ()
{
	ft_calloc(3,8);
}
*/
