/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:50:45 by astachni          #+#    #+#             */
/*   Updated: 2023/11/30 13:01:53 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	free_parsing(t_game game, char **strs)
{
	if (game.sprite[0].assign == 0 && game.sprite[1].assign == 0 && \
		game.sprite[2].assign == 0 && game.sprite[3].assign == 0)
		printf("MAP ERROR\n");
	error_code(game);
	free_sprite(game);
	free_color(game.map.color);
	free_path(game.map.path);
	free_strs(game.map.map);
	free_strs(strs);
	if (game.mlx && game.win)
	{
		if (game.img.img)
			mlx_destroy_image(game.mlx, game.img.img);
		mlx_destroy_window(game.mlx, game.win);
	}
	if (game.mlx)
	{
		mlx_destroy_display(game.mlx);
		free(game.mlx);
	}
}

void	error_code(t_game game)
{
	if (game.error == 1)
		printf("ISLAND IN MAP\n");
	else if (game.error == 2)
		printf("NO PLAYER\n");
	else if (game.error == 3)
		printf("BAD MAP EXTENTION\n");
	else if (game.error == 4)
		printf("BAD COLOR\n");
	else if (game.error == 5)
		printf("SPRITE ERROR\n");
}
