/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:59:53 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/16 13:21:01 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;

	i = 0;
	tab = malloc(nmemb * size);
	if (tab == NULL)
	{
		return (NULL);
	}
	while (i < nmemb * size)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}
/*int main() 
{
    size_t nmemb = 5;
    size_t size = sizeof(int);

    int *tab = (int *)ft_calloc(nmemb, size);
    if (tab == NULL) 
	{
        printf("Memory allocation failed\n");
        return (1); 
	}
    printf("Allocated and zero-initialized array:\n");
    for (size_t i = 0; i < nmemb; i++) {
        printf("%d ", tab[i]);
    }
    printf("\n");
    free(tab);
    return (0);
}*/
