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

ARG CONF_PATH="/etc/nginx/default.conf"
FROM debian
#ANCHOR prepare files
RUN apt update && apt install -y nginx
EXPOSE 80
#ANCHOR creating directories in the image.
#		CONF_PATH overrides default .conf file; /data stores web sources.
RUN echo $CONF_PATH
COPY nginx.conf $CONF_PATH
RUN mkdir -p "/data" && mkdir -p "/data/www" && mkdir -p "/data/images"
CMD ["nginx", "-g", "daemon off;"]
#CMD ["nginx"]

#INSTRUCTION ["executable","param1","param2"] (exec form)
#INSTRUCTION command param1 param2 (shell form)