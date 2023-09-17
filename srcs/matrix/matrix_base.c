/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_base.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:55:32 by gurodrig          #+#    #+#             */
/*   Updated: 2023/04/14 12:55:34 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

void	free_mat4(t_mat4 *m)
{
	int	i;

	i = 0;
	if (!m)
		return ;
	while (m->tab && i < 4)
		free(m->tab[i++]);
	free(m->tab);
	free(m);
}

int	init_mat4(t_mat4 **m)
{
	int	i;

	*m = malloc(sizeof(t_mat4));
	if (!*m)
		return (0);
	(*m)->tab = malloc(sizeof(float *) * 4);
	if (!(*m)->tab)
		return (free_mat4(*m), 0);
	i = 0;
	while (i < 4)
	{
		(*m)->tab[i] = malloc(sizeof(float) * 4);
		if (!(*m)->tab[i])
			return (free_mat4(*m), 0);
		i++;
	}
	return (1);
}

int	init_vec4(t_vector4 **vec)
{
	int	i;

	*vec = malloc(sizeof(t_vector4));
	if (!*vec)
		return (0);
	(*vec)->tab = malloc(sizeof(float) * 4);
	if (!(*vec)->tab)
		return (free(vec), 0);
	i = 0;
	while (i < 3)
		(*vec)->tab[i++] = 0;
	(*vec)->tab[i] = 1;
	return (1);
}

void	free_v(t_vector4 *vec)
{
	if (vec)
		free(vec->tab);
	free(vec);
}

void	vec_copy(t_vector4 *dst, t_vector4 *src)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		dst->tab[i] = src->tab[i];
		i++;
	}
}
