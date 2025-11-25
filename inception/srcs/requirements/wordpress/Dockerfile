# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/18 14:21:59 by alerusso42        #+#    #+#              #
#    Updated: 2025/11/25 15:25:09 by alerusso42       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM debian:trixie

RUN apt-get update \
    && apt-get install -y \
        wget \
        curl \
        php-fpm \
        php-mysql \
    && rm -rf /var/lib/apt/lists/*

RUN mkdir -p /var/www/html

COPY tools/init.sh /
RUN chmod 755 /init.sh
ENTRYPOINT ["/init.sh"]
CMD ["php-fpm7.4", "-F"]