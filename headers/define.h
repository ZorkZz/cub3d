/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 01:12:21 by astachni          #+#    #+#             */
/*   Updated: 2023/09/20 01:13:08 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# define SCREEN_W 700
# define SCREEN_H 300

# define KEY_LEFT 65361
# define KEY_UP 65362
# define KEY_RIGHT 65363
# define KEY_DOWN 65364
# define ESCAPE_KEY 65307

# define MOVE_SPEED 25
# define ROTATION_SPEED 0.05

# define FOV (M_PI / 3.0)
# define HALF_FOV = (FOV / 2.0)
# define NUM_RAYS = (WIDTH / 2)
# define HALF_NUM_RAYS = (NUM_RAYS / 2)
# define DELTA_ANGLE = (FOV / NUM_RAYS)

#endif