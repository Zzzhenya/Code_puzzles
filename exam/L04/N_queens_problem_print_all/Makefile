NAME = queen

SRC = nqueens.c

all: $(NAME) $(NAME1)


$(NAME): $(SRC) Makefile
	clang -Wextra -Wall -Werror $(SRC) -o $(NAME)

NAME1 = nq

SRC1 = nqueen.c

$(NAME1): $(SRC1) Makefile
	clang -Wextra -Wall -Werror $(SRC1) -o $(NAME1)

fclean:
	rm -rf $(NAME) $(NAME1)