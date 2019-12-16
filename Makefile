NAME = Cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = cube3d.h

SRC = main.c \
	close_window.c \
	get_column.c \
	key_hook.c \
	ft_isspace.c \
	get_color.c \
	get_next_line_utils.c \
	get_next_line.c \
	get_path.c \
	get_resolution.c \
	parser.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -lmlx -framework OpenGL -framework AppKit $(OBJ) -o $(NAME)

linux: $(OBJ)
	gcc -lm -lmlx -lXext -lX11 -L ./libft.a -lpthread $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: re
	./$(NAME)

norm:
	norminette $(SRC) $(HEADER)

.PHONY: all re clean fclean test norm
