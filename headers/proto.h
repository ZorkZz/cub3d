/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:36 by astachni          #+#    #+#             */
/*   Updated: 2023/09/17 17:40:59 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H

# define PROTO_H

# define SCREEN_W 700
# define SCREEN_H 300

# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define ESCAPE_KEY 65307

# define MOVE_SPEED 25
# define ROTATION_SPEED 0.05

// parsing

int		map_parsing(char *map_path, t_game *game);
t_map	get_map(char **entire_file);
void	get_infos_perso(char **map, t_perso *perso);

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
int	deal_key(int key, void *param);
int	exit_mlx(void *arg);

// draw

void	draw(t_game *game);
void	draw_minimap(t_game *game);
void	draw_rectangle(t_game *game, int x, int y, int w, int h);
void	game_put_pixel(t_game *game, int x, int y);
void	draw_line(t_game *game, t_point start, t_point end);

// control

void	move_player(t_game *game, char c);
void	rotate_player(t_game *game, int mult);
#endif
