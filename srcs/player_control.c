/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_control.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:41:19 by astachni          #+#    #+#             */
/*   Updated: 2023/11/06 10:46:41 by astachni         ###   ########.fr       */
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
		if (game->map.map[(int)(game->perso.x - sin(game->perso.angle)
				* MOVE_SPEED)][(int)(game->perso.y + cos(game->perso.angle)
				* MOVE_SPEED)] != '1' && (game->map.map[(int)(game->perso.x
				- sin(game->perso.angle) * MOVE_SPEED)][(int)(game->perso.y
				+ cos(game->perso.angle) * MOVE_SPEED)] != '\0'))
		{
			game->perso.x -= sin(game->perso.angle) * MOVE_SPEED;
			game->perso.y += cos(game->perso.angle) * MOVE_SPEED;
		}
	}
	else if (c == 'd')
	{
		if (game->map.map[(int)(game->perso.x + sin(game->perso.angle)
				* MOVE_SPEED)][(int)(game->perso.y - cos(game->perso.angle)
				* MOVE_SPEED)] != '1' && game->map.map[(int)(game->perso.x
				+ sin(game->perso.angle) * MOVE_SPEED)][(int)(game->perso.y
				- cos(game->perso.angle) * MOVE_SPEED)] != '\0')
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
		if (game->map.map[(int)(game->perso.x + cos(game->perso.angle)
				* MOVE_SPEED)][(int)(game->perso.y + sin(game->perso.angle)
				* MOVE_SPEED)] != '1' && game->map.map[(int)(game->perso.x
				+ cos(game->perso.angle) * MOVE_SPEED)][(int)(game->perso.y
				+ sin(game->perso.angle) * MOVE_SPEED)] != '\0')
		{
			game->perso.x += cos(game->perso.angle) * MOVE_SPEED;
			game->perso.y += sin(game->perso.angle) * MOVE_SPEED;
		}
	}
	else if (c == 's')
	{
		if ((game->map.map[(int)(game->perso.x - cos(game->perso.angle)
					* MOVE_SPEED)][(int)(game->perso.y - sin(game->perso.angle)
			* MOVE_SPEED)] != '1') && game->map.map[(int)(game->perso.x
				- cos(game->perso.angle) * MOVE_SPEED)][(int)(game->perso.y
				- sin(game->perso.angle) * MOVE_SPEED)] != '\0')
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
