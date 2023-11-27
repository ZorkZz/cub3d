/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ratio_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:13:49 by astachni          #+#    #+#             */
/*   Updated: 2023/11/27 12:34:16 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	get_ratio_map(t_game *game)
{
	t_point	point;
	t_point	point_screen;
	int		i;

	point.y = 0;
	i = 0;
	while (game->map.map && game->map.map[point.y])
	{
		point.x = 0;
		while (game->map.map[point.y] && game->map.map[point.y][point.x])
			point.x++;
		if (i < point.x)
			i = point.x;
		point.y++;
	}
	point.x = i;
	point_screen.x = SCREEN_H / point.x;
	point_screen.y = SCREEN_W / point.y;
	if (point_screen.y > point_screen.x)
		game->ratio_map = point_screen.x;
	else
		game->ratio_map = point_screen.y;
	game->ratio_map /= 4;
}
