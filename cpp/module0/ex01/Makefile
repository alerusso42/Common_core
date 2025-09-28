NAME	=	phone
SRC		=	main.cpp Contact.cpp PhoneBook.cpp utils.cpp utils2.cpp
LIB_SRC =	string.cpp
LIB		=	$(addprefix lib/, $(LIB_SRC))
HEADER	=	PhoneBook.hpp Contact.hpp

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) $(LIB) $(HEADER) -o $(NAME)

clean:
	@printf "no objects for %s\n" "$(NAME)"

fclean:
	rm -rf $(NAME)

re: fclean all