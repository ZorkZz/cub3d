/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:50:45 by astachni          #+#    #+#             */
/*   Updated: 2023/11/03 15:28:50 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	free_parsing(t_game game, char **strs)
{
	if (game.sprite[0].assign == 1 || game.sprite[1].assign == 1 || \
		game.sprite[2].assign == 1 || game.sprite[3].assign == 1)
		printf("MAP ERROR\n");
	free_sprite(game);
	free_color(game.map.color);
	free_path(game.map.path);
	free_strs(game.map.map);
	free_strs(strs);
	if (game.mlx && game.win)
	{
		mlx_destroy_image(game.mlx, game.img.img);
		mlx_destroy_window(game.mlx, game.win);
	}
	if (game.mlx)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}
}
