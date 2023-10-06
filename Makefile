NAME = cub3d

SRCS = 	src/main.c \
		src/errors.c \
		src/reader.c \
		src/reader_utils.c \
		src/ft_free.c \
		src/checker.c \
		src/checker_utils.c

OBJS 	= $(SRCS:.c=.o)

RM		= rm -rf

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

MLXFLAGS = -framework OpenGL -framework AppKit -Lmlx

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