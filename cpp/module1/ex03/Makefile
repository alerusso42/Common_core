NAME	=	violence
SRC		=	HumanA.cpp HumanB.cpp main.cpp Weapon.cpp
LIB_SRC =	string.cpp
LIB		=	$(addprefix lib/, $(LIB_SRC))
HEADER	=	Weapon.hpp HumanA.hpp HumanB.hpp

all: $(NAME)

$(NAME): $(SRC) $(LIB)  
	c++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) $(LIB)   -o $(NAME)

clean:
	@printf "no objects for %s\n" "$(NAME)"

fclean:
	rm -rf $(NAME)

re: fclean all