/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:17 by astachni          #+#    #+#             */
/*   Updated: 2023/11/06 09:50:19 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

char		**get_entire_file(int fd);
static int	verif_island(char *file);

int	map_parsing(char *map_path, t_game *game)
{
	int		fd;
	char	**entire_file;

	game->sprite[0].assign = 0;
	game->sprite[1].assign = 0;
	game->sprite[2].assign = 0;
	game->sprite[3].assign = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	entire_file = get_entire_file(fd);
	close (fd);
	if (!entire_file)
		return (EXIT_FAILURE);
	(*game).map = get_map(entire_file);
	if (!(*game).map.map)
		return (free_strs(entire_file), EXIT_FAILURE);
	if (is_valid_map((*game).map.map) != 0 || is_island_(game) || \
		(*game).map.color.c_int == -1 || (*game).map.color.f_int == -1)
		return (free_parsing(*game, entire_file), EXIT_FAILURE);
	get_infos_perso((*game).map.map, &game->perso);
	free_strs(entire_file);
	return (EXIT_SUCCESS);
}

char	**get_entire_file(int fd)
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
	if (verif_island(file_unsplited))
		return (free(file_unsplited), NULL);
	file_splited = ft_split (file_unsplited, '\n');
	return (free(file_unsplited), file_splited);
}

static int	verif_island(char *file)
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
					return (1);
				i++;
			}
		}
		i++;
	}
	return (0);
}
