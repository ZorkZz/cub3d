/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:52 by astachni          #+#    #+#             */
/*   Updated: 2023/10/05 22:03:38 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	get_to_draw(t_game *game, t_fpoint point, int i);
static void	draw_collumn(t_game *game, t_fpoint point, int i);


void	set_ray(t_game *game)
{
	float		fov;
	t_fpoint	point;
	int			x;
	float		angle_incr;

	x = SCREEN_W;
	fov = FOV;
	angle_incr = FOV / NUM_RAYS;
	while (--x >= 0)
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
			point.x += 1 * cos(game->perso.angle - fov);
			point.y += 1 * sin(game->perso.angle - fov);
		}
		game->color = 0x0FFFFFF;
		get_to_draw(game, point, x);
		fov -= angle_incr;
	}
}

static void	get_to_draw(t_game *game, t_fpoint point, int i)
{
	float	dist_x;
	float	dist_y;

	if (point.x > game->perso.x)
		dist_x = pow((point.x - game->perso.x), 2);
	else
		dist_x = pow((game->perso.x - point.x), 2);
	if (point.y > game->perso.y)
		dist_y = pow((point.y - game->perso.y), 2);
	else
		dist_y = pow((game->perso.y - point.y), 2);
	point.distance = sqrt(dist_x * dist_x + dist_y * dist_y);
	point.height = (((SCREEN_H - 1) / point.distance) * 10000) + 50;
	draw_collumn(game, point, i);
}

static void	draw_collumn(t_game *game, t_fpoint point, int x)
{
	int	y_start;
	int	y_end;

	y_start = ((SCREEN_H - 1) / 2) - (point.height / 2);
	y_end = y_start + point.height;
	while (y_start < y_end)
	{
		if (y_start < 0 || y_start >= SCREEN_H - 1)
			return ;
		if (x < 0 || x >= SCREEN_W - 1)
			return ;
		game_put_pixel(game, x, y_start);
		y_start++;
	}
}
