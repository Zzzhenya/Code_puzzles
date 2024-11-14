NAME=prog

SRCS=main.cpp Scanner.cpp

HEADER=Scanner.hpp Token.hpp

all:$(NAME)

$(NAME): $(SRCS) $(HEADER) Makefile
	c++ -Wall -Wextra -Werror $(SRCS) -o $(NAME)

fclean:
	rm -rf $(NAME)
