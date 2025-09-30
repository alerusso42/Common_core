NAME	=	a.out
SRC		=	megaphone.cpp
HEADER	=	

all: $(NAME)

$(NAME): $(SRC)
	c++ -Wall -Wextra -Werror -std=c++98 $(SRC)  

clean:
	@printf "no objects for %s\n" "$(NAME)"

fclean:
	rm -rf $(NAME)

re: fclean all