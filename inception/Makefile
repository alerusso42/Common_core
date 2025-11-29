# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: codespace <codespace@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 18:08:06 by alerusso42        #+#    #+#              #
#    Updated: 2025/11/29 15:31:24 by codespace        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=inception

$(NAME): 
	(clear; cd srcs && docker compose up --build)

daemon:
	(clear; cd srcs && docker compose up -d --build)

clean:
	(clear ; cd srcs && docker compose down -v)

fclean:
	(clear ; cd srcs && \
	docker system prune -a -f)