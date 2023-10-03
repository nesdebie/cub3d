NAME = cub3d

SRCS = 	src/main.c \
		src/errors.c \
		src/reader.c \
		src/reader_utils.c \
		src/ft_free.c \
		src/checker.c

OBJS 	= $(SRCS:.c=.o)

OBJDIR	= obj

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
	mkdir $(OBJDIR)
	mv $(OBJS) $(OBJDIR)

clean:
	make clean -C ./libft
	make clean -C ./mlx
	$(RM) $(OBJS) $(OBJDIR)

fclean: 	clean
	make fclean -C ./libft
	$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re