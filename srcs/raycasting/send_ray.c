/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:52 by astachni          #+#    #+#             */
/*   Updated: 2023/10/04 15:02:05 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	left_ray(t_game *game);
static void	right_ray(t_game *game);

void	set_ray(t_game *game)
{
	game->color = 0x0BD09A7;
	left_ray(game);
	right_ray(game);
}

static void	right_ray(t_game *game)
{
	float	half_fov;
	float	x;
	float	y;

	half_fov = HALF_FOV;
	while (half_fov >= 0)
	{
		x = game->perso.x;
		y = game->perso.y;
		while (game->map.map[(int)x / 100][(int)y / 100] != '1')
		{
			if (game->debug)
				game_put_pixel(game, x / 10, y / 10);
			x += 1 * cos(game->perso.angle - half_fov);
			y += 1 * sin(game->perso.angle - half_fov);
		}
		half_fov -= 0.01;
	}
}

static void	left_ray(t_game *game)
{
	float	half_fov;
	float	x;
	float	y;

	half_fov = HALF_FOV;
	while (half_fov >= 0)
	{
		x = game->perso.x;
		y = game->perso.y;
		while (game->map.map[(int)x / 100][(int)y / 100] != '1')
		{
			if (game->debug)
				game_put_pixel(game, x / 10, y / 10);
			x += 1 * cos(game->perso.angle + half_fov);
			y += 1 * sin(game->perso.angle + half_fov);
		}
		half_fov -= 0.01;
	}
}
