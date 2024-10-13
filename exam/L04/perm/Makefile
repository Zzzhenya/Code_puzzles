NAME = perm

SRC = perm.c

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME): $(SRC) Makefile
	clang $(CFLAGS) $(SRC) -o $(NAME)

clean:
	rm -rf $(NAME)

.PHONY: all clean
