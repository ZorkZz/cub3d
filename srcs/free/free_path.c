/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 15:58:25 by astachni          #+#    #+#             */
/*   Updated: 2023/09/14 15:59:46 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	free_path(t_path path)
{
	if (path.ea)
		free(path.ea);
	if (path.so)
		free(path.so);
	if (path.we)
		free(path.we);
	if (path.no)
		free(path.no);
}
