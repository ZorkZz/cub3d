/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:58:25 by astachni          #+#    #+#             */
/*   Updated: 2023/10/28 20:46:12 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	free_path(t_path path)
{
	if (path.is_free == 0)
	{
		if (path.ea != NULL)
			free(path.ea);
		if (path.so != NULL)
			free(path.so);
		if (path.we != NULL)
			free(path.we);
		if (path.no != NULL)
			free(path.no);
	}
	path.is_free = 1;
	path.ea = NULL;
	path.so = NULL;
	path.we = NULL;
	path.no = NULL;
}
