NAME	=	sed
SRC		=	main.cpp
LIB_SRC =	strings/input_checker.cpp \
			files/sed.cpp
LIB		=	$(addprefix lib/, $(LIB_SRC))
HEADER	=	sed.hpp

all: $(NAME)

$(NAME): $(SRC) $(LIB)  
	c++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) $(LIB)   -o $(NAME)

clean:
	@printf "no objects for %s\n" "$(NAME)"

fclean:
	rm -rf $(NAME)

re: fclean all