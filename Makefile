NAME = cub3d

OBJS_DIR = .objs/

SRCS = srcs/main.c srcs/parsing/parsing.c srcs/parsing/get_map.c srcs/parsing/get_infos_perso.c srcs/parsing/verify_map.c srcs/free/free_path.c srcs/free/free_parsing.c srcs/utils/ft_strsdup.c srcs/free/free_strs.c srcs/free/free_color.c srcs/window.c srcs/rendering/draw.c srcs/key.c srcs/player_control.c srcs/rendering/draw_line.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)

LIBS = libs/libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

HEADER = headers/cub3d.h headers/proto.h headers/struct.h

ifeq ($(shell uname -s), Linux)
INCLUDE_FLAGS = -I/usr/include -Ilibs/mlx_linux -O3

MLX_FLAGS = -Llibs/mlx_linux -lmlx_Linux -L/usr/lib -Ilibs/mlx_linux -lXext -lX11 -lm -lz

PATH_MLX = libs/mlx_linux

else
INCLUDE_FLAGS =

MLX_FLAGS = -L./libs/mlx -lmlx -framework OpenGL -framework AppKit

PATH_MLX = mlx

endif

all: mlx libft $(NAME)

$(LIBS):
	$(MAKE) -C libs/libft all

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	@$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@
	@printf	"\033[1;33m \r\033[2KCreating -c $< -o $\n \033[0m"

$(NAME):	$(OBJS) $(LIBS) $(HEADER)
			@$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
			@printf	"\033[1;32m \r\033[2KCompiling $(NAME) : DONE \n \033[0m"

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
