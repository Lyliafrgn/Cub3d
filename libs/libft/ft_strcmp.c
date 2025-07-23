/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 15:18:48 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 16:39:23 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief The  strcmp()  function compares the two strings s1 and s2.
//    strcmp() returns an integer indicating the result of the comparison, as
//    follows:
/// @return     • 0, if the s1 and s2 are equal;
/// @return     • a negative value if s1 is less than s2;
/// @return     • a positive value if s1 is greater than s2.
int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ptr1;
	unsigned char	*ptr2;
	int				i;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	if (!ptr1 || !ptr2)
		return (0);
	i = 0;
	while (!(ptr1[i] == '\0' && ptr2[i] == '\0'))
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}
/*
#include <stdio.h>

int ft_strcmp(const char *s1, const char *s2);

int main(void)
{
	char *str1 = "hola";
	char *str2 = "hola";
	char *str3 = "holb";
	char *str4 = "hol";

	printf("Comparando '%s' y '%s': %d\n", str1,
		str2, ft_strcmp(str1, str2)); // 0
	printf("Comparando '%s' y '%s': %d\n",
		str1, str3, ft_strcmp(str1, str3));
	printf("Comparando '%s' y '%s': %d\n", str1, str4,
		ft_strcmp(str1, str4));

	return 0;
}
*/
