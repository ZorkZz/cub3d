#include "../headers/cub3d.h"

int	deal_key(int key, void *param)
{
	t_game	*game;

	game = param;
	if (key == 'w')
		move_player(game, 'w');
	if (key == 'a')
		move_player(game, 'a');
	if (key == 's')
		move_player(game, 's');
	if (key == 'd')
		move_player(game, 'd');
	if (key == 'q')
		rotate_player(game, 1);
	if (key == 'e')
		rotate_player(game, -1);
	if (key == ESCAPE_KEY)
		exit_mlx(game);
	if (key == 'p' && game->debug == 1)
		game->debug = 0;
	else if (key == 'p')
		game->debug = 1;
	render_win(game);
	return (1);
}
