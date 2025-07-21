/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:00:42 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/08 18:40:38 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include <stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	str = 0;
	if (s1 != 0 && set != 0)
	{
		start = 0;
		end = ft_strlen(s1);
		while (s1[start] && ft_strchr(set, s1[start]))
			start++;
		while (s1[end - 1] && ft_strchr(set, s1[end - 1]) && end > start)
			end--;
		str = (char *)malloc((end - start + 1) * sizeof(char));
		if (str)
		{
			ft_strlcpy(str, &s1[start], end - start + 1);
		}
	}
	return (str);
}
/*int	main(void)
{
	char	*str;

	str = ft_strtrim("abqbc", "abc");
	printf("le resultat apres trimming est %s\n", str);
	str = ft_strtrim("ababaMy name is Simonabababaa", "ab");
	printf("le resultat apres trimming est %s\n", str);
	free (str);
	return (0);
}*/
