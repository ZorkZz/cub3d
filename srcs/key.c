#include "../headers/cub3d.h"

int	deal_key(t_game *game)
{
	if (game->perso.w == 1)
		move_player(game, 'w');
	if (game->perso.a == 1)
		move_player(game, 'a');
	if (game->perso.s == 1)
		move_player(game, 's');
	if (game->perso.d == 1)
		move_player(game, 'd');
	if (game->perso.left == 1)
		rotate_player(game, 1);
	if (game->perso.right == 1)
		rotate_player(game, -1);
	return (1);
}

int	key_hook(int key, void *param)
{
	t_game	*game;

	game = param;
	if (key == 'w')
		game->perso.w = 1;
	if (key == 'a')
		game->perso.a = 1;
	if (key == 's')
		game->perso.s = 1;
	if (key == 'd')
		game->perso.d = 1;
	if (key == 65361)
		game->perso.left = 1;
	if (key == 65363)
		game->perso.right = 1;
	if (key == ESCAPE_KEY)
		exit_mlx(game);
	else if (key == 'm')
		game->minimap *= -1;
	return (1);
}

int	key_realese(int key, void *param)
{
	t_game	*game;

	game = param;
	if (key == 'w')
		game->perso.w = 0;
	if (key == 'a')
		game->perso.a = 0;
	if (key == 's')
		game->perso.s = 0;
	if (key == 'd')
		game->perso.d = 0;
	if (key == 65361)
		game->perso.left = 0;
	if (key == 65363)
		game->perso.right = 0;
	return (0);
}
