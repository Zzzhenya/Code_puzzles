NAME = rip

SRC = rip.c

NAME1 = 2rip

SRC1 = rip2.c

all: fclean $(NAME) $(NAME1)

$(NAME): $(SRC)
	cc -Wall -Wextra -Werror -lm $(SRC) -o $(NAME)

$(NAME1): $(SRC1)
	cc -Wall -Wextra -Werror -lm $(SRC1) -o $(NAME1)

fclean:
	rm -rf $(NAME)
	rm -rf $(NAME1)