#include "../headers/cub3d.h"

void draw(t_game *game)
{
	draw_minimap(game);
}

void	draw_minimap(t_game *game)
{
	size_t	i;
	size_t	j;
	t_point	s;
	t_point	e;

	game->color = 0x00FFFFFF;
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '1')
				draw_rectangle(game, i * 10, j * 10, 10, 10);
			j++;
		}
		i++;
	}
	game->color = 0x0000FFFF;
	draw_rectangle(game, game->perso.x/10, game->perso.y/10, 5, 5);
	s.x = game->perso.x/10;
	s.y = game->perso.y/10;
	e.x = game->perso.x/10 + 40 * cos(game->perso.angle);
	e.y = game->perso.y/10 + 40 * sin(game->perso.angle);
	draw_line(game, s, e);
}

void	draw_rectangle(t_game *game, int x, int y, int w, int h)
{
	int	i;
	int	j;

	i = 0;
	while (i < w)
	{
		j = 0;
		while (j < h)
		{
			game_put_pixel(game, i + x, j + y);
			j++;
		}
		i++;
	}
}

void	game_put_pixel(t_game *game, int x, int y)
{
	game->img.addr[x * SCREEN_W + y] = game->color;
}
