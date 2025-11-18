# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 14:21:59 by alerusso42        #+#    #+#              #
#    Updated: 2025/11/18 14:22:28 by alerusso42       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RUN  apt-get update \
  && apt-get install -y wget \
  && rm -rf /var/lib/apt/lists/*
RUN wget https://wordpress.org/latest.tar.gz && tar -xzvf latest.tar.gz
#other