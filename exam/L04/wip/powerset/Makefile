NAME = powerset

SRC = powerset.c

all: fclean $(NAME)

$(NAME): $(SRC) Makefile
	clang -Wextra -Wall -Werror $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)

