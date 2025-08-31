NAME	=	sed
SRC		=	main.cpp
LIB_SRC =	strings/cut_string.cpp strings/input_checker.cpp
LIB		=	$(addprefix lib/, $(LIB_SRC))
HEADER	=	sed.hpp

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) $(LIB) $(HEADER) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all