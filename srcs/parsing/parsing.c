/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:17 by astachni          #+#    #+#             */
/*   Updated: 2023/09/20 02:02:59 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

char	**get_entire_file(int fd);

int	map_parsing(char *map_path, t_game *game)
{
	int		fd;
	char	**entire_file;

	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	entire_file = get_entire_file(fd);
	close (fd);
	if (!entire_file)
		return (EXIT_FAILURE);
	(*game).map = get_map(entire_file);
	if (is_valid_map((*game).map.map) != 0)
		return (EXIT_FAILURE);
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
	file_splited = ft_split (file_unsplited, '\n');
	free(file_unsplited);
	return (file_splited);
}
