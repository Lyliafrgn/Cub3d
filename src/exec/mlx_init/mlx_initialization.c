/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_initialization.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ly <ly@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:55:30 by ofilloux          #+#    #+#             */
/*   Updated: 2025/08/21 03:10:28 by ly               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	ft_close_window(void *param)
{
	t_global	*data;

	data = (t_global *)param;
	if (data)
		ft_free_resources(data);
	printf("Window closed\n");
	exit(0);
	return (0);
}

int	ft_err(char *msg, t_global *data)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	if (data)
		ft_free_resources(data);
	return (FAILURE);
}

int	init_mlx(t_global *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return ((ft_err("Err MLX init failed (mlx_ptr is NULL)", data)));
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			data->winw, data->winh, "Cub3d");
	if (!data->win_ptr)
		return (ft_err("Err: Window creation failed (mlx_new_window)", data));
	if (upload_img(data) == FAILURE)
		return (ft_err("Err: Failed to load textures or screen image", data));
	mlx_hook(data->win_ptr, 2, KeyPressMask, ft_key_pressed, data);
	mlx_hook(data->win_ptr, 3, KeyReleaseMask, ft_key_released, data);
	mlx_hook(data->win_ptr, 17, 0, ft_close_window, data);
	mlx_loop_hook(data->mlx_ptr, render_scene, data);
	return (SUCCESS);
}

int	ft_key_pressed(int keycode, t_global *data)
{
	if (keycode == XK_w || keycode == XK_W)
		data->up = 1;
	else if (keycode == XK_s || keycode == XK_S)
		data->down = 1;
	else if (keycode == XK_d || keycode == XK_D)
		data->right = 1;
	else if (keycode == XK_a || keycode == XK_A)
		data->left = 1;
	else if (keycode == XK_Left)
		data->cam_left = 1;
	else if (keycode == XK_Right)
		data->cam_right = 1;
	else if (keycode == XK_Escape)
	{
		printf("Escape key pressed\n");
		ft_free_resources(data);
		exit (0);
	}
	return (0);
}

int	ft_key_released(int keycode, t_global *data)
{
	if (keycode == XK_w || keycode == XK_W)
		data->up = 0;
	else if (keycode == XK_s || keycode == XK_S)
		data->down = 0;
	else if (keycode == XK_d || keycode == XK_D)
		data->right = 0;
	else if (keycode == XK_a || keycode == XK_A)
		data->left = 0;
	else if (keycode == XK_Left)
		data->cam_left = 0;
	else if (keycode == XK_Right)
		data->cam_right = 0;
	return (0);
}

/*void	print_structs(t_global *data) // @debug
{
	printf("saved map is :\n%s\n", data->map.map_string);
	printf("Map width: %d, height: %d\n", data->map.width, data->map.height);
	printf("Map content:\n");
	print_pp_char_arr(data->map.map);
	printf("____________\n");
	printf("Map texture : \n  NO: `%s`,\n  SO: `%s`,\n  EA: `%s`,\n  WE: `%s`\n",
		data->txtr[TX_NO].path, data->txtr[TX_SO].path,
		data->txtr[TX_EA].path, data->txtr[TX_WE].path);
	printf("colors : floor: %d, %d, %d; ceiling: %d, %d, %d\n\n",
		data->colors[0][0], data->colors[0][1], data->colors[0][2],
		data->colors[1][0], data->colors[1][1], data->colors[1][2]);
}*/
