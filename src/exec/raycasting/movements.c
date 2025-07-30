#include "../headers/cub3d.h"

void	ft_move(t_data *data)
{
	if (data->up || data->down)
		ft_move_vertical(data);
	if (data->left || data->right)
		ft_move_horizontal(data);
	if (data->rotleft || data->rotright)
		ft_rotate(data);
}
