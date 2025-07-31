/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:37:24 by ofilloux          #+#    #+#             */
/*   Updated: 2025/07/30 01:09:56 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "structures.h"

int	run_game_main_loop(t_global *data);
int	init_mlx(t_global *data);
int ft_close_window(void);
int ft_key_pressed(int keycode, t_global *data);
int ft_key_released(int keycode, t_global *data);
int upload_img(t_global *data);
void	ft_err(char *msg);
#endif
