#include "../headers/cub3d.h"

void move_player(t_game *game, char c)
{
	if (c == 'w')
	{
		game->perso.x += cos(game->perso.angle) * MOVE_SPEED;
		game->perso.y += sin(game->perso.angle) * MOVE_SPEED;
	}
	if (c == 's')
	{
		game->perso.x -= cos(game->perso.angle) * MOVE_SPEED;
		game->perso.y -= sin(game->perso.angle) * MOVE_SPEED;
	}
	if (c == 'a')
	{
		game->perso.x += sin(game->perso.angle) * MOVE_SPEED;
		game->perso.y -= cos(game->perso.angle) * MOVE_SPEED;
	}
	if (c == 'd')
	{
		game->perso.x -= sin(game->perso.angle) * MOVE_SPEED;
		game->perso.y += cos(game->perso.angle) * MOVE_SPEED;
	}
}

void rotate_player(t_game *game, int mult)
{
	game->perso.angle += ROTATION_SPEED * mult;
	while (game->perso.angle < 0)
		game->perso.angle += 2 * M_PI;
	while (game->perso.angle >= 2 * M_PI)
		game->perso.angle -= 2 * M_PI;
}
