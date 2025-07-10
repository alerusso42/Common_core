NAME	=	phone
SRC		=	phone.cpp class_build.cpp utils.cpp
HEADER	=	phone.hpp

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) $(HEADER) -o $(NAME)

clean: 
	rm $(NAME)

fclean: clean

re: fclean all