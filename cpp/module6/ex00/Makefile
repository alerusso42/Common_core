NAME =	 		program
SRC	=	 		main.cpp \
				ScalarConverter.cpp \
				utils.cpp \
				overflow.cpp

LIB_SRC	= 		error/Error.cpp \
	files/sed.cpp \
	math/Point.cpp \
	math/bsp.cpp \
	math/fpoint/Fixed.cpp \
	math/fpoint/fixed_func.cpp \
	math/fpoint/fixed_operator.cpp \
	math/random.cpp \
	strings/input_checker.cpp \
	strings/print.cpp \
	strings/conversion.cpp \

LIB	= 		$(addprefix lib/, $(LIB_SRC))

HEADER = 		header.hpp \
			ScalarConverter.hpp


C =		 g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(HEADER)
	$(C) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all

run: 
	make && ./$(NAME)

val: 
	make && valgrind --track-fds=yes --show-leak-kinds=all --leak-check=full ./$(NAME)
