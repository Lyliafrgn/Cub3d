#include "cub3d.h"

void	ft_err(char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}