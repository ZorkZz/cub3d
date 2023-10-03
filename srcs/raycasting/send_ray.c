/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 16:21:52 by astachni          #+#    #+#             */
/*   Updated: 2023/10/03 18:53:58 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"


//e.x = game->perso.x/10 + 40 * cos(game->perso.angle + (60) * M_PI / 180);
//e.y = game->perso.y/10 + 40 * sin(game->perso.angle + (60) * M_PI / 180);
//e.x = game->perso.x/10 + 40 * cos(game->perso.angle - (60) * M_PI / 180);
//e.y = game->perso.y/10 + 40 * sin(game->perso.angle - (60) * M_PI / 180);
void	set_ray(t_game *game)
{
	t_point	start_ray;

	start_ray.x = game->perso.x;
	start_ray.y = game->perso.y;
	game->color = 0x0BD09A7;
	printf("start_ray.x %f, start_ray.y %f\n", (float)start_ray.x / 100, (float)start_ray.y / 100);
	while (game->map.map[start_ray.x / 100][start_ray.y / 100] != '1')
	{
		if (game->debug)
			game_put_pixel(game, start_ray.x / 10, start_ray.y / 10);
		start_ray.x += 20 * cos(game->perso.angle);
		start_ray.y += 20 * sin(game->perso.angle);
		printf("start_ray.x %f, start_ray.y %f\n", (float)start_ray.x / 100, (float)start_ray.y / 100);
	}
}
