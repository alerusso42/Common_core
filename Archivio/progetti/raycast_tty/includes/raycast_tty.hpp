/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_tty.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alessandro.russo.frc@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 21:26:12 by alerusso          #+#    #+#             */
/*   Updated: 2025/10/12 17:30:30 by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_TTY
# define RAYCAST_TTY

# include "lib/lib.hpp"
# include <stdarg.h>
# include <iostream>
# include <fstream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <mutex>
# include <thread>
# include <map>
#ifdef _WIN32
# include <conio.h>
# include <windows.h>
#elif defined(__linux__) || defined(__APPLE__)
# include <termios.h>
# include <unistd.h>
#else
# error "OS has not terminal support"
#endif
//classes

# include "../classes/Term/Term.hpp"
# include "../classes/Map/Map.hpp"

void	commands(Term *tty);

#endif