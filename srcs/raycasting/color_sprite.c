/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:58:09 by astachni          #+#    #+#             */
/*   Updated: 2023/10/27 17:07:27 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	get_texture(t_game *game)
{
	//malloc secur a faire et cest un test avec juste 1 texture
	game->sprite.img = mlx_xpm_file_to_image(game->mlx, "./imgs/wall_test.xpm", \
		&game->sprite.x, &game->sprite.x);
	game->sprite.addr = (int *)mlx_get_data_addr(game->mlx, \
		&game->sprite.bits_per_pixel, &game->sprite.line_length, \
			&game->sprite.endian);
	return (0);
}
