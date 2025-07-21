/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:02:16 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/16 13:08:56 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	copy = (char *)malloc(sizeof(char) * (i + 1));
	if (copy == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (s[i])
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
int main() 
{
	const char *source = "Hello, World!";

	printf("la chaine source est: %s\n", source);
	char *dup = ft_strdup(source);
	printf("Chaine dupliquee: %s\n", dup);
	free(dup);
	return (0);
}*/
