/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 09:33:24 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:22:28 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static long int	is_posit(long int n)
{
	if (n >= 0)
		return (1);
	else
		return (0);
}

static long int	ft_size(long int n, int p)
{
	int	t;

	t = 0;
	if (p == 1)
	{
		while (n >= 10)
		{
			n = n / 10;
			t++;
		}
	}
	else
	{
		if (n == -2147483648)
			return (10);
		while (n <= -10)
		{
			n = n / 10;
			t++;
		}
	}
	return (t + 1);
}

static char	*ft_int_char(char *ret, long int n, int t, int sign)
{
	int	i;

	i = 0;
	if (sign == 0)
	{
		ret[i] = '-';
		i++;
		n *= -1;
	}
	i = t - 1;
	while (n >= 10)
	{
		ret[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	ret[i] = n % 10 + '0';
	ret[t] = '\0';
	return (ret);
}

/**
 * @brief Converts an integer to a null-terminated string.
 *
 * @param n The integer to convert.
 * @return Pointer to the newly allocated string representing the integer,
 *         or NULL if memory allocation fails.
*/
char	*ft_itoa(int n)
{
	char		*ret;
	int			t;
	long int	lo_n;

	lo_n = (long int)n;
	if (is_posit(lo_n))
		t = ft_size(lo_n, is_posit(lo_n));
	else
		t = ft_size(lo_n, is_posit(lo_n)) + 1;
	ret = malloc(1 + t * sizeof(char));
	if (!ret)
		return (NULL);
	ret = ft_int_char(ret, lo_n, t, is_posit(n));
	return (ret);
}
/*
int main ()
{
	printf("%s",ft_itoa(0));
}
*/
