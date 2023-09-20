/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:33:19 by astachni          #+#    #+#             */
/*   Updated: 2023/09/20 02:25:18 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	is_valid_char(char **map, ssize_t i, ssize_t j);

int	is_valid_map(char **map)
{
	int		player_start_found;
	ssize_t	i;
	ssize_t	j;

	player_start_found = 0;
	i = 0;
	while (map && map[i])
	{
		j = 0;
		while (map[i] && map[i][j])
		{
			if (is_valid_char(map, i, j))
				return (EXIT_FAILURE);
			if (map[i][j] == 'N' || map[i][j] == 'S' || \
				map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (player_start_found != 0)
					return (EXIT_FAILURE);
				player_start_found = 1;
			}
			j++;
		}
		i++;
	}
	ft_printf("a");
	if (!player_start_found)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	is_valid_char(char **map, ssize_t i, ssize_t j)
{
	const char	valid_chars[] = " 01NSEW";

	if (ft_strchr(valid_chars, map[i][j]) != NULL)
	{
		if (map[i][j] == ' ')
		{
			if (i != 0 && map[i - 1][j] && (map[i - 1][j] != ' ' && map[i - 1][j] != '1'))
				return (EXIT_FAILURE);
			if (map[i] && map[i + 1] && map[i + 1][j] && (map[i + 1][j] != ' ' && map[i + 1][j] != '1'))
				return (EXIT_FAILURE);
			if (j != 0 && map[i][j - 1] && (map[i][j - 1] != ' ' && map[i][j - 1] != '1'))
				return (EXIT_FAILURE);
			if (map[i][j] && map[i][j + 1] && (map[i][j + 1] != ' ' && map[i][j + 1] != '1'))
				return (EXIT_FAILURE);
		}
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
