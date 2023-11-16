/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img_with_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:52 by astachni          #+#    #+#             */
/*   Updated: 2023/11/16 11:19:13 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	draw_collumn(t_game *game, float height, int x);
static void	put_pixel_column(t_game *game, int x, int y_start, int y_end);

void	change_wall_face(t_game *game, t_fpoint h, t_fpoint v, t_fpoint cos_sin)
{
	if (h.distance >= v.distance)
	{
		game->wall_face = 's';
		if (game->perso.x > h.x)
			game->wall_face = 'n';
		while (v.y > 1)
			v.y -= 1;
		game->offset = 1 - v.y;
		if (cos_sin.x > 0)
			game->offset = v.y;
	}
	else
	{
		game->wall_face = 'e';
		if (game->perso.y > v.y)
			game->wall_face = 'w';
		while (h.x > 1)
			h.x -= 1;
		game->offset = h.x;
		if (cos_sin.y > 0)
			game->offset = 1 - h.x;
	}
}

void	choose_color(t_game *game, float y_ratio)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	if (game->wall_face == 's')
		i = 0;
	else if (game->wall_face == 'n')
		i = 1;
	else if (game->wall_face == 'e')
		i = 2;
	else if (game->wall_face == 'w')
		i = 3;
	x = game->sprite[i].x * y_ratio;
	y = game->sprite[i].y * game->offset;
	game->color = game->sprite[i].addr[x * game->sprite[i].x + y];
}

void	get_to_draw(t_game *game, float dist, int i)
{
	float	height;

	height = (((SCREEN_H - 1) / dist)) * 1.3;
	draw_collumn(game, height, i);
}

static void	draw_collumn(t_game *game, float height, int x)
{
	int	y_start;
	int	y_end;

	y_start = ((SCREEN_H - 1) * 0.5) - (height * 0.5);
	y_end = y_start + height;
	put_pixel_column(game, x, y_start, y_end);
}

static void	put_pixel_column(t_game *game, int x, int y_start, int y_end)
{
	int	y;

	y = 0;
	game->color = game->map.color.c_int;
	while (y < y_start && y <= SCREEN_H - 1)
		game_put_pixel(game, x, y++);
	while (y < y_end && y <= SCREEN_H - 1)
	{
		choose_color(game, (float)(y - y_start) / (float)(y_end - y_start));
		game_put_pixel(game, x, y++);
	}
	game->color = game->map.color.f_int;
	while (y < SCREEN_H - 1)
		game_put_pixel(game, x, y++);
}
