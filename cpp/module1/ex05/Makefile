NAME	=	harl
SRC		=	main.cpp \
			Harl.cpp \
			utils.cpp
LIB_SRC =	strings/input_checker.cpp \
			files/sed.cpp
LIB		=	$(addprefix lib/, $(LIB_SRC))
HEADER	=	Harl.hpp

all: $(NAME)

$(NAME): $(SRC) $(LIB) $(HEADER)
	g++ -Wall -Wextra -Werror -std=c++98 -g $(SRC) $(LIB) $(HEADER) -o $(NAME)

clean:
	@printf "no objects for %s\n" "$(NAME)"

fclean:
	rm -rf $(NAME)

re: fclean all