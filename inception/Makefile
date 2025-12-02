# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 18:08:06 by alerusso42        #+#    #+#              #
#    Updated: 2025/12/02 11:05:58 by alerusso42       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=inception

$(NAME): 
	(clear; cd srcs && docker compose down; \
	docker compose up --build)

daemon:
	(clear; cd srcs && docker compose down; \
	docker compose up -d --build)

stop:
	(clear ; cd srcs && docker compose down)

fclean:
	(clear ; cd srcs && \
	docker compose down -v && \
	docker system prune -a -f --volumes && \
	sudo rm -rf volumes/mariadb/* volumes/wordpress/* && \
	echo "\033[32mFull reset done.\033[0m")

re: fclean daemon

logs:
	@if [ -z $$cont ]; then \
		echo "\033[31musage: make logs cont=name\033[0m" ; \
		exit 2; \
	fi
	@if [ [ $$cont != "all" ] ]; then \
		(cd srcs && docker logs $$cont);
	@else
		(cd srcs && \
		echo -e "\033[32mnginx:\n\033[0m" ; docker logs nginx ;\
		echo -e "\033[32mnginx:\n\033[0m" ; docker logs nginx ;\
		echo -e "\033[32mnginx:\n\033[0m" ; docker logs nginx ;\
		);

exec:
	@if [ -z $$cont ]; then \
		echo "\033[31musage: make exec cont=name\033[0m" ; \
		exit 2; \
		fi
	@(cd srcs && docker exec -it $$cont /bin/bash)