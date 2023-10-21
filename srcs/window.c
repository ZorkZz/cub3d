#include "../headers/cub3d.h"

void draw(t_game *game);

int	init_win(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, "cub3d");
	if (!game->win)
		return (exit_mlx(game), 1);
	return (0);
}

void	render_win(t_game *game)
{
	game->img.img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img, \
			&game->img.bits_per_pixel, \
			&game->img.line_length, &game->img.endian);
	raycast(game);
	draw(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	mlx_destroy_image(game->mlx, game->img.img);
}

int	exit_mlx(void *arg)
{
	t_game	*game;

	game = arg;
	exit_win(game, 0);
	return (1);
}

int	exit_win(t_game *game, int error)
{
	free_color(game->map.color);
	free_path(game->map.path);
	free_strs(game->map.map);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (exit(error), 1);
}
