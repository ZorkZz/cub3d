/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:15:02 by astachni          #+#    #+#             */
/*   Updated: 2023/09/17 17:27:15 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

typedef struct s_bresenham
{
	int	p0x;
	int	p0y;
	int	p1x;
	int	p1y;
}	t_bresenham;

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
}	t_path;

typedef struct s_color
{
	char	*f;
	char	*c;
}	t_color;

typedef struct s_map
{
	char	**map;
	t_path	path;
	t_color	color;
}	t_map;

typedef struct s_perso
{
	ssize_t	y;
	ssize_t	x;
	float	angle;
}	t_perso;

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_game
{
	t_perso	perso;
	t_map	map;
	void	*mlx;
	void	*win;
	t_img	img;
	int	color;
}	t_game;

#endif
