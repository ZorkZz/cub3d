/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:39 by astachni          #+#    #+#             */
/*   Updated: 2023/11/02 15:03:11 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static t_color	get_c(t_color color, char *entire_file);
static t_color	get_f(t_color color, char *entire_file);
static t_path	verif_path_ns(t_path path, char *entire_file);
static t_path	verif_path_ew(t_path path, char *entire_file);

t_map	get_path_color(char **entire_file, t_map map)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	map.path.is_free = 0;
	map.color.is_free = 0;
	j = 0;
	while (entire_file[i] && i < 6)
	{
		while (entire_file[i][j] && \
		(entire_file[i][j] == ' ' || entire_file[i][j] == '\t'))
			j++;
		map.path = verif_path_ns(map.path, &entire_file[i][j]);
		map.path = verif_path_ew(map.path, &entire_file[i][j]);
		if (entire_file[i][j] == 'C')
			map.color = get_c(map.color, &entire_file[i][j + 1]);
		else if (entire_file[i][j] == 'F')
			map.color = get_f(map.color, &entire_file[i][j + 1]);
		i++;
		j = 0;
	}
	return (map);
}

static t_path	verif_path_ew(t_path path, char *entire_file)
{
	ssize_t	j;

	if (ft_strncmp(entire_file, "WE", ft_strlen("WE")) == 0)
	{
		j = 2;
		while (entire_file[j] && \
			(entire_file[j] == ' ' || entire_file[j] == '\t'))
			j++;
		if (entire_file[j])
			path.we = ft_strdup(&entire_file[j]);
	}
	else if (ft_strncmp(entire_file, "EA", ft_strlen("EA")) == 0)
	{
		j = 2;
		while (entire_file[j] && \
			(entire_file[j] == ' ' || entire_file[j] == '\t'))
			j++;
		if (entire_file[j])
			path.ea = ft_strdup(&entire_file[j]);
	}
	return (path);
}

static t_path	verif_path_ns(t_path path, char *entire_file)
{
	ssize_t	j;

	if (ft_strncmp(entire_file, "NO", ft_strlen("NO")) == 0)
	{
		j = 2;
		while (entire_file[j] && \
			(entire_file[j] == ' ' || entire_file[j] == '\t'))
			j++;
		if (entire_file[j])
			path.no = ft_strdup(&entire_file[j]);
	}
	else if (ft_strncmp(entire_file, "SO", ft_strlen("SO")) == 0)
	{
		j = 2;
		while (entire_file[j] && \
			(entire_file[j] == ' ' || entire_file[j] == '\t'))
			j++;
		if (entire_file[j])
			path.so = ft_strdup(&entire_file[j]);
	}
	return (path);
}

static t_color	get_f(t_color color, char *entire_file)
{
	ssize_t	j;

	j = 0;
	while (entire_file[j] && \
		(entire_file[j] == ' ' || entire_file[j] == '\t'))
		j++;
	if (entire_file[j])
		color.f = ft_strdup(&entire_file[j]);
	color = get_f_int(color);
	return (color);
}

static t_color	get_c(t_color color, char *entire_file)
{
	ssize_t	j;

	j = 0;
	while (entire_file[j] && \
		(entire_file[j] == ' ' || entire_file[j] == '\t'))
		j++;
	if (entire_file[j])
		color.c = ft_strdup(&entire_file[j]);
	color = get_c_int(color);
	return (color);
}
