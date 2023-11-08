/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 18:58:36 by astachni          #+#    #+#             */
/*   Updated: 2023/11/08 13:04:35 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static char		**get_map_char(char **entire_file);
static t_map	all_null(void);

t_map	get_map(char **entire_file)
{
	t_map	map;
	size_t	i;

	map = all_null();
	get_path_color(entire_file, &map);
	map.map = get_map_char(entire_file);
	i = 0;
	while (map.map && map.map[i])
		i++;
	map.width = i;
	while (map.map && i < ft_strlen(map.map[0]))
		i++;
	map.height = i;
	return (map);
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

static t_map	all_null(void)
{
	t_map	map;

	map.color.c = NULL;
	map.color.f = NULL;
	map.path.ea = NULL;
	map.path.no = NULL;
	map.path.so = NULL;
	map.path.we = NULL;
	return (map);
}
