/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:15:02 by astachni          #+#    #+#             */
/*   Updated: 2023/11/27 12:06:46 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

# include <stdlib.h>

typedef struct s_bresenham
{
	int	p0x;
	int	p0y;
	int	p1x;
	int	p1y;
}	t_bresenham;

typedef struct s_fpoint
{
	float	x;
	float	y;
	double	distance;
	float	height;
}	t_fpoint;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_path
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		is_free;
}	t_path;

typedef struct s_color
{
	char	*f;
	char	*c;
	int		c_int_tab[3];
	int		c_int;
	int		f_int_tab[3];
	int		f_int;
	int		is_free;
}	t_color;

typedef struct s_map
{
	char	**map;
	t_path	path;
	t_color	color;
	ssize_t	width;
	ssize_t	height;
}	t_map;

typedef struct s_perso
{
	float	y;
	float	x;
	float	angle;
	int		s;
	int		w;
	int		a;
	int		d;
	int		left;
	int		right;
}	t_perso;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		x;
	int		y;
	int		assign;
}	t_img;

typedef struct s_game
{
	t_perso	perso;
	t_map	map;
	void	*mlx;
	void	*win;
	t_img	img;
	t_img	sprite[4];
	int		color;
	int		minimap;
	char	wall_face;
	float	offset;
	int		error;
	int		ratio_map;
}	t_game;

#endif
