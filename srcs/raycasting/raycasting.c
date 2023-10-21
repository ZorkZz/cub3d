#include "../../headers/cub3d.h"

void trace_ray(t_game *game, float ray_angle, float depth);

int is_wall(t_game *game, float fx, float fy)
{
	int x;
	int y;

	x = fx;
	y = fy;
	if (x < 0 || y < 0 || x >= game->map.width || y >= game->map.height)
		return (0);
	return (game->map.map[x][y] != '1');
}
void raycast(t_game *game)
{
	float ray_angle;
	float depth;
	float delta_angle;
	//float proj_height;
	float num_rays;
	unsigned x;

	x = SCREEN_W;
	num_rays = SCREEN_W;
	ray_angle = game->perso.angle - HALF_FOV + 0.0001;
	delta_angle = FOV / (num_rays - 1.0);
	while (--x > 0)
	{
		depth = ray_depth(game, ray_angle);
		if (game->debug)
			trace_ray(game, ray_angle, depth);
//		proj_height = SCREEN_DIST / (depth + 0.00001);
//		printf("%f, ", i * SCALE);
//		printf("%f, ", (SCREEN_W / 2) - proj_height);
//		printf("%f, ", SCALE);
//		printf("%f\n", proj_height);
//		draw_rectangle(game, i * SCALE, (SCREEN_H / 2) - proj_height / 2, SCALE, proj_height);
		ray_angle += delta_angle;
		get_to_draw(game, depth, x);
	}
}

void trace_ray(t_game *game, float ray_angle, float depth)
{
	t_point start;
	t_point end;

	game->color = 0x0BD09A7;
	start.x = game->perso.x * 10;
	start.y = game->perso.y * 10;
	end.x = (game->perso.x + depth * cos(ray_angle)) * 10;
	end.y = (game->perso.y + depth * sin(ray_angle)) * 10;
	draw_line(game, start, end);
}

float ray_depth(t_game *game, float ray_angle)
{
	float h;
	float v;
	float cos_a;
	float sin_a;

	cos_a = cos(ray_angle);
	sin_a = sin(ray_angle);
	h = horizontal_depth(game, cos_a, sin_a);
	v = vertical_depth(game, cos_a, sin_a);
	if (h > v)
		return (v);
	return (h);
}

float horizontal_depth(t_game *game, float cos_a, float sin_a)
{
	t_fpoint d;
	t_fpoint hor;
	float depth;
	float delta_depth;
	unsigned i;

	hor.y = ((int)game->perso.y) - 0.0001;
	d.y = -1;
	if (sin_a > 0)
	{
		hor.y = ((int)game->perso.y) + 1;
		d.y = 1;
	}
	depth = (hor.y - game->perso.y) / sin_a;
	hor.x = game->perso.x + depth * cos_a;
	delta_depth = d.y / sin_a;
	d.x = delta_depth * cos_a;
	i = 0;
	while (i++ < 10 && is_wall(game, hor.x, hor.y))
	{
		hor.x += d.x;
		hor.y += d.y;
		depth += delta_depth;
		// if (game->color == 0x0430000 && is_wall(game, hor.x, hor.y) == 1)
		// {
		// 	if (game->perso.x >= hor.x)
		// 		game->color = 0x0FF0000;
		// 	else
		// 		game->color = 0x0001AFF;
		// }
	}
	return (depth);
}
float	vertical_depth(t_game *game, float cos_a, float sin_a)
{
	t_fpoint		d;
	t_fpoint		ray;
	float			depth;
	float			delta_depth;
	unsigned int	i;

	ray.x = ((int)game->perso.x) - 0.0001;
	d.x = -1;
	if (cos_a > 0)
	{
		ray.x = ((int)game->perso.x) + 1;
		d.x = 1;
	}
	depth = (ray.x - game->perso.x) / cos_a;
	ray.y = game->perso.y + depth * sin_a;
	delta_depth = d.x / cos_a;
	d.y = delta_depth * sin_a;
	i = 0;
	while (i++ < 10 && is_wall(game, ray.x, ray.y))
	{
		ray.x += d.x;
		ray.y += d.y;
		depth += delta_depth;
		// if (game->color == 0x0430000 && is_wall(game, ray.x, ray.y) == 1)
		// {
		// 	if (game->perso.y >= ray.y)
		// 		game->color = 0x0FF0000;
		// 	else
		// 		game->color = 0x0001AFF;
		// }
	}
	return (depth);
}
