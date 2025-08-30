/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofilloux <ofilloux@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:37:24 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/30 11:22:42 by ofilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXEC_H
# define EXEC_H

# include "structures.h"

/*MLX INIT*/
int		init_mlx(t_global *data);
int		ft_key_pressed(int keycode, t_global *data);
int		ft_key_released(int keycode, t_global *data);
int		ft_err(char *msg, t_global *data);

/*Charging textures*/
int		upload_img(t_global *data);

/*Rendering*/
int		render_scene(t_global *data);

/*Movements*/
void	ft_move(t_global *data);

/*Cast*/
int		ft_get_line_height(t_global *data, int col);

/*Cast Utils*/
void	ft_choose_wall_texture(t_ray *ray);
void	ft_set_step(t_global *data, t_point *step);
void	ft_set_sidedist(t_global *data, t_vec *sidedist, t_vec deltadist);
void	ft_init_deltadist(t_ray *ray, t_vec *deltadist);

/*Pixels*/
int		ft_get_texx(t_global *data);
int		ft_get_texpixel(t_global *data, int texx, int texy);
void	ft_pixel_put(t_global *data, int c, int r, int color);

/*Minimap*/
void	draw_minimap(t_global *data);
double	min_two_val(double a, double b);
bool	not_in_mmap(int col, int row);
void	draw_borders(t_global *data, t_mmap mmap, int col, int row);
void	drawmap(t_global *data, int col, int row);
void	draw_player(t_global *data, int col, int row);
void	calculate_tile_y(t_global *data, double row, int *tile_y);
void	calculate_tile_x(t_global *data, double col, int *tile_x);
bool	in_wall(t_global *data, int row, int col);
void	draw_rays(t_global *data, int row, int col);

#endif
