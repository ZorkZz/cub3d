/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:49:23 by astachni          #+#    #+#             */
/*   Updated: 2023/11/16 11:29:02 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	draw(t_game *game)
{
	draw_minimap(game);
}

void	draw_player_vision(t_game *game)
{
	t_point	s;
	t_point	e;

	game->color = 0x0000FFFF;
	s.x = game->perso.x * 10;
	s.y = game->perso.y * 10;
	e.x = game->perso.x * 10 + 10 * cos(game->perso.angle);
	if (e.x < 0)
		e.x = 0;
	if (e.x >= SCREEN_W)
		e.x = SCREEN_W - 1;
	e.y = game->perso.y * 10 + 10 * sin(game->perso.angle);
	if (e.y < 0)
		e.y = 0;
	if (e.y >= SCREEN_H)
		e.y = SCREEN_H - 1;
	draw_line(game, s, e);
}

void	draw_minimap(t_game *game)
{
	size_t	i;
	size_t	j;

	game->color = 0x0000FFFF;
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j])
		{
			if (game->map.map[i][j] == '1')
				draw_rectangle(game, i * 10, j * 10);
			j++;
		}
		i++;
	}
	draw_player_vision(game);
}

void	draw_rectangle(t_game *game, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 10)
		{
			game_put_pixel(game, j + y, i + x);
			j++;
		}
		i++;
	}
}

void	game_put_pixel(t_game *game, int x, int y)
{
	game->img.addr[y * SCREEN_W + x] = game->color;
}
