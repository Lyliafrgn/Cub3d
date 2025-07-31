#include "../headers/cub3d.h"

//dessiner bande

int	game_loop(t_data *data)
{
	int	col;

	col = 0;
	if (data->left || data->right || data->up || data->down || data->cam_left
		|| data->cam_right)
		ft_move(data);
	while (col < data->winw)
	{
		ft_draw_stripe(data, col);
		col++;
	}
	if (data->mlx_ptr && data->win_ptr && data->screen.mlx_img)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->screen.mlx_img, 0, 0);
	return (0);
}
