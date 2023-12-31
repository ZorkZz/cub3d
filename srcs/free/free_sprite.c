/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 15:17:44 by astachni          #+#    #+#             */
/*   Updated: 2023/11/08 13:05:34 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
#include <stdio.h>

void	free_sprite(t_game game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (game.sprite[i].assign == 1 && game.sprite[i].img)
			mlx_destroy_image(game.mlx, game.sprite[i].img);
		i++;
	}
}
