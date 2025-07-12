NAME	=	zombie
SRC		=	main.cpp Zombie.cpp zombieHorde.cpp
HEADER	=	Zombie.hpp

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) $(LIB) $(HEADER) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all