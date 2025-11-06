# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    init.sh                                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alerusso42 <alerusso42@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/06 16:11:38 by alerusso42        #+#    #+#              #
#    Updated: 2025/11/06 17:54:44 by alerusso42       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

source "bash_utils/utils.sh"
source "bash_utils/env.sh"
include "$NGINX/install.sh"

install_ngnix || error "Can't install ngnix" && printf "Ok.\n"
