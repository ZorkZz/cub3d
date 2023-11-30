/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 10:47:38 by astachni          #+#    #+#             */
/*   Updated: 2023/11/21 14:14:30 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

void	draw(t_game *game);

int	init_win(t_game *game)
{
	if (SCREEN_H > 5000 || SCREEN_W > 5000 || SCREEN_H == 0 || SCREEN_W == 0)
		return (ft_putstr_fd("screen size not supported\n", 2), 1);
	game->mlx = mlx_init();
	if (!game->mlx)
		return (1);
	game->win = mlx_new_window(game->mlx, SCREEN_W, SCREEN_H, "cub3d");
	if (!game->win)
		return (exit_mlx(game), 1);
	game->img.img = mlx_new_image(game->mlx, SCREEN_W, SCREEN_H);
	return (0);
}

int	render_win(void *param)
{
	t_game	*game;

	game = param;
	deal_key(game);
	game->img.addr = (int *)mlx_get_data_addr(game->img.img, \
			&game->img.bits_per_pixel, \
			&game->img.line_length, &game->img.endian);
	raycast(game);
	if (game->minimap == 1)
		draw(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.img, 0, 0);
	return (1);
}

int	exit_mlx(void *arg)
{
	t_game	*game;

	game = arg;
	exit_win(game, 0);
	return (1);
}

int	exit_win(t_game *game, int error)
{
	free_color(game->map.color);
	free_path(game->map.path);
	free_strs(game->map.map);
	free_images(game);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
		mlx_destroy_display(game->mlx);
	free(game->mlx);
	return (exit(error), 1);
}

void	init_keys(t_game *game)
{
	mlx_hook(game->win, 2, 1L << 0, key_hook, game);
	mlx_hook(game->win, 3, 1L << 1, key_realese, game);
	mlx_hook(game->win, 17, 1L >> 17, exit_mlx, game);
	mlx_loop_hook(game->mlx, render_win, game);
	mlx_loop(game->mlx);
}
