/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylfergu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 18:46:09 by lylfergu          #+#    #+#             */
/*   Updated: 2024/07/15 17:54:02 by lylfergu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
void	to_upper(unsigned int i, char *s)
{
		(void)i;	
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
}

int	main(void)
{
	char str[7] = "hello";
	printf("%s\n", str);
	ft_striteri(str, to_upper);
	printf("%s", str);
}*/
