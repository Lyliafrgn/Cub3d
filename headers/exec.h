/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:37:24 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/14 13:32:48 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "structures.h"

int		init_mlx(t_global *data);
int		ft_key_pressed(int keycode, t_global *data);
int		ft_key_released(int keycode, t_global *data);
int     ft_err(char *msg, t_global *data);

int		upload_img(t_global *data);
int		render_scene(t_global *data);

int		ft_get_texx(t_global *data);
int		ft_get_texpixel(t_global *data, int texx, int texy);
void	ft_pixel_put(t_global *data, int c, int r, int color);

int	    ft_get_line_height(t_global *data, int col);

void	ft_move(t_global *data);

void    ft_free_resources(t_global *data);

#endif
