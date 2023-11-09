NAME = cub3d

SRCS = 	src/main.c \
		src/close_game.c \
		src/errors.c \
		src/parsing/parsing.c \
		src/parsing/file_checker.c \
		src/parsing/file_checker_utils.c \
		src/parsing/map_checker.c \
		src/parsing/map_checker_utils.c \
		src/parsing/textures_checker.c \
		src/ft_free.c \
		src/init/init_pre_loop.c \
		src/init/init_during_loop.c \
		src/moves/keys_flags.c \
		src/moves/rotate.c \
		src/moves/moves.c \
		src/moves/validate_moves.c \
		src/images/draw_map.c \
		src/images/display_pov.c \
		src/images/dda.c \
		src/images/raycasting.c

OBJS 	= $(SRCS:.c=.o)

RM		= rm -rf

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror -O3 -flto -ffast-math #-march=native 

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -Lmlx

%.o : %.c
	$(CC) $(CFLAGS) -Imlx -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJS)
	make -C ./libft
	make -C ./mlx
	$(CC) $(OBJS) $(MLXFLAGS) -Llibft -lft -o $(NAME)

clean:
	make clean -C ./libft
	make clean -C ./mlx
	$(RM) $(OBJS)

fclean: 	clean
	make fclean -C ./libft
	$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re