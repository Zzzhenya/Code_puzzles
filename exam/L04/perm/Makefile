NAME = perm

NAME1 = lexi

NAME2 = 1perm

SRC = perm.c

SRC1 = perm_lexi.c

SRC2 = perm1.c

CFLAGS = -Wall -Wextra -Werror -g

all: clean $(NAME) $(NAME1) $(NAME2)

$(NAME): $(SRC) Makefile
	clang $(CFLAGS) $(SRC) -o $(NAME)

$(NAME1): $(SRC1) Makefile
	clang $(CFLAGS) $(SRC1) -o $(NAME1)

$(NAME2): $(SRC2) Makefile
	clang $(CFLAGS) $(SRC2) -o $(NAME2)

clean:
	rm -rf $(NAME)
	rm -rf $(NAME1)
	rm -rf $(NAME2)

.PHONY: all clean
