/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:24:52 by astachni          #+#    #+#             */
/*   Updated: 2023/11/01 11:53:40 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../headers/cub3d.h"

void trace_ray(t_game *game, float ray_angle, float depth);
static void	start_raycast(t_game *game);
static void	*raycast_thread(void *param);

void	create_threads(t_game *game)
{
	game->fill_image_mutex = malloc(sizeof(pthread_mutex_t));
	*game->fill_image_mutex = (pthread_mutex_t)PTHREAD_MUTEX_INITIALIZER;
	pthread_mutex_init(game->fill_image_mutex, NULL);
	game->threads = malloc(sizeof(pthread_t) * A);
	start_raycast(game);
	pthread_mutex_destroy(game->fill_image_mutex);
	free(game->fill_image_mutex);
	free(game->threads);
}

t_game	cpy_game(t_game *game, t_game game_cpy)
{
	game_cpy.color = game->color;
	game_cpy.debug = game->debug;
	game_cpy.img = game->img;
	game_cpy.img.addr = game->img.addr;
	game_cpy.mlx = game->mlx;
	game_cpy.offset = game->offset;
	game_cpy.perso = game->perso;
	game_cpy.perso.angle = game->perso.angle;
	game_cpy.perso.x = game->perso.x;
	game_cpy.perso.y = game->perso.y;
	game_cpy.sprite[0] = game->sprite[0];
	game_cpy.sprite[1] = game->sprite[1];
	game_cpy.sprite[2] = game->sprite[2];
	game_cpy.sprite[3] = game->sprite[3];
	game_cpy.win = game->win;
	game_cpy.fill_image_mutex = game->fill_image_mutex;
	game_cpy.map.map = game->map.map;
	game_cpy.map.height = game->map.height;
	game_cpy.map.width = game->map.width;
	game_cpy.map.color.c_int = game->map.color.c_int;
	game_cpy.map.color.f_int = game->map.color.f_int;
	game_cpy.threads = game->threads;
	game_cpy.wall_face = game->wall_face;
	return (game_cpy);
}

static void	start_raycast(t_game *game)
{
	int		i;

	i = 0;
	while (i < A)
	{
		game_cpy.nb_thread = i + 1;
		pthread_create(&game->threads[i], NULL, raycast_thread, &game_cpy);
		//ft_printf("%d, %d\n", game_cpy.nb_thread, i);
		i++;
	}
	i = 0;
	while (i < 2)
		pthread_join(game->threads[i++], NULL);
}

static void	*raycast_thread(void *param)
{
	float			ray_angle;
	float			depth;
	float			delta_angle;
	float			num_rays;
	unsigned int	x;
	unsigned int	end;
	t_game			*game;

	game = param;
	x = SCREEN_W / game->nb_thread;
	end = game->nb_thread * (SCREEN_W / A);
	num_rays = SCREEN_W;
	ray_angle = game->perso.angle - HALF_FOV + 0.0001;
	delta_angle = FOV / (num_rays - 1.0);
	ft_printf("%p, %d\n", game, game->nb_thread);
	pthread_exit(NULL);
	while (--x > end)
	{
		depth = ray_depth(game, ray_angle);
		depth *= cos(game->perso.angle - ray_angle);
		get_to_draw(game, depth, x);
		if (game->debug)
			trace_ray(game, ray_angle, depth);
		ray_angle += delta_angle;
	}
	free(game);
	pthread_exit(NULL);
}
