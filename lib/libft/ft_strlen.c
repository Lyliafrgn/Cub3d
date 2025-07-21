/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/21 14:45:12 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/04 12:29:37 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}
/*
int     main(void)
{
        int     prt;

        prt = ft_strlen("hello");
        printf("%d\n", prt);
        prt = ft_strlen("pas d inspi");
        printf("%d\n", prt);

        return (0);
}*/
