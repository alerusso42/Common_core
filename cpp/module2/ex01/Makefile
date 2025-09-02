NAME =	 		program
SRC	=	 		main.cpp \
				Fixed.cpp
LIB_SRC	= 		files/sed.cpp \
	strings/input_checker.cpp \
LIB	= 		$(addprefix lib/, $(LIB_SRC))
HEADER = 		header.hpp \
			Fixed.hpp

C =		 g++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(HEADER)
	$(C) $(CFLAGS) $(SRC) $(LIB) -o $(NAME)

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all
