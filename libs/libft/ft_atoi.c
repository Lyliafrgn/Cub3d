/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi copy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 10:36:24 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:15:25 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <stdlib.h>

/**
* @brief transform a string into and integer
* @param s : const char *s
* @return : int
*/
int	ft_atoi(const char *s)
{
	int	i;
	int	n;
	int	r;

	i = 0;
	n = 0;
	r = 0;
	while (s[i] == ' ' || (s[i] >= '\t' && s[i] <= '\r'))
	{
		i++;
	}
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			n++;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		r = r * 10 + (s[i] - '0');
		i++;
	}
	if (n % 2 == 1)
		r *= -1;
	return (r);
}

/*
int main ()
{
	printf("%i\n",ft_atoi(" ireu -12"));
	printf("%i\n\n",atoi(" ireu -12"));

	printf("%i\n",ft_atoi("--+-  213 ireu -12"));
	printf("%i\n\n",atoi(" --+-  213 ireu -12"));

	printf("%i\n",ft_atoi(" --+3-  213 ireu -12"));
	printf("%i\n\n",atoi(" --+3-  213 ireu -12"));

	printf("%i\n",ft_atoi(" --+4i2-  213 ireu -12"));
	printf("%i\n\n",atoi(" --+4i2-  213 ireu -12"));

	printf("%i\n",ft_atoi(" --+5 2- "));
        printf("%i\n\n",atoi(" --+5 2- "));

	printf("%i\n",ft_atoi(" --+623232323222 2-"));
        printf("%i\n\n",atoi(" --+623232323222 2-"));

	printf("%i\n",ft_atoi(""));
        printf("%i\n\n",atoi(""));

	printf("%i\n",ft_atoi("0"));
        printf("%i\n\n",atoi("0"));

	printf("%i\n",ft_atoi("-0"));
        printf("%i\n\n",atoi("-0"));

        printf("%i\n",ft_atoi("2"));
        printf("%i\n\n",atoi("2"));

        printf("%i\n",ft_atoi("-2"));
        printf("%i\n\n",atoi("-2"));

	printf("%i\n",ft_atoi(" 9"));
        printf("%i\n\n",atoi(" 9"));


        printf("%i\n",ft_atoi(" -+9"));
        printf("%i\n\n",atoi(" -+9"));


        printf("%i\n",ft_atoi("   +9"));
        printf("%i\n\n",atoi("   +9"));

        printf("%i\n",ft_atoi(" ++9"));
        printf("%i\n\n",atoi(" ++9"));


        printf("%i\n",ft_atoi(" --9"));
        printf("%i\n\n",atoi(" --9"));


        printf("%i\n",ft_atoi("-2147483648"));
        printf("%i\n\n",atoi("-2147483648"));

        printf("%i\n",ft_atoi("2147483647"));
        printf("%i\n\n",atoi("2147483647"));


        printf("%i\n",ft_atoi("-214748364999"));
        printf("%i\n\n",atoi("-214748364999"));

        printf("%i\n",ft_atoi("214748364799"));
        printf("%i\n\n",atoi("214748364799"));
}
*/
