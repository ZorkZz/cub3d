/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:31:22 by astachni          #+#    #+#             */
/*   Updated: 2023/11/06 11:31:24 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	free_images(t_game *game)
{
	if (game && game->mlx)
	{
		mlx_destroy_image(game->mlx, game->img.img);
		mlx_destroy_image(game->mlx, game->sprite[0].img);
		mlx_destroy_image(game->mlx, game->sprite[1].img);
		mlx_destroy_image(game->mlx, game->sprite[2].img);
		mlx_destroy_image(game->mlx, game->sprite[3].img);
	}
}
