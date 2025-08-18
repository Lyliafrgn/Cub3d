#include "../headers/cub3d.h"

static int	ft_close_window(void *param)
{
	t_global	*data;

	data = (t_global *)param;
	if (data)
		free_resources(data);
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
		free_resources(data);
	return (FAILURE);
}

int	init_mlx(t_global *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (FAILURE);
	data->win_ptr = mlx_new_window(data->mlx_ptr, data->winw, data->winh, "Cub3d");
	if (!data->win_ptr)
		return (FAILURE);
	if (upload_img(data) == FAILURE)
		ft_err("image upload failed", data);
	mlx_hook(data->win_ptr, 2, KeyPressMask, ft_key_pressed, data);
	mlx_hook(data->win_ptr, 3, KeyReleaseMask, ft_key_released, data);
	mlx_hook(data->win_ptr, 17, 0, ft_close_window, data);
	mlx_loop_hook(data->mlx_ptr, render_scene, data);
	return (SUCCESS);
}


int	ft_key_pressed(int keycode, t_global *data)
{
	if (keycode == XK_w || keycode == XK_W)
		data->dir.up = 1;
	else if (keycode == XK_s || keycode == XK_S)
		data->dir.down = 1;
	else if (keycode == XK_d || keycode == XK_D)
		data->dir.right = 1;
	else if (keycode == XK_a || keycode == XK_A)
		data->dir.left = 1;
	else if (keycode == XK_Left)
		data->dir.cam_left = 1;
	else if (keycode == XK_Right)
		data->dir.cam_right = 1;
	else if (keycode == XK_Escape)
	{
		printf("Escape key pressed\n");
		free_resources(data);
		exit (0);
	}
	return (0);
}

int	ft_key_released(int keycode, t_global *data)
{
	if (keycode == XK_w || keycode == XK_W)
		data->dir.up = 0;
	else if (keycode == XK_s || keycode == XK_S)
		data->dir.down = 0;
	else if (keycode == XK_d || keycode == XK_D)
		data->dir.right = 0;
	else if (keycode == XK_a || keycode == XK_A)
		data->dir.left = 0;
	else if (keycode == XK_Left)
		data->dir.cam_left = 0;
	else if (keycode == XK_Right)
		data->dir.cam_right = 0;
	return (0);
}
