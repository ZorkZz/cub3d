/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:05:22 by astachni          #+#    #+#             */
/*   Updated: 2023/09/17 17:48:01 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int ac, char **av, char **envp)
{
	t_game	game;
	ssize_t	i;

	(void) envp;
	(void) av;
	if (ac != 2 || !*envp)
		return (EXIT_FAILURE);
	if (map_parsing(av[1], &game) != 0)
		return (EXIT_FAILURE);
	if (game.map.path.ea)
		printf("EA %s\n", game.map.path.ea);
	if (game.map.path.no)
		printf("NO %s\n", game.map.path.no);
	if (game.map.path.so)
		printf("SO %s\n", game.map.path.so);
	if (game.map.path.we)
		printf("WE %s\n", game.map.path.we);
	if (game.map.color.c)
		printf("C %s\n", game.map.color.c);
	if (game.map.color.f)
		printf("F %s\n", game.map.color.f);
	i = 0;
	while (game.map.map && game.map.map[i])
		printf("%s\n", game.map.map[i++]);
	printf("x: %ld, y: %ld, %f°", game.perso.x, game.perso.y, game.perso.angle);
	init_win(&game);
	render_win(&game);
	mlx_hook(game.win, 17, 1L >> 17, exit_mlx, &game);
	mlx_loop(game.mlx);
	return (free_color(game.map.color),free_path(game.map.path), free_strs(game.map.map), EXIT_SUCCESS);
}
