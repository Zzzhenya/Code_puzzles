NAME = sandbox

SRC = main.c

all: fclean $(NAME)

$(NAME): $(SRC)
	clang -Wall -Wextra -Werror $(SRC) -o $(NAME)

fclean:
	rm -rf $(NAME)