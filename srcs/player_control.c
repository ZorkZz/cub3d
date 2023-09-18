#include "../headers/cub3d.h"

void	move_player(t_game *game, char c)
{
	if (c == 'w')
	{
		if (game->map.map[(int)(game->perso.x  + cos(game->perso.angle) * MOVE_SPEED) / 100][(int)(game->perso.y + sin(game->perso.angle) * MOVE_SPEED) / 100] != '1')
		{
			game->perso.x += cos(game->perso.angle) * MOVE_SPEED;
			game->perso.y += sin(game->perso.angle) * MOVE_SPEED;
		}
	}
	else if (c == 's')
	{
		if ((game->map.map[(int)(game->perso.x  - cos(game->perso.angle) * MOVE_SPEED) / 100][(int)(game->perso.y - sin(game->perso.angle) * MOVE_SPEED) / 100] != '1'))
		{
			game->perso.x -= cos(game->perso.angle) * MOVE_SPEED;
			game->perso.y -= sin(game->perso.angle) * MOVE_SPEED;
		}
	}
	else if (c == 'a')
	{
		if (game->map.map[(int)(game->perso.x - sin(game->perso.angle) * MOVE_SPEED) / 100][(int)(game->perso.y + cos(game->perso.angle) * MOVE_SPEED) / 100] != '1')
		{
			game->perso.x -= sin(game->perso.angle) * MOVE_SPEED;
			game->perso.y += cos(game->perso.angle) * MOVE_SPEED;
		}
	}
	else if (c == 'd')
	{
		if (game->map.map[(int)(game->perso.x + sin(game->perso.angle) * MOVE_SPEED) / 100][(int)(game->perso.y - cos(game->perso.angle) * MOVE_SPEED) / 100] != '1')
		{
			game->perso.x += sin(game->perso.angle) * MOVE_SPEED;
			game->perso.y -= cos(game->perso.angle) * MOVE_SPEED;
		}
	}
}

void	rotate_player(t_game *game, int mult)
{
	game->perso.angle += ROTATION_SPEED * mult;
	while (game->perso.angle < 0)
		game->perso.angle += 2 * M_PI;
	while (game->perso.angle >= 2 * M_PI)
		game->perso.angle -= 2 * M_PI;
}
