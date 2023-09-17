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

# define SCREEN_W 700
# define SCREEN_H 300
// parsing

int		map_parsing(char *map_path, t_game *game);
t_map	get_map(char **entire_file);

// free

int	exit_win(t_game *game, int error);
void	free_color(t_color color);
void	free_path(t_path path);
void	free_strs(char **strs);

// utils

char	**ft_strsdup(char **src);

// window

int	init_win(t_game *game);
void	render_win(t_game *game);
int	exit_mlx(void *arg);

// draw

void	draw(t_game *game);
void	draw_minimap(t_game *game);
void	draw_rectangle(t_game *game, int x, int y, int w, int h);
void	game_put_pixel(t_game *game, int x, int y);
#endif
