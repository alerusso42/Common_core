NAME := a.out
FILE := test_file
LIBFT := libft.a

SRC := $(shell ls ./srcs/*.c ./srcs/functions/*.c ./srcs/utils/*.c)

comp := cc -Wall -Wextra -Werror -g\
		$(SRC) $(LIBFT) -o $(NAME)


$(NAME): $(SRC)
	$(comp)

all: $(NAME)
	

clean: 


fclean:
	rm -f a.out

re: fclean $(NAME)


run: $(NAME)
	clear ; ./a.out

print: $(NAME)
	./a.out > $(FILE)

gdb: $(NAME)
	gdb -q ./a.out

val: $(NAME)
	valgrind --track-origins=yes --show-leak-kinds=all --leak-check=full ./a.out

libft:
	(cd ../../Libft/Libft/ && make re && cp libft.a $$OLDPWD && make fclean)