NAME := a.out
FILE := test_file

SRC := $(shell ls ./srcs/*.c ./srcs/functions/*.c)

comp := cc -Wall -Wextra -Werror -g \
		$(SRC) libft.a -o $(NAME)


$(NAME): $(SRC)
	$(comp)

run: $(NAME)
	./a.out

print: $(NAME)
	./a.out > $(FILE)

gdb: $(NAME)
	gdb -q ./a.out

val: $(NAME)
	valgrind --track-origins=yes --show-leak-kinds=all --leak-check=full ./a.out