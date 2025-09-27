NAME =	 		program
SRC	=	 		main.cpp \
				A.cpp \
				B.cpp \
				C.cpp \
				Base.cpp

LIB_SRC	= 		error/Error.cpp \
	files/sed.cpp \
	math/bsp.cpp \
	math/fpoint/Fixed.cpp \
	math/fpoint/fixed_func.cpp \
	math/fpoint/fixed_operator.cpp \
	math/Point.cpp \
	math/random.cpp \
	strings/conversion.cpp \
	strings/input_checker.cpp \
	strings/print.cpp \

LIB	= 		$(addprefix lib/, $(LIB_SRC))

HEADER = 		header.hpp \
			A.hpp \
			B.hpp \
			C.hpp \
			Base.hpp


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
