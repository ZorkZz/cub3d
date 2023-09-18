#include "../headers/cub3d.h"

static void	draw_line_more_vertical(t_bresenham *b, t_game *game)
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
		game_put_pixel(game, b->p0x, b->p0y);
		if (error > 0)
		{
			b->p0x = b->p0x + way_x;
			error -= 2 * delta[1];
		}
		error += 2 * delta[0];
		b->p0y = b->p0y + 1;
	}
}

static void	draw_line_more_horizontal(t_bresenham *b, t_game *game)
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
		game_put_pixel(game, b->p0x, b->p0y);
		if (error > 0)
		{
			b->p0y = b->p0y + way_y;
			error -= 2 * delta[0];
		}
		error += 2 * delta[1];
		b->p0x = b->p0x + 1;
	}
}

void	init_bresenham(t_bresenham *b, t_point start, t_point end)
{
	b->p0x = start.x;
	b->p0y = start.y;
	b->p1x = end.x;
	b->p1y = end.y;
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

void	draw_line(t_game *game, t_point start, t_point end)
{
	t_bresenham	b;

	init_bresenham(&b, start, end);
	if (abs(b.p1y - b.p0y) < abs(b.p1x - b.p0x))
	{
		if (b.p0x > b.p1x)
			exchange_p0_p1(&b);
		draw_line_more_horizontal(&b, game);
	}
	else
	{
		if (b.p0y > b.p1y)
			exchange_p0_p1(&b);
		draw_line_more_vertical(&b, game);
	}
}
