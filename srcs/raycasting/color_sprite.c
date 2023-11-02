/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:58:09 by astachni          #+#    #+#             */
/*   Updated: 2023/11/02 21:48:07 by astachni         ###   ########.fr       */
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

int	get_texture(t_game *game, char *texture, int i)
{
	if (!texture)
		return (0);
	game->sprite[i].img = mlx_xpm_file_to_image(game->mlx, texture, \
		&game->sprite[i].x, &game->sprite[i].y);
	if (!game->sprite[i].img)
		return (0);
	game->sprite[i].addr = (int *)mlx_get_data_addr(game->sprite[i].img, \
		&game->sprite[i].bits_per_pixel, &game->sprite[i].line_length, \
			&game->sprite[i].endian);
	return (1);
}

int	get_all_textures(t_game *game)
{
	if (!get_texture(game, game->map.path.no, 0))
		return (printf("fail to load no texture\n"), 0);
	else if (!get_texture(game, game->map.path.so, 1))
		return (printf("fail to lead so texture\n"), 0);
	else if (!get_texture(game, game->map.path.we, 2))
		return (printf("fail to lead we texture\n"), 0);
	else if (!get_texture(game, game->map.path.ea, 3))
		return (printf("fail to lead ea texture\n"), 0);
	return (1);
}
