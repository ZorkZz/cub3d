/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorkz <zorkz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 14:35:29 by astachni          #+#    #+#             */
/*   Updated: 2023/11/22 14:38:44 by zorkz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	raycast(t_game *game)
{
	float			ray_angle;
	float			depth;
	float			delta_angle;
	float			num_rays;
	unsigned int	x;

	x = SCREEN_W;
	num_rays = SCREEN_W + 1;
	ray_angle = game->perso.angle - HALF_FOV + 0.0001;
	delta_angle = FOV / (num_rays - 1.0);
	while (x-- > 0)
	{
		depth = ray_depth(game, ray_angle);
		depth *= cos(game->perso.angle - ray_angle);
		get_to_draw(game, depth, x);
		ray_angle += delta_angle;
	}
}

float	ray_depth(t_game *game, float ray_angle)
{
	t_fpoint	h;
	t_fpoint	v;
	t_fpoint	cos_sin;
	float		cos_a;
	float		sin_a;

	cos_a = cos(ray_angle);
	sin_a = sin(ray_angle);
	h = horizontal_depth(game, cos_a, sin_a);
	v = vertical_depth(game, cos_a, sin_a);
	cos_sin.x = cos_a;
	cos_sin.y = sin_a;
	change_wall_face(game, h, v, cos_sin);
	if (h.distance > v.distance)
		return (v.distance);
	return (h.distance);
}

t_fpoint	horizontal_depth(t_game *game, float cos_a, float sin_a)
{
	t_fpoint	d;
	t_fpoint	ray;
	float		delta_depth;

	ray.y = ((int)game->perso.y) - 0.0001;
	d.y = -1;
	if (sin_a > 0)
	{
		ray.y = ((int)game->perso.y) + 1;
		d.y = 1;
	}
	ray.distance = (ray.y - game->perso.y) / sin_a;
	ray.x = game->perso.x + ray.distance * cos_a;
	delta_depth = d.y / sin_a;
	d.x = delta_depth * cos_a;
	while (!is_wall(game, ray.x, ray.y))
	{
		ray.x += d.x;
		ray.y += d.y;
		ray.distance += delta_depth;
	}
	return (ray);
}

t_fpoint	vertical_depth(t_game *game, float cos_a, float sin_a)
{
	t_fpoint		d;
	t_fpoint		ray;
	float			delta_depth;

	ray.x = ((int)game->perso.x) - 0.0001;
	d.x = -1;
	if (cos_a > 0)
	{
		ray.x = ((int)game->perso.x) + 1;
		d.x = 1;
	}
	ray.distance = (ray.x - game->perso.x) / cos_a;
	ray.y = game->perso.y + ray.distance * sin_a;
	delta_depth = d.x / cos_a;
	d.y = delta_depth * sin_a;
	while (!is_wall(game, ray.x, ray.y))
	{
		ray.x += d.x;
		ray.y += d.y;
		ray.distance += delta_depth;
	}
	return (ray);
}
