/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:19:43 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/13 15:51:23 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include "libft.h"

static int	count_size(int n)
{
	int	count;

	if (n == 0)
	{
		return (1);
	}
	count = 0;
	if (n < 0)
	{
		count = 1;
	}
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		nbr;
	int		len;

	nbr = n;
	len = count_size(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		nbr *= -1;
	}
	str = (char *)malloc((sizeof(*str) * len) + 1);
	if (!str)
		return (NULL);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = (nbr % 10) + 48;
		nbr /= 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
/*int	main(void)
{
	char	*ptr;

	ptr = ft_itoa(-56);
	printf("%s\n", ptr);
	ptr = ft_itoa(34);
	printf("%s\n", ptr);
	ptr = ft_itoa(0);
	printf("%s\n", ptr);
	ptr = ft_itoa(562589);
	printf("%s\n", ptr);
	ptr = ft_itoa(-2147483648);
	printf("%s\n", ptr);
	free (ptr);
	return (0);
}*/
