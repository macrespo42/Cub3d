NAME = Cub3D

CC = clang

CFLAGS = -Wall -Wextra -Werror -I includes/

HEADER = cube3d.h

LXFLAGS = -framework OpenGL -framework AppKit

MLX = minilibx_opengl

SRC = main.c \
	key_hook.c \
	ft_isspace.c \
	parse_infos.c \
	parse_map.c \
	get_wall_dist.c \
	cam_infos.c \
	draw.c \
	move.c \
	ray.c \
	parser.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@make -C minilibx_opengl/
	$(CC) $(OBJ) -o $(NAME) -L libft -lft -L $(MLX) -lmlx $(LXFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./$(NAME) tests/minimap.cub

norm:
	norminette $(SRC) $(HEADER)

.PHONY: all re clean fclean test norm
