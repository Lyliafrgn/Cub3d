/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 15:30:09 by ofilloux          #+#    #+#             */
/*   Updated: 2025/10/06 16:15:50 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int err_msg(char *string)
{
  	static int already_printed = 0;
	int	len;

	len = ft_strlen(string);
    if (!already_printed)
    {
        write(STDERR_FILENO, string, len);
        already_printed = 1;
    }
    return (EXIT_FAILURE);
}
