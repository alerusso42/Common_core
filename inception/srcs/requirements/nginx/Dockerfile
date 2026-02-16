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

FROM debian:bullseye

#ARG CONF_PATH="/etc/nginx"
#ANCHOR prepare files
RUN apt update && apt install -y nginx && apt install -y openssl
#ANCHOR creating directories in the image.
#		CONF_PATH overrides default .conf file; /data stores web sources.
COPY nginx.conf "/etc/nginx/conf.d"
RUN mkdir -p "/data/www" && mkdir -p "/data/images"

#ANCHOR openssl
#	1)	Creates ssl dir in nginx to store certificate and key
#	2)	req -x509 		--->	Certificate type
#	3)	nodes			--->	no private key password
#	4)	days 365 		--->	Duration
#	5)	newkey rsa:2048	--->	Generate private RSA key on 2048 bit
#	6)	keyout nginx.key--->	Private key path
#	7)	out nginx.cert	--->	Certificate path
#	8)	CN=localhost	--->	Valid for domain CN
RUN mkdir -p /etc/nginx/ssl && \ 
	openssl req -x509 -nodes -days 365 \ 
	-newkey rsa:2048 \ 
	-keyout /etc/nginx/ssl/nginx.key \ 
	-out /etc/nginx/ssl/nginx.crt \ 
	-subj "/CN=localhost"

CMD "nginx" "-g" "daemon off;"
#CMD ["nginx"]

#INSTRUCTION ["executable","param1","param2"] (exec form)
#INSTRUCTION command param1 param2 (shell form)