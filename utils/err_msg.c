/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:30:09 by ofilloux          #+#    #+#             */
/*   Updated: 2025/09/07 15:35:11 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err_msg(char *string)
{
	int	len;

	len = ft_strlen(string);
	write(STDERR_FILENO, string, len);
	return (EXIT_FAILURE);
}
