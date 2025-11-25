# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 18:08:06 by alerusso42        #+#    #+#              #
#    Updated: 2025/11/25 15:58:51 by alerusso42       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=inception

$(NAME): 
	(clear; cd srcs && docker compose up --build)

daemon:
	(clear; cd srcs && docker compose up -d --build)

clean:
	(clear ; cd srcs && docker compose down -v)