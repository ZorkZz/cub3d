/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:33:55 by astachni          #+#    #+#             */
/*   Updated: 2023/11/16 11:57:19 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

t_color	get_c_int(t_color *color)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = 0;
	while (color->c && color->c[++i])
	{
		if (i == 0 || (i > 0 && color->c[i - 1] == ','))
		{
			color->c_int_tab[j] = ft_atoi(&color->c[i]);
			if (color->c_int_tab[j] < 0 || color->c_int_tab[j] > 255)
				return (color->c_int = -1, *color);
			j++;
		}
	}
	if (j != 3)
		return (color->c_int = -1, *color);
	color->c_int = (color->c_int_tab[0] << 16) | (color->c_int_tab[1] << 8) | \
		color->c_int_tab[2];
	return (*color);
}

t_color	get_f_int(t_color *color)
{
	ssize_t	i;
	ssize_t	j;

	i = -1;
	j = 0;
	while (color->f && color->f[++i])
	{
		if (i == 0 || (i > 0 && color->f[i - 1] == ','))
		{
			color->f_int_tab[j] = ft_atoi(&color->f[i]);
			if (color->f_int_tab[j] < 0 || color->f_int_tab[j] > 255)
				return (color->f_int = -1, *color);
			j++;
		}
	}
	if (j != 3)
		return (color->f_int = -1, *color);
	color->f_int = (color->f_int_tab[0] << 16) | (color->f_int_tab[1] << 8) | \
		color->f_int_tab[2];
	return (*color);
}
