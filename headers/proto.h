/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:36 by astachni          #+#    #+#             */
/*   Updated: 2023/10/27 17:01:31 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

// parsing
int		is_valid_map(char **map);
int		map_parsing(char *map_path, t_game *game);
t_map	get_map(char **entire_file);
void	get_infos_perso(char **map, t_perso *perso);

// free

int		exit_win(t_game *game, int error);
void	free_parsing(t_game game, char **strs);
void	free_color(t_color color);
void	free_path(t_path path);
void	free_strs(char **strs);

// utils

char	**ft_strsdup(char **src);

// window

int		init_win(t_game *game);
void	render_win(t_game *game);
int		deal_key(int key, void *param);
int		exit_mlx(void *arg);

// draw

void	draw(t_game *game);
void	draw_minimap(t_game *game);
void	draw_rectangle(t_game *game, int x, int y, int w, int h);
void	game_put_pixel(t_game *game, int x, int y);
void	draw_line(t_game *game, t_point start, t_point end);

// control

void	move_player(t_game *game, char c);
void	rotate_player(t_game *game, int mult);

//raycasting

int			get_texture(t_game *game);
void		change_wall_face(t_game *game, t_fpoint h, t_fpoint v);
void		get_to_draw(t_game *game, float dist, int i);
void		raycast(t_game *game);
float		ray_depth(t_game *game, float ray_angle);
t_fpoint	horizontal_depth(t_game *game, float cos_a, float sin_a);
t_fpoint	vertical_depth(t_game *game, float cos_a, float sin_a);

#endif
