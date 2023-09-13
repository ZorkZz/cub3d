/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astachni <astachni@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 17:09:47 by astachni          #+#    #+#             */
/*   Updated: 2023/09/13 17:18:52 by astachni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H

# define CUB3D_H

# ifdef __APPLE__
#  include "../mlx/mlx.h"
# elif __linux__
#  include "../mlx_linux/mlx.h"
# endif
# include <stdio.h>
# include <stdlib.h>
# include <stddef.h>
# include <fcntl.h>
# include <math.h>
# include "struct.h"
# include "proto.h"
# include "../libs/libft/libft.h"

#endif