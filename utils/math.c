/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 10:31:36 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/07 11:04:21 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/**
 * @brief mise au carre d'un double (pow(a, 2.0);)
 * @param a double
 */
double	sqr(double a)
{
	return (pow(a, 2.0));
}

/**
 * @brief Return the minimum value between two values
 * @param a double
 * @param b double
 */
double	min_two_val(double a, double b)
{
	if (a < b)
		return (a);
	return (b);
}
