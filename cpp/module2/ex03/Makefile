NAME =	 		bsp
SRC	=	 		main.cpp \
				Point.cpp
LIB_SRC	= 		files/sed.cpp \
	math/fpoint/Fixed.cpp \
	math/fpoint/fixed_func.cpp \
	math/fpoint/fixed_operator.cpp \
	strings/input_checker.cpp
LIB	= 		$(addprefix lib/, $(LIB_SRC))
HEADER = 		header.hpp \
			Point.hpp \
			lib/math/fpoint/Fixed.hpp

C =		 g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(HEADER)
	echo $(LIB)
	$(C) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

run: 
	make && ./$(NAME)

val: 
	make && valgrind --track-fds=yes --show-leak-kinds=all --leak-check=full ./$(NAME)

gdb:
	make && gdb --q $(NAME)
