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

void print_rbg2(int c)
{
        int r = c >> 16;
        int g = ((c << 16) >> 16) >> 8;
        int b = ((c << 24) >> 24);
        printf("r : %d, g : %d, b : %d\n", r, g, b);
}

int	get_texture(t_game *game)
{
//	char *texture = "./imgs/wallgradient2.xpm";
	char *texture = "./imgs/wall_test.xpm";
	//malloc secur a faire et cest un test avec juste 1 texture
	game->sprite.img = mlx_xpm_file_to_image(game->mlx, texture, \
		&game->sprite.x, &game->sprite.y);
	game->sprite.addr = (int *)mlx_get_data_addr(game->sprite.img, \
		&game->sprite.bits_per_pixel, &game->sprite.line_length, \
			&game->sprite.endian);
	return (0);
}
