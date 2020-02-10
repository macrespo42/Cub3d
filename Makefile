NAME = Cub3D

CC = clang

CFLAGS = -Wall -Wextra -Werror -I includes/

HEADER = cube3d.h

LXFLAGS = -lmlx -framework OpenGL -framework AppKit -lm

MLX = libmlx.dylib

SRC = main.c \
	key_hook.c \
	parse_infos.c \
	parse_map.c \
	cam_infos.c \
	draw.c \
	ray.c \
	get_range.c \
	move.c \
	load_xpm.c \
	sprite.c \
	save.c \
	parser.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C mlx_beta/
	cp mlx_beta/$(MLX) .
	$(CC) $(OBJ) -o $(NAME) -L libft -lft $(LXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ) $(MLX)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME) tests/minimap.cub

norm:
	norminette $(SRC) $(HEADER)

.PHONY: all re clean fclean test norm
