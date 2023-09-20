/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:20:02 by astachni          #+#    #+#             */
/*   Updated: 2023/09/20 14:15:22 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	free_color(t_color color)
{
	if (color.c)
		free(color.c);
	if (color.f)
		free(color.f);
	color.c = NULL;
	color.f = NULL;
}
