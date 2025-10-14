# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/10 22:06:56 by alerusso          #+#    #+#              #
#    Updated: 2025/10/14 22:34:27 by alerusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME :=		ray_tty

SRC := 		$(wildcard srcs/*.cpp)
CLASSES := 	$(wildcard classes/Term/*.cpp) \
			$(wildcard classes/Map/*.cpp)
LIB := 		$(shell echo -n $$(cd includes/lib/ && make list))
CPP :=		$(SRC) $(CLASSES) $(LIB)

HPP :=		$(wildcard classes/Term/*.hpp) \
			$(wildcard classes/Map/*.hpp)

COMP := 	g++ -Wall -Wextra -Werror -std=c++11 -g

all: $(NAME)
	clear
	@echo "\033[32mcompilation ok.\033[0m"
	
$(NAME): 	$(CPP) $(HPP)
	clear
	$(COMP) $(CPP) -o $(NAME)

clean:
	
fclean:
	rm -f $(NAME)
	rm -f logfile
	rm -f massif*

sanity:
	$(COMP) -fsanitize=address -fno-omit-frame-pointer $(CPP) -o $(NAME)
	./$(NAME)


re: fclean all
	