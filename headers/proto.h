/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:36 by astachni          #+#    #+#             */
/*   Updated: 2023/09/14 16:19:48 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H

# define PROTO_H

// parsing

int		map_parsing(char *map_path, t_game *game);
t_map	get_map(char **entire_file);

// free

void	free_color(t_color color);
void	free_path(t_path path);
void	free_strs(char **strs);

// utils

char	**ft_strsdup(char **src);

#endif