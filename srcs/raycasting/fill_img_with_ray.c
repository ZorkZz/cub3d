/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_img_with_ray.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:52 by astachni          #+#    #+#             */
/*   Updated: 2023/10/27 18:27:18 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	draw_collumn(t_game *game, float height, int x);

// static int	get_color(t_game *game, int x, int y)
// {
// 	printf("%d\n", game->sprite.addr[(y * game->sprite.line_length / 4) + x]);
// 	return (game->sprite.addr[(y * game->sprite.line_length / 4) + x]);
// }

void	change_wall_face(t_game *game, t_fpoint h, t_fpoint v, float cos_a, float sin_a)
{
	if (h.distance >= v.distance)
	{
		game->wall_face = 's';
		if (game->perso.x > h.x)
			game->wall_face = 'n';
		while (v.y > 1)
			v.y -= 1;
		game->offset = 1 - v.y;
		if (cos_a > 0)
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
		if (sin_a > 0)
			game->offset = 1 - h.x;
	}
}

void	choose_color(t_game *game, float y_ratio)
{
	if (game->wall_face == 's')
		game->color = 0x00000000;
	else if (game->wall_face == 'n')
		game->color = 0x00FFFFFF;
	else if (game->wall_face == 'e')
		game->color = 0x00850202;
	else if (game->wall_face == 'w')
		game->color = 0x00900285;
	int x = game->sprite.x * y_ratio;
	int y = game->sprite.y * game->offset;
	game->color = game->sprite.addr[x * game->sprite.x + y];
}

void	get_to_draw(t_game *game, float dist, int i)
{
	float	height;

	height = (((SCREEN_H - 1) / dist) * 1);
	draw_collumn(game, height, i);
}

static void	draw_collumn(t_game *game, float height, int x)
{
	int	y_start;
	int	y_end;
	int	y;

	y_start = ((SCREEN_H - 1) / 2) - (height / 2);
	y_end = y_start + height;
	if (y_start < 0)
		y_start = 0;
	if (y_end >= SCREEN_H)
		y_end = SCREEN_H - 1;
	y = 0;
	game->color = game->map.color.c_int;
	while (y < y_start && y <= SCREEN_H - 1)
		game_put_pixel(game, y++, x);
	while (y_start < y_end)
	{
		choose_color(game, (float)(y_start - y) / (float)(y_end - y));
		game_put_pixel(game, y_start++, x);
	}
	game->color = game->map.color.f_int;
	while (y_start < SCREEN_H - 1 && y_start >= 0)
		game_put_pixel(game, y_start++, x);
}
