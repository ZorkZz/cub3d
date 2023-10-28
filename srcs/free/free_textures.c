#include "../../headers/cub3d.h"

void	free_images(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img.img);
	mlx_destroy_image(game->mlx, game->sprite[0].img);
	mlx_destroy_image(game->mlx, game->sprite[1].img);
	mlx_destroy_image(game->mlx, game->sprite[2].img);
	mlx_destroy_image(game->mlx, game->sprite[3].img);
}
