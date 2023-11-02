/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proto.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:13:36 by astachni          #+#    #+#             */
/*   Updated: 2023/11/02 14:48:15 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTO_H
# define PROTO_H

// parsing
int		is_valid_map(char **map);
int		map_parsing(char *map_path, t_game *game);
t_map	get_map(char **entire_file);
void	get_infos_perso(char **map, t_perso *perso);
t_color	get_c_int(t_color color);
t_color	get_f_int(t_color color);
t_map	get_path_color(char **entire_file, t_map map);

// free

int		exit_win(t_game *game, int error);
void	free_parsing(t_game game, char **strs);
void	free_color(t_color color);
void	free_path(t_path path);
void	free_strs(char **strs);
void	free_images(t_game *game);

// utils

char	**ft_strsdup(char **src);

// window

int		init_win(t_game *game);
int		render_win(void	*param);
int		deal_key(t_game *game);
int		exit_mlx(void *arg);
int		key_hook(int key, void *param);
int		key_realese(int key, void *param);

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

int			get_all_textures(t_game *game);
void		change_wall_face(t_game *game, t_fpoint h, t_fpoint v, float cos_a, float sin_a);
void		get_to_draw(t_game *game, float dist, int i);
void		raycast(t_game *game);
float		ray_depth(t_game *game, float ray_angle);
t_fpoint	horizontal_depth(t_game *game, float cos_a, float sin_a);
t_fpoint	vertical_depth(t_game *game, float cos_a, float sin_a);

#endif
