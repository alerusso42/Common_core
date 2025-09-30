NAME =	 		trap
SRC	=	 		main.cpp \
				ClapTrap.cpp \
				ScavTrap.cpp \
				FragTrap.cpp

LIB_SRC	= 		files/sed.cpp \
	math/Point.cpp \
	math/bsp.cpp \
	math/fpoint/Fixed.cpp \
	math/fpoint/fixed_func.cpp \
	math/fpoint/fixed_operator.cpp \
	math/random.cpp \
	strings/input_checker.cpp \

LIB	= 		$(addprefix lib/, $(LIB_SRC))

HEADER = 		header.hpp \
			ClapTrap.hpp \
			ScavTrap.hpp \
			FragTrap.hpp


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
