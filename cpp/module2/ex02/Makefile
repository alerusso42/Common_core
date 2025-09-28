NAME =	 		fixed
SRC	=	 		main.cpp
LIB_SRC	= 		files/sed.cpp \
	strings/input_checker.cpp \
	$(addprefix math/fpoint/, \
				fixed_func.cpp \
				fixed_operator.cpp \
				Fixed.cpp)
LIB	= 		$(addprefix lib/, $(LIB_SRC))
HEADER = 		header.hpp

C =		 g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(HEADER)
	$(C) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	@printf "no objects for %s\n" "$(NAME)"

fclean:
	rm -rf $(NAME)

re: fclean all
