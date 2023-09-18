#include "../headers/cub3d.h"

int	deal_key(int key, void *param)
{
	t_game	*game;

	game = param;
	if (key == 'w')
		move_player(game, 1, -1);
	if (key == 'a')
		move_player(game, 0, -1);
	if (key == 's')
		move_player(game, 1, 1);
	if (key == 'd')
		move_player(game, 0, 1);
	if (key == 'q')
		rotate_player(game, 1);
	if (key == 'e')
		rotate_player(game, -1);
	if (key == ESCAPE_KEY)
		exit_mlx(game);
	render_win(game);
	return (1);
}
