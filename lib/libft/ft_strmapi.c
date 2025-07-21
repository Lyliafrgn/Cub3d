/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:20:45 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/08 18:45:21 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*str;

	i = 0;
	if (!s || !f)
	{
		return (NULL);
	}
	len = ft_strlen(s);
	str = (char *)malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
	{
		return (NULL);
	}
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
char f(unsigned int i, char c)
{
	char str;
	str = c + 1;
	return (str);
}

int main(void)
{
	char str1[] = "abc";
	char* str2;
	str2 = ft_strmapi(str1, *f);
	printf("%s\n", str2);
	free(str2);
	return (0);
}*/
