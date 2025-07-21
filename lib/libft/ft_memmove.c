/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:22:46 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/16 12:46:00 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*copy;
	char	*source;

	if (!src && !dest)
		return (0);
	i = 0;
	copy = (char *)dest;
	source = (char *)src;
	if (dest < src)
	{
		while (i < n)
		{
			copy[i] = source[i];
			i++;
		}
	}
	else
	{
		i = n;
		while (i-- > 0)
			copy[i] = source[i];
	}
	return (dest);
}
/*int main(void)
{
    char source[] = "hello";
	char	dest[] = "Salut";
    printf("Avant ft_memmove: %s\n", dest);
	ft_memmove(dest, source, 2);
    printf("Après ft_memmove: %s\n", dest);
    return 0;
}*/
