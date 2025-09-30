NAME	=	brain
SRC		=	main.cpp

all: $(NAME)

$(NAME): $(SRC) $(LIB)  
	c++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) $(LIB)   -o $(NAME)

clean:
	@printf "no objects for %s\n" "$(NAME)"

fclean:
	rm -rf $(NAME)

re: fclean all