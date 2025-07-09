NAME	=	phone
SRC		=	phone.cpp class_build.cpp
HEADER	=	phone.hpp

all: $(NAME)

$(NAME): $(SRC) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 $(SRC) $(HEADER)

clean: 
	rm $(NAME)

fclean: clean

re: fclean all