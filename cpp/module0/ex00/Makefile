NAME	=	a.out
SRC		=	megaphone.cpp
HEADER	=	

all: $(NAME)

$(NAME): $(SRC)
	g++ -Wall -Wextra -Werror -std=c++98 $(SRC) $(HEADER)

clean:
	@printf "no objects for %s\n" "$(NAME)"

fclean:
	rm -rf $(NAME)

re: fclean all