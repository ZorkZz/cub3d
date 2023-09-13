NAME = cub3d

OBJS_DIR = .objs/

SRCS = srcs/main.c

OBJS = $(SRCS:%.c=$(OBJS_DIR)%.o)
OBJS_BONUS = $(SRCS_BONUS:%.c=$(OBJS_DIR)%.o)

LIBS = libs/libft/libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror -g3

RM = rm -f

HEADER = headers/cub3d.h

ifeq ($(shell uname -s), Linux)
INCLUDE_FLAGS = -I/usr/include -Imlx_linux -O3

MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

PATH_MLX = mlx_linux

else
INCLUDE_FLAGS =

MLX_FLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

PATH_MLX = mlx

endif

all: mlx $(CREATE_FOLDER) $(NAME)

$(LIBS):
	$(MAKE) -C libs/libft all

$(OBJS_DIR)%.o: %.c $(HEADER) Makefile
	$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(NAME):	$(OBJS) $(LIBS) $(HEADER)
			$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLX_FLAGS) -o $(NAME)
			@norminette main.c srcs/*.c header/*.h

clean:
	@make clean -C libs/libft
	@make clean -C $(PATH_MLX)
	$(RM) $(OBJS)

fclean: clean
	make fclean -C libs/libft
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY:	all bonus clean fclean re libft mlx gnl printf
