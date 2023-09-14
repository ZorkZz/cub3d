/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:58:36 by astachni          #+#    #+#             */
/*   Updated: 2023/09/14 16:23:56 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

t_path	get_path(char **entire_file);
t_color	get_color(char **entire_file);
char	**get_map_char(char **entire_file);

t_map	get_map(char **entire_file)
{
	t_map	map;

	map.path = get_path(entire_file);
	map.color = get_color(entire_file);
	map.map = get_map_char(entire_file);
	return (map);
}

t_path	get_path(char **entire_file)
{
	ssize_t	i;
	t_path	path;

	i = 0;
	while (i < 4)
	{
		if (entire_file[i][0] == 'N')
			path.no = ft_strdup(&entire_file[i][3]);
		else if (entire_file[i][0] == 'S')
			path.so = ft_strdup(&entire_file[i][3]);
		else if (entire_file[i][0] == 'W')
			path.we = ft_strdup(&entire_file[i][3]);
		else if (entire_file[i][0] == 'E')
			path.ea = ft_strdup(&entire_file[i][3]);
		i++;
	}
	if (!path.no || !path.ea || !path.so || !path.we)
		free_path(path);
	return (path);
}

t_color	get_color(char **entire_file)
{
	ssize_t	i;
	t_color	color;

	i = 4;
	while (i < 6)
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
	return (ft_strsdup(&entire_file[6]));
}
