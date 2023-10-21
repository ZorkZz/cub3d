/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:58:36 by astachni          #+#    #+#             */
/*   Updated: 2023/10/12 14:26:26 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

t_path	get_path(char **entire_file);
t_color	get_color(char **entire_file);
char	**get_map_char(char **entire_file);

t_map	get_map(char **entire_file)
{
	t_map	map;
	size_t	i;

	map.path = get_path(entire_file);
	map.color = get_color(entire_file);
	map.map = get_map_char(entire_file);
	i = 0;
	while (map.map[i])
		i++;	
	map.width = i;
	while (map.map[0][i])
		i++;
	map.height = i;
	return (map);
}

t_path	get_path(char **entire_file)
{
	ssize_t	i;
	t_path	path;

	i = 0;
	path.ea = NULL;
	path.no = NULL;
	path.so = NULL;
	path.we = NULL;
	while (entire_file[i] && i < 4)
	{
		if (entire_file[i][0] == 'N' && ft_strlen(&entire_file[i][0]) > 3)
			path.no = ft_strdup(&entire_file[i][3]);
		else if (entire_file[i][0] == 'S' && ft_strlen(&entire_file[i][0]) > 3)
			path.so = ft_strdup(&entire_file[i][3]);
		else if (entire_file[i][0] == 'W' && ft_strlen(&entire_file[i][0]) > 3)
			path.we = ft_strdup(&entire_file[i][3]);
		else if (entire_file[i][0] == 'E' && ft_strlen(&entire_file[i][0]) > 3)
			path.ea = ft_strdup(&entire_file[i][3]);
		i++;
	}
	if (!path.ea || !path.no || !path.so || !path.we)
		free_path(path);
	return (path);
}

t_color	get_color(char **entire_file)
{
	ssize_t	i;
	t_color	color;

	i = 0;
	color.c = NULL;
	color.f = NULL;
	while (entire_file[i] && i < 4)
		i++;
	while (entire_file[i] && i < 6)
	{
		if (entire_file[i][0] == 'F')
			color.f = ft_strdup(&entire_file[i][2]);
		else if (entire_file[i][0] == 'C')
			color.c = ft_strdup(&entire_file[i][2]);
		i++;
	}
	if (!color.f || !color.c)
		free_color(color);
	return (color);
}

char	**get_map_char(char **entire_file)
{
	char	**map;
	ssize_t	i;

	map = NULL;
	i = 0;
	while (entire_file[i] && i < 6)
		i++;
	if (i == 6)
		map = ft_strsdup(&entire_file[6]);
	if (!map)
		return (NULL);
	return (map);
}
