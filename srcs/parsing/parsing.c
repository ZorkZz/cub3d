/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:17 by astachni          #+#    #+#             */
/*   Updated: 2023/09/13 18:28:01 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

char	**get_entire_file(int fd);

int	map_parsing(char *map_path, t_game *game)
{
	int		fd;
	char	**entire_file;

	(void) game;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
		return (EXIT_FAILURE);
	entire_file = get_entire_file(fd);
	if (!entire_file)
	{
		close (fd);
		return (EXIT_FAILURE);
	}
	close (fd);
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
		file_unsplited = ft_strfjoin(file_unsplited, line);
		if (!file_unsplited)
			return (NULL);
	}
	file_splited = ft_split (file_unsplited, '\n');
	return (file_splited);
}
