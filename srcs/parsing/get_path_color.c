/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:39 by astachni          #+#    #+#             */
/*   Updated: 2023/11/07 16:45:49 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
#include <stdio.h>

static void	get_c(t_color *color, char *entire_file);
static void	get_f(t_color *color, char *entire_file);
static void	verif_path_ns(t_path *path, char *entire_file);
static void	verif_path_ew(t_path *path, char *entire_file);

void	get_path_color(char **entire_file, t_map *map)
{
	ssize_t	i;
	ssize_t	j;

	i = 0;
	map->path.is_free = 0;
	map->color.is_free = 0;
	j = 0;
	while (entire_file[i] && i < 6)
	{
		while (entire_file[i][j] && \
		(entire_file[i][j] == ' ' || entire_file[i][j] == '\t'))
			j++;
		verif_path_ns(&map->path, &entire_file[i][j]);
		verif_path_ew(&map->path, &entire_file[i][j]);
		if (entire_file[i][j] == 'C')
			get_c(&map->color, &entire_file[i][j + 1]);
		else if (entire_file[i][j] == 'F')
			get_f(&map->color, &entire_file[i][j + 1]);
		i++;
		j = 0;
	}
}

static void	verif_path_ew(t_path *path, char *entire_file)
{
	ssize_t	j;

	j = 2;
	if (ft_strncmp(entire_file, "WE", ft_strlen("WE")) == 0)
	{
		while (entire_file[j] && \
			(entire_file[j] == ' ' || entire_file[j] == '\t'))
			j++;
		if (entire_file[j] && !path->we)
			path->we = ft_strdup(&entire_file[j]);
		else if (path->we)
			free(path->we);
	}
	else if (ft_strncmp(entire_file, "EA", ft_strlen("EA")) == 0)
	{
		while (entire_file[j] && \
			(entire_file[j] == ' ' || entire_file[j] == '\t'))
			j++;
		if (entire_file[j] && !path->ea)
			path->ea = ft_strdup(&entire_file[j]);
		else if (path->ea)
			free(path->ea);
	}
}

static void	verif_path_ns(t_path *path, char *entire_file)
{
	ssize_t	j;

	j = 2;
	if (ft_strncmp(entire_file, "NO", ft_strlen("NO")) == 0)
	{
		while (entire_file[j] && \
			(entire_file[j] == ' ' || entire_file[j] == '\t'))
			j++;
		if (entire_file[j] && !path->no)
			path->no = ft_strdup(&entire_file[j]);
		else if (path->no)
			free(path->no);
	}
	else if (ft_strncmp(entire_file, "SO", ft_strlen("SO")) == 0)
	{
		while (entire_file[j] && \
			(entire_file[j] == ' ' || entire_file[j] == '\t'))
			j++;
		if (entire_file[j] && !path->so)
			path->so = ft_strdup(&entire_file[j]);
		else if (path->so)
			free(path->so);
	}
}

static void	get_f(t_color *color, char *entire_file)
{
	ssize_t	j;
	ssize_t	i;

	i = 0;
	while (entire_file[i])
	{
		if (entire_file[i] != ',' || \
			(entire_file[i] < '0' || entire_file[i] > '9'))
			return ;
		i++;
	}
	j = 0;
	while (entire_file[j] && \
		(entire_file[j] == ' ' || entire_file[j] == '\t'))
		j++;
	if (entire_file[j])
		color->f = ft_strdup(&entire_file[j]);
	get_f_int(color);
}

static void	get_c(t_color *color, char *entire_file)
{
	ssize_t	j;
	ssize_t	i;

	i = 0;
	while (entire_file[i])
	{
		if (entire_file[i] != ',' && \
			(entire_file[i] < '0' || entire_file[i] > '9'))
			return ;
		i++;
	}
	j = 0;
	while (entire_file[j] && \
		(entire_file[j] == ' ' || entire_file[j] == '\t'))
		j++;
	if (entire_file[j])
		color->c = ft_strdup(&entire_file[j]);
	get_c_int(color);
}
