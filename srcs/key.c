/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:59:30 by gurodrig          #+#    #+#             */
/*   Updated: 2023/04/14 12:59:32 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	deal_key2(int key, t_fdf *map)
{
	if (key == KEY_LEFT)
		if (!rotate_camera(map, &rotation_x_matrix, -0.015))
			exit_app(map, 2);
	if (key == KEY_RIGHT)
		if (!rotate_camera(map, &rotation_x_matrix, 0.015))
			exit_app(map, 2);
	if (key == KEY_UP)
		if (!rotate_camera(map, &rotation_y_matrix, -0.015))
			exit_app(map, 2);
	if (key == KEY_DOWN)
		if (!rotate_camera(map, &rotation_y_matrix, 0.015))
			exit_app(map, 2);
	if (key == 'k')
		if (!rotate_camera(map, &rotation_z_matrix, -0.015))
			exit_app(map, 2);
	if (key == 'l')
		if (!rotate_camera(map, &rotation_z_matrix, 0.015))
			exit_app(map, 2);
	if (key == ESCAPE_KEY)
		exit_app(map, 0);
}

int	deal_key(int key, void *param)
{
	t_fdf	*map;

	map = param;
	if (key == 'a')
		map->cam->position->tab[0] = map->cam->position->tab[0] \
					- map->cam->speed;
	if (key == 'd')
		map->cam->position->tab[0] = map->cam->position->tab[0] \
					+ map->cam->speed;
	if (key == 'w')
		map->cam->position->tab[1] = map->cam->position->tab[1] \
					+ map->cam->speed;
	if (key == 's')
		map->cam->position->tab[1] = map->cam->position->tab[1] \
					- map->cam->speed;
	if (key == 'i')
		map->cam->position->tab[2] = map->cam->position->tab[2] \
					+ map->cam->speed;
	if (key == 'o')
		map->cam->position->tab[2] = map->cam->position->tab[2] \
					- map->cam->speed;
	deal_key2(key, map);
	render_screen(map);
	return (1);
}
