NAME = cube3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADER = cube3d.h

SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc -lmlx -framework OpenGL -framework AppKit $(SRC) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

test: all
	./cube3d

norm:
	norminette $(SRC) $(HEADER)

.PHONY: all re clean fclean test norm
