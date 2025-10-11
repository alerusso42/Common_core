# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 22:06:56 by alerusso          #+#    #+#              #
#    Updated: 2025/10/10 23:21:05 by alerusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=		ray_tty

SRC := 		$(wildcard srcs/*.cpp)
CLASSES := 	$(wildcard classes/Term/*.cpp)
LIB := 		$(shell echo -n $$(cd includes/lib/ && make list))
CPP :=		$(SRC) $(CLASSES) $(LIB)

HPP :=		$(wildcard classes/Term/*.hpp)

COMP := 	g++ -Wall -Wextra -Werror -std=c++11 -g

all: $(NAME)
	clear
	@echo "\033[32mcompilation ok.\033[0m"
	
$(NAME): 	$(CPP) $(HPP)
	clear
	$(COMP) $(CPP) -o $(NAME)

clean:
	
fclean:
	rm $(NAME)

re: fclean all
	