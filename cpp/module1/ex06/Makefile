NAME	=	harlFilter
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
	rm -rf $(NAME)

fclean: clean

re: fclean all