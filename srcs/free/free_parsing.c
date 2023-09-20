/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:50:45 by astachni          #+#    #+#             */
/*   Updated: 2023/09/20 13:52:27 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	free_parsing(t_game game, char **strs)
{
	free_color(game.map.color);
	free_path(game.map.path);
	free_strs(game.map.map);
	free_strs(strs);
}
