NAME	=	account
SRC		=	Account.cpp tests.cpp
HEADER	=	Account.hpp

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) $(HEADER) -o $(NAME)

clean:
	@printf "no objects for %s\n" "$(NAME)"

fclean:
	rm -rf $(NAME)

re: fclean all

log:
	https://cdn.intra.42.fr/document/document/34946/19920104_091532.log