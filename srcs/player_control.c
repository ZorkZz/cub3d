#include "../headers/cub3d.h"

void move_player(t_game *game, int axis, int mult)
{
	if (axis == 1)
		game->perso.x += MOVE_SPEED * mult;
	else
		game->perso.y += MOVE_SPEED * mult;
}

void rotate_player(t_game *game, int mult)
{
	game->perso.angle += ROTATION_SPEED * mult;
	while (game->perso.angle < 0)
		game->perso.angle += 2 * M_PI;
	while (game->perso.angle >= 2 * M_PI)
		game->perso.angle -= 2 * M_PI;
}
