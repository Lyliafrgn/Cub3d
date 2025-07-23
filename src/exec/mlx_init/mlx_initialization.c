#include "../headers/cub3d.h"

int ft_close_window(t_global *data)
{
    printf("Window closed\n") // message a modifier ?;
    //FREE(data);
    exit(0);
    return (0);
}

int	init_mlx(t_global *data)
{
	data->mlx_ptr = mlx_init();
	if (!data->mlx_ptr)
		return (FAILURE);

	data->win_ptr = mlx_new_window(data->mlx_ptr, data->winw, data->winh, "Cub3d");
	if (!data->win_ptr)
		return (FAILURE);

	if (load_img(data) == FAILURE)
		return (ft_free_data(data), FAILURE); // ajouter message d erreur ? 
	mlx_hook(data->win_ptr, 2, KeyPressMask, ft_key_pressed, data;
	mlx_hook(data->win_ptr, 3, KeyReleaseMask, ft_key_released, data);
	mlx_hook(data->win_ptr, 17, ButtonPresMask, ft_close_window, data);
	mlx_loop_hook(data->mlx_ptr, ft_render, data);
	return (SUCCESS);
}

// IN PROGRESS

int ft_key_pressed(int keycode, t_global *data)

int ft_key_released(int keycode, t_global *data)