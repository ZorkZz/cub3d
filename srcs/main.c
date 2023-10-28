/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:05:22 by astachni          #+#    #+#             */
/*   Updated: 2023/10/28 21:07:00 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int ac, char **av, char **envp)
{
	t_game	game;

	(void) av;
	game.debug = 0;
	if (ac != 2 || !*envp)
		return (EXIT_FAILURE);
	if (map_parsing(av[1], &game) != 0)
		return (EXIT_FAILURE);
	if (init_win(&game) == 1)
		return (1);
	if (!get_all_textures(&game))
		return (EXIT_FAILURE);
	render_win(&game);
	mlx_hook(game.win, 2, 1L >> 0, deal_key, &game);
	mlx_hook(game.win, 17, 1L >> 17, exit_mlx, &game);
	mlx_loop(game.mlx);
	return (free_color(game.map.color),free_path(game.map.path), free_strs(game.map.map), EXIT_SUCCESS);
}
