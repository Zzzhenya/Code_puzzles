NAME = knp

SRC = knp.c

all: $(NAME)


$(NAME): $(SRC)
	clang -Wall -Wextra -Werror -g -lm $(SRC) -o $(NAME)

run: $(NAME) sample.txt
	./$(NAME) < sample.txt

.PHONY: all run