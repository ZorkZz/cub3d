/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:58:36 by astachni          #+#    #+#             */
/*   Updated: 2023/10/30 13:29:20 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static t_path	get_path(char **entire_file);
static t_color	get_color(char **entire_file);
static char		**get_map_char(char **entire_file);
static t_color	get_color_int(t_color color);

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
	while (i < ft_strlen(map.map[0]))
		i++;
	map.height = i;
	return (map);
}

static t_path	get_path(char **entire_file)
{
	ssize_t	i;
	t_path	path;

	i = 0;
	path.ea = NULL;
	path.no = NULL;
	path.so = NULL;
	path.we = NULL;
	path.is_free = 0;
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
	return (path);
}

static t_color	get_color(char **entire_file)
{
	ssize_t	i;
	t_color	color;

	i = 0;
	color.c = NULL;
	color.f = NULL;
	color.is_free = 0;
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
	if (color.f && color.c)
		color = get_color_int(color);
	return (color);
}

static t_color	get_color_int(t_color color)
{
	int	i;
	int	j;

	i = -1;
	j = 0;
	while (color.c && color.c[++i])
	{
		if (i == 0 || (i > 0 && color.c[i - 1] == ','))
		{
			color.c_int_tab[j] = ft_atoi(&color.c[i]);
			if (color.c_int_tab[j] < 0 || color.c_int_tab[j] > 255)
				return (color.c_int = -1, color);
			j++;
		}
	}
	i = -1;
	j = 0;
	while (color.f && color.f[++i])
	{
		if (i == 0 || (i > 0 && color.f[i - 1] == ','))
		{
			color.f_int_tab[j] = ft_atoi(&color.f[i]);
			if (color.f_int_tab[j] < 0 || color.f_int_tab[j] > 255)
				return (color.f_int = -1, color);
			j++;
		}
	}
	color.c_int = (color.c_int_tab[0] << 16) | (color.c_int_tab[1] << 8) | color.c_int_tab[2];
	color.f_int = (color.f_int_tab[0] << 16) | (color.f_int_tab[1] << 8) | color.f_int_tab[2];
	return (color);
}

static char	**get_map_char(char **entire_file)
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
