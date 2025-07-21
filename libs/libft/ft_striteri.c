/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri copy.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 11:34:52 by ofilloux          #+#    #+#             */
/*   Updated: 2025/06/11 15:58:29 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @brief Applies the function f to each character of the string s,
 *        passing its index.
 *
 * The function f is applied in-place to each character of the string s,
 * with its index as the first argument.
 *
 * @param s The string to iterate over (must be modifiable).
 * @param f The function to apply to each character,
 *          taking its index and a pointer to the character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		(*f)(i, &s[i]);
		i++;
	}
}
