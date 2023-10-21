/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:52 by astachni          #+#    #+#             */
/*   Updated: 2023/10/16 19:30:34 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	get_to_draw(t_game *game, t_fpoint point, int i, float correction);
static void	draw_collumn(t_game *game, t_fpoint point, int i);
static void	set_many_rays(t_fpoint *point, t_game *game, float fov);

void	set_ray(t_game *game)
{
	float		fov;
	t_fpoint	point;
	int			x;
	float		angle_incr;

	x = SCREEN_W;
	fov = HALF_FOV;
	angle_incr = HALF_FOV / NUM_RAYS;
	while (--x >= 0)
	{
		point.x = game->perso.x * 100;
		point.y = game->perso.y * 100;
		while (game->map.map[(int)point.x / 100][(int)point.y / 100] != '1')
		{
			if (game->debug)
			{
				game->color = 0x0BD09A7;
				game_put_pixel(game, point.x / 10, point.y / 10);
			}
			point.x += 8 * cos(game->perso.angle - fov);
			point.y += 8 * sin(game->perso.angle - fov);
		}
		set_many_rays(&point, game, fov);
		get_to_draw(game, point, x, fov);
		fov -= angle_incr;
	}
}

static void	set_many_rays(t_fpoint *point, t_game *game, float fov)
{
	point->x -= 8 * cos(game->perso.angle - fov);
	point->y -= 8 * sin(game->perso.angle - fov);
	while (game->map.map[(int)point->x / 100][(int)point->y / 100] != '1')
	{
		point->x += 1 * cos(game->perso.angle - fov) / 128;
		if (game->map.map[(int)point->x / 100][(int)point->y / 100] != '1')
			game->color = 0x0FFFFFF;
		else
			game->color = 0x0797979;
		point->y += 1 * sin(game->perso.angle - fov) / 128;
	}
}

static void	get_to_draw(t_game *game, t_fpoint point, int i, float correction)
{
	float	dist_x;
	float	dist_y;

	(void)correction;
	dist_x = pow((point.x - game->perso.x), 2);
	dist_y = pow((point.y - game->perso.y), 2);
	point.distance = sqrt(dist_x * dist_x + dist_y * dist_y);
	// point.distance += cos(game->perso.angle - correction);
	point.height = (((SCREEN_H - 1) / point.distance) * 5000 + 200);
	draw_collumn(game, point, i);
}

static void	draw_collumn(t_game *game, t_fpoint point, int x)
{
	int	y_start;
	int	y_end;
	//int	y;

	y_start = ((SCREEN_H - 1) / 2) - (point.height / 2);
	y_end = y_start + point.height;
	//y = 0;
	// game->color = 0x0000743;
	// while (y < y_start && y <= SCREEN_H - 1)
	// 	game_put_pixel(game, y++, x);
	while (y_start < y_end)
	{
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
	game->color = 0x0430000;
	while (y_start < SCREEN_H - 1 && y_start >= 0)
		game_put_pixel(game, y_start++, x);
}
