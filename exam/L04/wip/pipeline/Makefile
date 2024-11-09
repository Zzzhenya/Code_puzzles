NAME = picoshell

NAME1 = pico

SRC = main.c 

SRC1 = picoshell.c

CFLAGS = -Wall -Wextra -Werror -g

all: fclean $(NAME) $(NAME1)

$(NAME): $(SRC) Makefile
	clang $(CFLAGS) $(SRC) -o $(NAME)

$(NAME1): $(SRC1) Makefile
	clang $(CFLAGS) $(SRC1) -o $(NAME1)

fclean:
	rm -rf $(NAME) $(NAME1)
