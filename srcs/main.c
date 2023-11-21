/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:05:22 by astachni          #+#    #+#             */
/*   Updated: 2023/11/21 12:34:47 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static t_game	init_game(void);

int	main(int ac, char **av, char **envp)
{
	t_game	game;

	(void) av;
	game = init_game();
	if (ac != 2 || !*envp)
		return (EXIT_FAILURE);
	if (map_parsing(av[1], &game) != 0)
		return (EXIT_FAILURE);
	if (init_win(&game) == 1)
		return (1);
	if (!get_all_textures(&game))
		return (free_parsing(game, NULL), EXIT_FAILURE);
	render_win(&game);
	mlx_hook(game.win, 2, 1L << 0, key_hook, &game);
	mlx_hook(game.win, 3, 1L << 1, key_realese, &game);
	mlx_hook(game.win, 17, 1L >> 17, exit_mlx, &game);
	mlx_loop_hook(game.mlx, render_win, &game);
	mlx_loop(game.mlx);
	free_color(game.map.color);
	free_path(game.map.path);
	free_strs(game.map.map);
	return (EXIT_SUCCESS);
}

static t_game	init_game(void)
{
	t_game	game;

	game.minimap = -1;
	game.error = 0;
	game.mlx = NULL;
	game.img.img = NULL;
	game.win = NULL;
	game.sprite[0].img = NULL;
	game.sprite[1].img = NULL;
	game.sprite[2].img = NULL;
	game.sprite[3].img = NULL;
	return (game);
}
