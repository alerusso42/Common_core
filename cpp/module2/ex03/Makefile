NAME =	 		bsp
SRC	=	 		main.cpp
LIB_SRC	= 		files/sed.cpp \
	math/fpoint/Fixed.cpp \
	math/fpoint/fixed_func.cpp \
	math/fpoint/fixed_operator.cpp \
	math/bsp.cpp \
	math/Point.cpp \
	strings/input_checker.cpp
LIB	= 		$(addprefix lib/, $(LIB_SRC))
HEADER = 		header.hpp \
			lib/math/Point.hpp \
			lib/math/fpoint/Fixed.hpp

C =		 c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC) $(LIB)  
	echo $(LIB)
	$(C) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	@printf "no objects for %s\n" "$(NAME)"

fclean:
	rm -rf $(NAME)

re: fclean all

run: 
	make && ./$(NAME)

val: 
	make && valgrind --track-fds=yes --show-leak-kinds=all --leak-check=full ./$(NAME)

gdb:
	make && gdb --q $(NAME)
