NAME	=	phone
SRC		=	phone.cpp class_build.cpp utils.cpp utils2.cpp
LIB_SRC =	string.cpp
LIB		=	$(addprefix lib/, $(LIB_SRC))
HEADER	=	phone.hpp

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) $(LIB) $(HEADER) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all