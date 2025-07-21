/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:05:08 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/16 13:04:12 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*str;
	size_t	i;

	str = s;
	i = 0;
	while (i < n)
	{
		str[i] = c;
		i++;
	}
	return (s);
}
/*int main(void)
{
	char str[] = "hello";
	int c = 's';
	printf("avant fonction %s\n", str);
	ft_memset(str, c, 2);
	printf("Apres fonction: %s\n", str);
	return (0);
}*/
