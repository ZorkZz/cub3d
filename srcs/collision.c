/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 11:22:08 by astachni          #+#    #+#             */
/*   Updated: 2023/11/27 11:22:08 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/cub3d.h"

static int	circle_square(float cx, float cy, int rx, int ry)
{
	float	edgex;
	float	edgey;
	float	dist;

	edgex = cx;
	edgey = cy;
	if (cx < rx)
		edgex = rx;
	else if (cx > rx + 1)
		edgex = rx + 1;
	if (cy < ry)
		edgey = ry;
	else if (cy > ry + 1)
		edgey = ry + 1;
	dist = sqrt(pow(cx - edgex, 2) + pow(cy - edgey, 2));
	return (dist <= PLAYER_SIZE);
}

int	can_moov(char **map, float x, float y)
{
	t_point	coor;
	int		i;
	int		j;

	i = -1;
	while (i <= 1)
	{
		j = -1;
		while (j <= 1)
		{
			coor.x = round(x) + i;
			coor.y = round(y) + j;
			if (coor.x >= 0 && coor.x < ft_strslen(map) && coor.y >= 0 && \
				(float)coor.y < ft_strlen(map[(int) x]))
			{
				if (map[coor.x][coor.y] == '1' || map[coor.x][coor.y] == ' ' || \
					map[coor.x][coor.y] == ' ')
					if (circle_square(x, y, coor.x, coor.y) == 1)
						return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
