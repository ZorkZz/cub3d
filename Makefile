NAME = cub3D

OBJS_DIR = .objs/

SRCS_PARSING = srcs/parsing/parsing.c srcs/parsing/get_map.c srcs/parsing/get_infos_perso.c srcs/parsing/verify_map.c srcs/parsing/get_path_color.c srcs/parsing/color_to_int.c srcs/parsing/diffusion.c

SRCS_FREE = srcs/free/free_path.c srcs/free/free_parsing.c srcs/free/free_strs.c srcs/free/free_color.c srcs/free/free_textures.c srcs/free/free_sprite.c

SRCS_UTILS = srcs/utils/ft_strsdup.c srcs/utils/ft_strslen.c

SRCS_WINDOW = srcs/window.c

SRCS_RENDERING = srcs/rendering/draw.c srcs/rendering/draw_line.c

SRCS_CONTROL = srcs/key.c srcs/player_control.c

SRCS_RAYCASTING = srcs/raycasting/fill_img_with_ray.c srcs/raycasting/color_sprite.c srcs/raycasting/raycasting.c

SRCS = srcs/main.c $(SRCS_PARSING) $(SRCS_FREE) $(SRCS_UTILS) $(SRCS_WINDOW) $(SRCS_RENDERING) $(SRCS_CONTROL) $(SRCS_RAYCASTING)

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.zizi)

LIBS = libs/libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3 -O3 -fsanitize=address

RM = rm -f

HEADER = headers/cub3d.h headers/proto.h headers/struct.h headers/define.h

ifeq ($(shell uname -s), Linux)
INCLUDE_FLAGS = -I/usr/include -Ilibs/mlx_linux

MLX_FLAGS = -Llibs/mlx_linux -lmlx_Linux -L/usr/lib -Ilibs/mlx_linux -lXext -lX11 -lm -lz

PATH_MLX = libs/mlx_linux

else
INCLUDE_FLAGS =

MLX_FLAGS = -L./libs/mlx -lmlx -framework OpenGL -framework AppKit

PATH_MLX = mlx

endif

all: mlx libft create_dir $(NAME) norm

$(LIBS):
	$(MAKE) -C libs/libft all

$(OBJS_DIR)%.zizi: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@
	@printf	"\033[1;33m \r\033[2KCreating -c $< -o $\n \033[0m"

$(NAME):	$(OBJS) $(LIBS) $(HEADER)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
			@printf	"\033[1;32m \r\033[2KCompiling $(NAME) : DONE \n \033[0m"

create_dir:
	@mkdir -p .objs/srcs/free
	@mkdir -p .objs/srcs/parsing
	@mkdir -p .objs/srcs/raycasting
	@mkdir -p .objs/srcs/rendering
	@mkdir -p .objs/srcs/utils

libft:
	@$(MAKE) -C libs/libft

mlx:
	@$(MAKE) -C $(PATH_MLX)
	@printf	"\033[1;33m \r\033[2KCreating mlx file$\n \033[0m"
	@printf	"\033[1;32m \r\033[2KCompiling mlx : DONE \n \033[0m"

clean:
	@make clean -C libs/libft
	@make clean -C $(PATH_MLX)
	$(RM) $(OBJS)
	@rm -rf .objs

fclean: clean
	make fclean -C libs/libft
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

norm:
	@if norminette srcs headers | grep 'Error'; then \
        echo "\033[1;33m \r\033[2Knorm error \033[0m"; \
    else \
        echo "\033[1;32mYou are a genius \033[0m"; \
    fi

.PHONY:	all bonus clean fclean re libft mlx gnl printf
