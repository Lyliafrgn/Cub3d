/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 16:45:35 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/13 16:52:32 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
	}
	if (s[i] == c)
	{
		return ((char *)s + i);
	}
	return (NULL);
}
/*int	main(void)
{
	char	*s;
	char	*prt;

	s = "salut ca va?";
	prt = ft_strchr(s, 'c');
	printf("%s", prt);
	return (0);
}*/
