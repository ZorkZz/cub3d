/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_infos_perso.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 17:33:26 by astachni          #+#    #+#             */
/*   Updated: 2023/10/30 13:23:23 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	assign_variable(char **map, t_perso *perso, ssize_t i, ssize_t j);

void	get_infos_perso(char **map, t_perso *perso)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i] && map[i][j])
		{
			assign_variable(map, perso, i, j);
			j++;
		}
		i++;
	}
}

static void	assign_variable(char **map, t_perso *perso, ssize_t i, ssize_t j)
{
	if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || \
		map[i][j] == 'W')
	{
		perso->x = i;
		perso->y = j;
		if (map[i][j] == 'N')
			perso->angle = M_PI;
		else if (map[i][j] == 'S')
			perso->angle = 0;
		else if (map[i][j] == 'E')
			perso->angle = -(M_PI / 2);
		else if (map[i][j] == 'W')
			perso->angle = M_PI / 2;
		return ;
	}
}
