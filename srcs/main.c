/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:05:22 by astachni          #+#    #+#             */
/*   Updated: 2023/09/13 17:26:00 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

int	main(int ac, char **av, char **envp)
{
	t_game	game;

	(void) envp;
	(void) av;
	if (ac != 2)
		return (EXIT_FAILURE);
	if (map_parsing(av[1], &game) != 0)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}