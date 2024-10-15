NAME = perm

NAME1 = lexi

SRC = perm.c

SRC1 = perm_lexi.c

CFLAGS = -Wall -Wextra -Werror -g

all: $(NAME) $(NAME1)

$(NAME): $(SRC) Makefile
	clang $(CFLAGS) $(SRC) -o $(NAME)

$(NAME1): $(SRC1) Makefile
	clang $(CFLAGS) $(SRC1) -o $(NAME1)

clean:
	rm -rf $(NAME)
	rm -rf $(NAME1)

.PHONY: all clean
