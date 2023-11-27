/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:17 by astachni          #+#    #+#             */
/*   Updated: 2023/11/27 12:18:02 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

static char		**get_entire_file(int fd, t_game *game);
static int		verif_island(char *file, t_game *game);
static int		check_extention(char *file, t_game *game);
static void		sprite_assigne(t_game *game);

static void	sprite_assigne(t_game *game)
{
	game->sprite[0].assign = 0;
	game->sprite[1].assign = 0;
	game->sprite[2].assign = 0;
	game->sprite[3].assign = 0;
}

int	map_parsing(char *map_path, t_game *game)
{
	int		fd;
	char	**entire_file;

	sprite_assigne(game);
	if (check_extention(map_path, game))
		return (error_code(*game), EXIT_FAILURE);
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	entire_file = get_entire_file(fd, game);
	close (fd);
	if (!entire_file)
		return (EXIT_FAILURE);
	(*game).map = get_map(entire_file, game);
	if (!(*game).map.map)
		return (free_strs(entire_file), EXIT_FAILURE);
	if (is_valid_map((*game).map.map, game) != 0 || is_island_(game) || \
	game->error != 0 || game->map.color.c_int == -1 || \
		game->map.color.f_int == -1)
		return (free_parsing(*game, entire_file), EXIT_FAILURE);
	get_infos_perso((*game).map.map, &game->perso);
	free_strs(entire_file);
	get_ratio_map(game);
	return (EXIT_SUCCESS);
}

static int	check_extention(char *file, t_game *game)
{
	ssize_t	i;

	i = ft_strlen(file);
	if (i < 4)
	{
		game->error = 3;
		return (EXIT_FAILURE);
	}
	i -= ft_strlen(".cub");
	if (ft_strncmp(&file[i], ".cub", ft_strlen(".cub")))
	{
		game->error = 3;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static char	**get_entire_file(int fd, t_game *game)
{
	char	**file_splited;
	char	*file_unsplited;
	char	*line;

	file_unsplited = NULL;
	line = NULL;
	file_splited = NULL;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!file_unsplited)
		{
			file_unsplited = ft_strdup(line);
			free(line);
		}
		else
			file_unsplited = ft_strfjoin(file_unsplited, line);
		if (!file_unsplited)
			return (NULL);
		line = get_next_line(fd);
	}
	if (verif_island(file_unsplited, game))
		return (free(file_unsplited), NULL);
	file_splited = ft_split (file_unsplited, '\n');
	return (free(file_unsplited), file_splited);
}

static int	verif_island(char *file, t_game *game)
{
	size_t	i;

	i = 0;
	while (file && i < ft_strlen(file))
	{
		if (ft_strncmp(&file[i], "111", ft_strlen("111")) == 0)
		{
			while (i < ft_strlen(file))
			{
				if (ft_strncmp(&file[i], "\n\n", ft_strlen("\n\n")) == 0)
				{
					game->error = 1;
					return (EXIT_FAILURE);
				}
				i++;
			}
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
