/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:25:40 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/05 18:25:40 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP
# include "lib/lib.hpp"
# include <stack>

# define RPN_CHARS "0123456789+-*/ "

int32_t	rpn(std::string expr);

#endif