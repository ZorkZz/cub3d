/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:20:02 by astachni          #+#    #+#             */
/*   Updated: 2023/10/28 21:01:53 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	free_color(t_color color)
{
	if (color.is_free == 0)
	{
		if (color.c)
			free(color.c);
		if (color.f)
			free(color.f);
	}
	color.is_free = 1;
	color.c = NULL;
	color.f = NULL;
}
