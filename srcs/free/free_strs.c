/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_strs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 16:14:27 by astachni          #+#    #+#             */
/*   Updated: 2023/09/14 16:15:37 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void	free_strs(char **strs)
{
	ssize_t	i;

	i = 0;
	while (strs && strs[i])
		free(strs[i++]);
	if (strs)
		free(strs);
}
