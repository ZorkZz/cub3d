/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:11:39 by astachni          #+#    #+#             */
/*   Updated: 2023/11/16 11:47:36 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"
#include <stdio.h>

static void	get_c(t_color *color, t_game *game, char *entire_file);
static void	get_f(t_color *color, t_game *game, char *entire_file);
static void	*verif_path_ns(t_path *path, t_game *game, \
	char *entire_file, ssize_t j);
static void	*verif_path_ew(t_path *path, t_game *game, \
	char *entire_file, ssize_t j);

void	get_path_color(char **entire_file, t_map *map, t_game *game)
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
		verif_path_ns(&map->path, game, &entire_file[i][j], 2);
		verif_path_ew(&map->path, game, &entire_file[i][j], 2);
		if (entire_file[i][j] == 'C')
			get_c(&map->color, game, &entire_file[i][j + 1]);
		else if (entire_file[i][j] == 'F')
			get_f(&map->color, game, &entire_file[i][j + 1]);
		i++;
		j = 0;
	}
}

static void	*verif_path_ew(t_path *path, t_game *game, \
	char *entire_file, ssize_t j)
{
	if (ft_strncmp(entire_file, "WE", ft_strlen("WE")) == 0)
	{
		while (entire_file[j] && ft_isspace(entire_file[j]))
			j++;
		if (entire_file[j] && !path->we)
			path->we = ft_strdup(&entire_file[j]);
		else if (path->we)
		{
			game->error = 5;
			return (free(path->we), path->we = NULL);
		}
	}
	else if (ft_strncmp(entire_file, "EA", ft_strlen("EA")) == 0)
	{
		while (entire_file[j] && ft_isspace(entire_file[j]))
			j++;
		if (entire_file[j] && !path->ea)
			path->ea = ft_strdup(&entire_file[j]);
		else if (path->ea)
		{
			game->error = 5;
			return (free(path->ea), path->ea = NULL);
		}
	}
	return (NULL);
}

static void	*verif_path_ns(t_path *path, t_game *game, \
	char *entire_file, ssize_t j)
{
	if (ft_strncmp(entire_file, "NO", ft_strlen("NO")) == 0)
	{
		while (entire_file[j] && ft_isspace(entire_file[j]))
			j++;
		if (entire_file[j] && !path->no)
			path->no = ft_strdup(&entire_file[j]);
		else if (path->no)
		{
			game->error = 5;
			return (free(path->no), path->no = NULL);
		}
	}
	else if (ft_strncmp(entire_file, "SO", ft_strlen("SO")) == 0)
	{
		while (entire_file[j] && ft_isspace(entire_file[j]))
			j++;
		if (entire_file[j] && !path->so)
			path->so = ft_strdup(&entire_file[j]);
		else if (path->so)
		{
			game->error = 5;
			return (free(path->so), path->so = NULL);
		}
	}
	return (NULL);
}

static void	get_f(t_color *color, t_game *game, char *entire_file)
{
	ssize_t	j;
	ssize_t	i;

	i = 0;
	while (entire_file[i])
	{
		while (entire_file[i] && ft_isspace(entire_file[i]))
			i++;
		if ((entire_file[i] != ',' && !ft_isdigit(entire_file[i])) || \
			(i != 0 && entire_file[i - 1] == ',' && entire_file[i] == ','))
		{
			color->f_int = -1;
			game->error = 4;
			return ;
		}
		i++;
	}
	j = 0;
	while (entire_file[j] && ft_isspace(entire_file[j]))
		j++;
	if (entire_file[j])
		color->f = ft_strdup(&entire_file[j]);
	get_f_int(color);
}

static void	get_c(t_color *color, t_game *game, char *entire_file)
{
	ssize_t	j;
	ssize_t	i;

	i = 0;
	while (entire_file[i])
	{
		while (entire_file[i] && \
		(entire_file[i] == ' ' || entire_file[i] == '\t'))
			i++;
		if ((entire_file[i] != ',' && !ft_isdigit(entire_file[i])) || \
			(i != 0 && entire_file[i - 1] == ',' && entire_file[i] == ','))
		{
			color->c_int = -1;
			game->error = 4;
			return ;
		}
		i++;
	}
	j = 0;
	while (entire_file[j] && ft_isspace(entire_file[j]))
		j++;
	if (entire_file[j])
		color->c = ft_strdup(&entire_file[j]);
	get_c_int(color);
}
