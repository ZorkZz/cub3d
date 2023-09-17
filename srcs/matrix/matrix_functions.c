/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:59:42 by gurodrig          #+#    #+#             */
/*   Updated: 2023/04/14 12:59:43 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	translation_matrix(t_mat4 *m, float tx, float ty, float tz)
{
	m->tab[0][0] = 1;
	m->tab[0][1] = 0;
	m->tab[0][2] = 0;
	m->tab[0][3] = 0;
	m->tab[1][0] = 0;
	m->tab[1][1] = 1;
	m->tab[1][2] = 0;
	m->tab[1][3] = 0;
	m->tab[2][0] = 0;
	m->tab[2][1] = 0;
	m->tab[2][2] = 1;
	m->tab[2][3] = 0;
	m->tab[3][0] = tx;
	m->tab[3][1] = ty;
	m->tab[3][2] = tz;
	m->tab[3][3] = 1;
}

void	scaling_matrix(t_mat4 *m, float scale)
{
	m->tab[0][0] = scale;
	m->tab[0][1] = 0;
	m->tab[0][2] = 0;
	m->tab[0][3] = 0;
	m->tab[1][0] = 0;
	m->tab[1][1] = scale;
	m->tab[1][2] = 0;
	m->tab[1][3] = 0;
	m->tab[2][0] = 0;
	m->tab[2][1] = 0;
	m->tab[2][2] = scale;
	m->tab[2][3] = 0;
	m->tab[3][0] = 0;
	m->tab[3][1] = 0;
	m->tab[3][2] = 0;
	m->tab[3][3] = 1;
}

void	rotation_x_matrix(t_mat4 *m, float a)
{
	m->tab[0][0] = 1;
	m->tab[0][1] = 0;
	m->tab[0][2] = 0;
	m->tab[0][3] = 0;
	m->tab[1][0] = 0;
	m->tab[1][1] = cos(a);
	m->tab[1][2] = sin(a);
	m->tab[1][3] = 0;
	m->tab[2][0] = 0;
	m->tab[2][1] = -sin(a);
	m->tab[2][2] = cos(a);
	m->tab[2][3] = 0;
	m->tab[3][0] = 0;
	m->tab[3][1] = 0;
	m->tab[3][2] = 0;
	m->tab[3][3] = 1;
}

void	rotation_y_matrix(t_mat4 *m, float a)
{
	m->tab[0][0] = cos(a);
	m->tab[0][1] = 0;
	m->tab[0][2] = -sin(a);
	m->tab[0][3] = 0;
	m->tab[1][0] = 0;
	m->tab[1][1] = 1;
	m->tab[1][2] = 0;
	m->tab[1][3] = 0;
	m->tab[2][0] = sin(a);
	m->tab[2][1] = 0;
	m->tab[2][2] = cos(a);
	m->tab[2][3] = 0;
	m->tab[3][0] = 0;
	m->tab[3][1] = 0;
	m->tab[3][2] = 0;
	m->tab[3][3] = 1;
}

void	rotation_z_matrix(t_mat4 *m, float a)
{
	m->tab[0][0] = cos(a);
	m->tab[0][1] = sin(a);
	m->tab[0][2] = 0;
	m->tab[0][3] = 0;
	m->tab[1][0] = -sin(a);
	m->tab[1][1] = cos(a);
	m->tab[1][2] = 0;
	m->tab[1][3] = 0;
	m->tab[2][0] = 0;
	m->tab[2][1] = 0;
	m->tab[2][2] = 1;
	m->tab[2][3] = 0;
	m->tab[3][0] = 0;
	m->tab[3][1] = 0;
	m->tab[3][2] = 0;
	m->tab[3][3] = 1;
}
