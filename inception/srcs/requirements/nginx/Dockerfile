# syntax=docker/dockerfile:1

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 17:11:24 by alerusso42        #+#    #+#              #
#    Updated: 2025/11/10 09:31:04 by alerusso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian
#ANCHOR prepare files
RUN apt update && apt install -y nginx
EXPOSE 80
CMD ["nginx", "-g", "daemon off;"]

#INSTRUCTION ["executable","param1","param2"] (exec form)
#INSTRUCTION command param1 param2 (shell form)