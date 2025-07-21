/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 16:27:59 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/02 17:14:16 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)

{
	int	i;
	int	nb;
	int	res;

	i = 0;
	res = 0;
	nb = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\r' || nptr[i] == '\f')
	{
		i++;
	}
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			nb = -nb;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	res *= nb;
	return (res);
}
/*
int main()
{
 printf("%i\n", ft_atoi("-56"));
 printf("%i\n", ft_atoi("34"));
 printf("%i\n", ft_atoi("+24"));
 printf("%i\n", ft_atoi("+-123"));
 printf("%i", ft_atoi("-+562"));
 
 return (0);	
}*/
