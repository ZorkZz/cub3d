/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img_with_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:52 by astachni          #+#    #+#             */
/*   Updated: 2023/10/27 17:41:40 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	draw_collumn(t_game *game, float height, int x);

void	choose_color(t_game *game, t_fpoint h, t_fpoint v)
{
	if (h.distance >= v.distance)
	{
		game->color = 0x000000;
		if (game->perso.x > h.x)
			game->color = 0x0FFFFFF;
	}
	else
	{
		game->color = 0x0850202;
		if (game->perso.y > v.y)
			game->color = 0x0090285;
	}
}

void	get_to_draw(t_game *game, float dist, int i)
{
	float	height;

	height = (((SCREEN_H - 1) / dist) * 1);
	draw_collumn(game, height, i);
}

// static int	get_color(t_game *game, int x, int y)
// {
// 	printf("%d\n", game->sprite.addr[(y * game->sprite.line_length / 4) + x]);
// 	return (game->sprite.addr[(y * game->sprite.line_length / 4) + x]);
// }

static void	draw_collumn(t_game *game, float height, int x)
{
	int	y_start;
	int	y_end;
	int	y;
	int	wall_color;

	wall_color = game->color;
	y_start = ((SCREEN_H - 1) / 2) - (height / 2);
	y_end = y_start + height;
	y = 0;
	game->color = game->map.color.c_int;
	while (y < y_start && y <= SCREEN_H - 1)
		game_put_pixel(game, y++, x);
	while (y_start < y_end)
	{
		game->color = wall_color;
		if (y_start < 0)
			y_start = 0;
		if (y_start >= SCREEN_H - 1)
			y_start = SCREEN_H - 1;
		if (x < 0)
			x = 0;
		if (x >= SCREEN_W - 1)
			x = SCREEN_W - 1;
		game_put_pixel(game, y_start, x);
		if (y_end >= SCREEN_H - 1 && y_start == SCREEN_H - 1)
			return ;
		y_start++;
	}
	game->color = game->map.color.f_int;
	while (y_start < SCREEN_H - 1 && y_start >= 0)
		game_put_pixel(game, y_start++, x);
}