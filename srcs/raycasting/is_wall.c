/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_wall.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:30:18 by astachni          #+#    #+#             */
/*   Updated: 2023/11/27 11:30:18 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	_is_wall(t_game *game, float fx, float fy)
{
	ssize_t	x;
	ssize_t	y;

	x = fx;
	y = fy;
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (1);
	return (game->map.map[x][y] == '1' || game->map.map[x][y] == ' ');
}

int	is_wall(t_game *game, float fx, float fy)
{
	return (_is_wall(game, fx + 0.000001, fy + 0.0000001)
		|| _is_wall(game, fx + 0.000001, fy - 0.0000001)
		|| _is_wall(game, fx - 0.000001, fy + 0.0000001)
		|| _is_wall(game, fx - 0.000001, fy - 0.0000001));
}
