/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffusion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 11:30:54 by astachni          #+#    #+#             */
/*   Updated: 2023/11/09 12:35:15 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static void	diffusion(char **map, ssize_t x, ssize_t y)
{
	if (x + 1 < ft_strslen(map) && y < (ssize_t)ft_strlen(map[x + 1])
		&& (map[x + 1][y] == '0' || map[x + 1][y] == '1'))
	{
		map[x + 1][y] = '*';
		diffusion(map, x + 1, y);
	}
	if (x != 0 && y < (ssize_t)ft_strlen(map[x - 1])
		&& (map[x - 1][y] == '0' || map[x - 1][y] == '1'))
	{
		map[x - 1][y] = '*';
		diffusion(map, x - 1, y);
	}
	if (y + 1 < (ssize_t)ft_strlen(map[x])
		&& (map[x][y + 1] == '0' || map[x][y + 1] == '1'))
	{
		map[x][y + 1] = '*';
		diffusion(map, x, y + 1);
	}
	if (y != 0 && (map[x][y - 1] == '0' || map[x][y - 1] == '1'))
	{
		map[x][y - 1] = '*';
		diffusion(map, x, y - 1);
	}
}

static ssize_t	*find_coor(char **map)
{
	ssize_t	*tab;

	tab = malloc(sizeof(ssize_t) * 2);
	if (!tab)
		return (NULL);
	tab[0] = 0;
	tab[1] = 0;
	while (map)
	{
		tab[1] = 0;
		while (map[tab[0]][tab[1]])
		{
			if (map[tab[0]][tab[1]] == 'N'
				|| map[tab[0]][tab[1]] == 'S'
				|| map[tab[0]][tab[1]] == 'E'
				|| map[tab[0]][tab[1]] == 'W')
				return (tab);
			tab[1] += 1;
		}
		tab[0] += 1;
	}
	free(tab);
	return (NULL);
}

static int	map_is_ok(char **map)
{
	ssize_t	x;
	ssize_t	y;

	x = 0;
	while (map && map[x])
	{
		y = 0;
		while (map[x] && map[x][y])
		{
			if (map[x][y] != ' ' && map[x][y] != '*'
				&& map[x][y] != 'N' && map[x][y] != 'S' && map[x][y] != 'E'
				&& map[x][y] != 'W')
				return (-1);
			y++;
		}
		x++;
	}
	return (0);
}

int	is_island_(t_game *game)
{
	char	**map;
	ssize_t	*coor;
	int		return_code;

	map = NULL;
	return_code = 0;
	map = ft_strsdup(game->map.map);
	if (!map)
		return (1);
	coor = find_coor(map);
	if (!coor)
		return (free_strs(map), 1);
	diffusion (map, coor[0], coor[1]);
	if (map_is_ok(map))
	{
		game->error = 1;
		return_code = 1;
	}
	free(coor);
	free_strs(map);
	return (return_code);
}
