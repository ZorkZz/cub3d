/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:05:22 by astachni          #+#    #+#             */
/*   Updated: 2023/10/27 16:59:41 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int ac, char **av, char **envp)
{
	t_game	game;
	ssize_t	i;

	(void) av;
	game.debug = 0;
	if (ac != 2 || !*envp)
		return (EXIT_FAILURE);
	if (map_parsing(av[1], &game) != 0)
		return (EXIT_FAILURE);
	i = 0;
	while (game.map.map && game.map.map[i])
		printf("%s\n", game.map.map[i++]);
	printf("x: %f, y: %f, %f°3\n", game.perso.x, game.perso.y, game.perso.angle);
	if (init_win(&game) == 1)
		return (1);
	get_texture(&game);
	render_win(&game);
	mlx_hook(game.win, 2, 1L >> 0, deal_key, &game);
	mlx_hook(game.win, 17, 1L >> 17, exit_mlx, &game);
	mlx_loop(game.mlx);
	return (free_color(game.map.color),free_path(game.map.path), free_strs(game.map.map), EXIT_SUCCESS);
}
