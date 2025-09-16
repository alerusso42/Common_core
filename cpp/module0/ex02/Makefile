NAME	=	account
SRC		=	Account.cpp tests.cpp
HEADER	=	Account.hpp

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) $(HEADER) -o $(NAME)

clean: 
	rm -rf $(NAME)

fclean: clean

re: fclean all

log:
	https://cdn.intra.42.fr/document/document/34946/19920104_091532.log