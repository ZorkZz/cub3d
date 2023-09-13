/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:17 by astachni          #+#    #+#             */
/*   Updated: 2023/09/13 17:41:01 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

int	map_parsing(char *map_path, t_game *game)
{
	int	fd;

	fd = open(map_path, O_RDONLY);;
	if (fd < 0)
		return (EXIT_FAILURE);
	close (fd);
}

char	**get_entire_file(int fd)
{
	char	**file_splited;
	char	*file_unsplited;
	char	*line;

	line = get_next_line(fd);
	while (line != NULL)
	{
		file_unsplited = ft_strjoin(file_unsplited, line);
		free_line;
	}
}