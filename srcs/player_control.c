/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zorkz <zorkz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:41:19 by astachni          #+#    #+#             */
/*   Updated: 2023/11/22 16:17:20 by zorkz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static void	forward_backward(t_game *game, char c);
static void	left_right(t_game *game, char c);

void	move_player(t_game *game, char c)
{
	forward_backward(game, c);
	left_right(game, c);
}

static void	left_right(t_game *game, char c)
{
	if (c == 'a')
	{
		if (can_moov(game->map.map, game->perso.x - (sin(game->perso.angle) * \
		MOVE_SPEED), game->perso.y + (cos(game->perso.angle) * MOVE_SPEED)))
		{
			game->perso.x -= sin(game->perso.angle) * MOVE_SPEED;
			game->perso.y += cos(game->perso.angle) * MOVE_SPEED;
		}
	}
	else if (c == 'd')
	{
		if (can_moov(game->map.map, game->perso.x + (sin(game->perso.angle) * \
		MOVE_SPEED), game->perso.y - (cos(game->perso.angle) * MOVE_SPEED)))
		{
			game->perso.x += sin(game->perso.angle) * MOVE_SPEED;
			game->perso.y -= cos(game->perso.angle) * MOVE_SPEED;
		}
	}
}

static void	forward_backward(t_game *game, char c)
{
	if (c == 'w')
	{
		if (can_moov(game->map.map, game->perso.x + (cos(game->perso.angle) * \
		MOVE_SPEED), game->perso.y + (sin(game->perso.angle) * MOVE_SPEED)))
		{
			game->perso.x += cos(game->perso.angle) * MOVE_SPEED;
			game->perso.y += sin(game->perso.angle) * MOVE_SPEED;
		}
	}
	else if (c == 's')
	{
		if (can_moov(game->map.map, game->perso.x - (cos(game->perso.angle) * \
		MOVE_SPEED), game->perso.y - (sin(game->perso.angle) * MOVE_SPEED)))
		{
			game->perso.x -= cos(game->perso.angle) * MOVE_SPEED;
			game->perso.y -= sin(game->perso.angle) * MOVE_SPEED;
		}
	}
}

void	rotate_player(t_game *game, int mult)
{
	game->perso.angle += ROTATION_SPEED * mult;
	while (game->perso.angle < 0)
		game->perso.angle += 2 * M_PI;
	while (game->perso.angle >= 2 * M_PI)
		game->perso.angle -= 2 * M_PI;
}
