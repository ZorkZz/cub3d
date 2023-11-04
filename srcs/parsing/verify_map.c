/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:33:19 by astachni          #+#    #+#             */
/*   Updated: 2023/11/04 11:15:35 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static int	is_valid_char(char **map, ssize_t i, ssize_t j);

int	check_char(char **map, int i, int j, int *player_start_found)
{
	if (is_valid_char(map, i, j))
		return (EXIT_FAILURE);
	if (map[i][j] == 'N' || map[i][j] == 'S' || \
		map[i][j] == 'E' || map[i][j] == 'W')
	{
		if (*player_start_found != 0)
			return (EXIT_FAILURE);
		*player_start_found = 1;
	}
	return (EXIT_SUCCESS);
}

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
			if (check_char(map, i, j, &player_start_found) == EXIT_FAILURE)
				return (EXIT_FAILURE);
			j++;
		}
		if (map[i][j - 1] != '1')
			return (EXIT_FAILURE);
		i++;
	}
	if (!player_start_found)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_space(char **map, ssize_t i, ssize_t j)
{
	if (i != 0 && (size_t)j < ft_strlen(map[i - 1])
		&& map[i - 1][j] && (map[i - 1][j] != ' ' && map[i - 1][j] != '1'))
		return (EXIT_FAILURE);
	if (map[i] && i + 1 < ft_strslen(map) && (size_t)j < ft_strlen(map[i + 1])
		&& map[i + 1] && (map[i + 1][j] != ' ' && map[i + 1][j] != '1'))
		return (EXIT_FAILURE);
	if (j != 0 && (map[i][j - 1] != ' ' && map[i][j - 1] != '1'))
		return (EXIT_FAILURE);
	if (map[i][j] && (size_t)j + 1 < ft_strlen(map[i])
		&& (map[i][j + 1] != ' ' && map[i][j + 1] != '1'))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	check_zero(char **map, ssize_t i, ssize_t j)
{
	if (i == 0)
		return (EXIT_FAILURE);
	if (i != 0 && !map[i - 1][j])
		return (EXIT_FAILURE);
	if (map[i] && !map[i + 1])
		return (EXIT_FAILURE);
	if (j != 0 && !map[i][j - 1])
		return (EXIT_FAILURE);
	if (map[i][j] && !map[i][j + 1])
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static int	is_valid_char(char **map, ssize_t i, ssize_t j)
{
	const char	valid_chars[] = " 01NSEW";

	if (ft_strchr(valid_chars, map[i][j]) != NULL)
	{
		if (map[i][j] == ' ')
		{
			if (check_space(map, i, j) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
		else if (map[i][j] == '0')
			if (check_zero(map, i, j) == EXIT_FAILURE)
				return (EXIT_FAILURE);
	}
	else
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
