NAME = picoshell

SRC = main.c 

CFLAGS = -Wall -Wextra -Werror -g

all: fclean $(NAME)

$(NAME): $(SRC) Makefile
	clang $(CFLAGS) $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)
