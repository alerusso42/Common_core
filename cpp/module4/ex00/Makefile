NAME =	 		program
SRC	=	 		main.cpp \
				Animal.cpp \
				Dog.cpp \
				Cat.cpp \
				WrongAnimal.cpp \
				WrongCat.cpp

LIB_SRC	= 		files/sed.cpp \
	math/bsp.cpp \
	math/fpoint/Fixed.cpp \
	math/fpoint/fixed_func.cpp \
	math/fpoint/fixed_operator.cpp \
	math/Point.cpp \
	math/random.cpp \
	strings/input_checker.cpp \

LIB	= 		$(addprefix lib/, $(LIB_SRC))

HEADER = 		header.hpp \
			Animal.hpp \
			Dog.hpp \
			Cat.hpp \
			WrongAnimal.hpp \
			WrongCat.hpp


C =		 c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC) $(LIB)  
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
