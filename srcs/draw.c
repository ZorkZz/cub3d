#include "../headers/cub3d.h"

void draw(t_game *game)
{
	draw_minimap(game);
}

void	draw_minimap(t_game *game)
{
	size_t	i;
	size_t	j;

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
	//commentaires changer quand le player sera parse
	//printf("%ld, %ld\n", game->perso.x, game->perso.y);
	//draw_rectangle(game, game->perso.x, game->perso.y, 5, 5);
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
	game->img.addr[x * SCREEN_W + y] = 0x00FFFFFF;
}
