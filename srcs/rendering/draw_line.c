/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gurodrig <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 12:53:45 by gurodrig          #+#    #+#             */
/*   Updated: 2023/04/14 13:23:21 by gurodrig         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"

static void	draw_line_more_vertical(t_bresenham *b, t_fdf *map)
{
	int	delta[2];
	int	way_x;
	int	error;

	delta[0] = b->p1x - b->p0x;
	delta[1] = b->p1y - b->p0y;
	way_x = 1;
	if (delta[0] < 0)
	{
		way_x = -1;
		delta[0] = -delta[0];
	}
	error = 2 * delta[0] - delta[1];
	while (b->p0y < b->p1y)
	{
		my_mlx_put_pixel(map, b->p0x, b->p0y);
		if (error > 0)
		{
			b->p0x = b->p0x + way_x;
			error -= 2 * delta[1];
		}
		error += 2 * delta[0];
		b->p0y = b->p0y + 1;
	}
}

static void	draw_line_more_horizontal(t_bresenham *b, t_fdf *map)
{
	int	delta[2];
	int	way_y;
	int	error;

	delta[0] = b->p1x - b->p0x;
	delta[1] = b->p1y - b->p0y;
	way_y = 1;
	if (delta[1] < 0)
	{
		way_y = -1;
		delta[1] = -delta[1];
	}
	error = 2 * delta[1] - delta[0];
	while (b->p0x < b->p1x)
	{
		my_mlx_put_pixel(map, b->p0x, b->p0y);
		if (error > 0)
		{
			b->p0y = b->p0y + way_y;
			error -= 2 * delta[0];
		}
		error += 2 * delta[1];
		b->p0x = b->p0x + 1;
	}
}

int	init_bresenham(t_bresenham *b, t_vector4 *start, t_vector4 *end)
{
	int	x0;
	int	y0;
	int	x1;
	int	y1;

	x0 = start->tab[0];
	y0 = start->tab[1];
	x1 = end->tab[0];
	y1 = end->tab[1];
	if (x0 < -SCREEN_W * 0.2 || x0 > SCREEN_W * 1.2)
		return (0);
	if (y0 < -SCREEN_H * 0.2 || y0 > SCREEN_H * 1.2)
		return (0);
	if (x1 < -SCREEN_W * 0.2 || x1 > SCREEN_W * 1.2)
		return (0);
	if (y1 < -SCREEN_H * 0.2 || y1 > SCREEN_H * 1.2)
		return (0);
	b->p0x = x0;
	b->p0y = y0;
	b->p1x = x1;
	b->p1y = y1;
	return (1);
}

void	exchange_p0_p1(t_bresenham *b)
{
	int	bufferx;
	int	buffery;

	bufferx = b->p0x;
	buffery = b->p0y;
	b->p0x = b->p1x;
	b->p0y = b->p1y;
	b->p1x = bufferx;
	b->p1y = buffery;
}

void	draw_line(t_fdf *map, t_vector4 *start, t_vector4 *end)
{
	t_bresenham	b;

	if (!init_bresenham(&b, start, end))
		return ;
	if (abs(b.p1y - b.p0y) < abs(b.p1x - b.p0x))
	{
		if (b.p0x > b.p1x)
			exchange_p0_p1(&b);
		draw_line_more_horizontal(&b, map);
	}
	else
	{
		if (b.p0y > b.p1y)
			exchange_p0_p1(&b);
		draw_line_more_vertical(&b, map);
	}
}
