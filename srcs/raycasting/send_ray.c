/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:52 by astachni          #+#    #+#             */
/*   Updated: 2023/10/04 22:17:39 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	left_ray(t_game *game);
static void	right_ray(t_game *game);
static void	get_to_draw(t_game *game, t_fpoint point);
static void	draw_collumn(t_game *game, t_fpoint point);

void	set_ray(t_game *game)
{
	left_ray(game);
	right_ray(game);
}

static void	right_ray(t_game *game)
{
	float		half_fov;
	t_fpoint	point;

	half_fov = HALF_FOV;
	while (half_fov >= 0)
	{
		point.x = game->perso.x;
		point.y = game->perso.y;
		while (game->map.map[(int)point.x / 100][(int)point.y / 100] != '1')
		{
			if (game->debug)
			{
				game->color = 0x0BD09A7;
				game_put_pixel(game, point.x / 10, point.y / 10);
			}
			point.x += 1 * cos(game->perso.angle - half_fov);
			point.y += 1 * sin(game->perso.angle - half_fov);
		}
		if (game->map.map[(int)point.x / 100][(int)point.y / 100] == '1')
		{
			game->color = 0x0FFFFFF;
			get_to_draw(game, point);
		}
		half_fov -= 0.01;
	}
}

static void	left_ray(t_game *game)
{
	float		half_fov;
	t_fpoint	point;

	half_fov = HALF_FOV;
	while (half_fov >= 0)
	{
		point.x = game->perso.x;
		point.y = game->perso.y;
		while (game->map.map[(int)point.x / 100][(int)point.y / 100] != '1')
		{
			if (game->debug)
			{
				game->color = 0x0BD09A7;
				game_put_pixel(game, point.x / 10, point.y / 10);
			}
			point.x += 1 * cos(game->perso.angle + half_fov);
			point.y += 1 * sin(game->perso.angle + half_fov);
		}
		if (game->map.map[(int)point.x / 100][(int)point.y / 100] == '1')
		{
			game->color = 0x0FFFFFF;
			get_to_draw(game, point);
		}
		half_fov -= 0.01;
	}
}

static void	get_to_draw(t_game *game, t_fpoint point)
{
	float	dist_x;
	float	dist_y;

	if (point.x > game->perso.x)
		dist_x = pow((point.x - game->perso.x) / 10, 2);
	else
		dist_x = pow((game->perso.x - point.x) / 10, 2);
	if (point.y > game->perso.y)
		dist_y = pow((point.y - game->perso.y) / 10, 2);
	else
		dist_y = pow((game->perso.y - point.y) / 10, 2);
	point.distance = sqrt(dist_x * dist_x + dist_y * dist_y);
	//point.distance *= cos(game->perso.angle - atan2(dist_y, dist_x));
	point.height = (point.distance * 5);
	draw_collumn(game, point);
}

static void	draw_collumn(t_game *game, t_fpoint point)
{
	int	y_start;
	int	y_end;

	y_start = (SCREEN_H - point.height) / 2;
	y_end = y_start + point.height * 2;
	while (y_start < y_end)
	{
		if (y_start < 0)
			y_start = 0;
		game_put_pixel(game, point.x / 10, y_start);
		y_start++;
	}
}
