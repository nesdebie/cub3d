NAME = cub3d

SRCS = 	src/main.c

SRCS_B = 	src/main.c

OBJS 	= $(SRCS:.c=.o)

OBJS_B 	= $(SRCS_B:.c=.o)

CC 		= cc

CFLAGS 	= -Wall -Wextra -Werror

MLXFLAGS = -lmlx -framework OpenGL -framework AppKit

.c.o:		%.o : %.c
	@${CC} ${CFLAGS} -Imlx -c $< -o $@

all: 		$(NAME)

$(NAME):	$(OBJS)
	make re -C ./libft
	$(CC) $(OBJS) $(MLXFLAGS) -Llibft -lft -o $(NAME)


bonus:		$(OBJS_B)
	make re -C ./libft
	$(CC) $(OBJS_B) $(MLXFLAGS) -Llibft -lft -o $(NAME)

clean:
	make clean -C ./libft
	rm -f $(OBJS) $(OBJS_B)

fclean: 	clean
	make fclean -C ./libft
	rm -f $(NAME)

re:			fclean all

.PHONY:	all clean fclean re bonus