/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:15:02 by astachni          #+#    #+#             */
/*   Updated: 2023/09/14 16:04:20 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H

# define STRUCT_H

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
}	t_perso;

typedef struct s_game
{
	t_perso	perso;
	t_map	map;
}	t_game;

#endif