NAME = cub3D
NAME_B = cub3D_bonus

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
		src/init/init_wall_textures.c \
		src/moves/keys_flags.c \
		src/moves/rotate.c \
		src/moves/moves.c \
		src/moves/validate_moves.c \
		src/display/display_map.c \
		src/display/display_pov.c \
		src/display/dda.c \
		src/display/raycasting.c

SRCS_B =	src/main.c \
		src/close_game.c \
		src/errors.c \
		src/parsing/parsing.c \
		src/parsing/file_checker.c \
		src/parsing/file_checker_utils.c \
		src/parsing/map_checker_bonus.c \
		src/parsing/map_checker_utils.c \
		src/parsing/textures_checker.c \
		src/ft_free.c \
		src/init/init_pre_loop.c \
		src/init/init_during_loop.c \
		src/init/init_wall_textures.c \
		src/moves/keys_flags.c \
		src/moves/rotate.c \
		src/moves/moves.c \
		src/moves/validate_moves.c \
		src/display/display_map.c \
		src/display/display_pov.c \
		src/display/dda_bonus.c \
		src/display/raycasting_bonus.c

OBJS 	= $(SRCS:.c=.o)

OBJS_B 	= $(SRCS_B:.c=.o)

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror -O3 -flto -ffast-math -march=native

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit -Lmlx

.c.o:		%.o : %.c
	@${CC} ${CFLAGS} -Imlx -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJS)
	make -C ./libft
	make -C ./mlx
	$(CC) $(OBJS) $(MLXFLAGS) -Llibft -lft -o $(NAME)


bonus:		$(OBJS_B)
	make -C ./libft
	make -C ./mlx
	$(CC) $(OBJS_B) $(MLXFLAGS) -Llibft -lft -o $(NAME_B)

clean:
	make clean -C ./libft
	make clean -C ./mlx
	rm -f $(OBJS) $(OBJS_B)

fclean: 	clean
	make fclean -C ./libft
	rm -f $(NAME) $(NAME)_bonus

re:			fclean all

.PHONY:	all clean fclean re bonus