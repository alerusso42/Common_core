#ifndef TEST_H
# define TEST_H

/*
//SECTION - C Standard Library (libc) Headers

//		These libraries are supported by any C compiler that conforms 
//		to standard specifications (C89, C99, C11, etc.) and are 
//		independent of the operating system.
//		We should not face portability issues when using them.
*/
//REVIEW -	Memory allocation (malloc, free), conversions, processes, etc.
# include <stdlib.h>
//REVIEW -	String manipulation functions.
# include <string.h>
//REVIEW -	Standard math functions (sin, cos, sqrt, etc.).
# include <math.h>
//REVIEW -	Time and date handling functions.
# include <time.h>
//REVIEW -	Character handling functions (isdigit, isalpha, etc.).
# include <ctype.h>
//REVIEW -	Macros for runtime checks and development-time testing.
# include <assert.h>
//REVIEW -	Fixed-width integer types (e.g., uint64_t).
# include <stdint.h>
//REVIEW -	Error handling utilities.
# include <errno.h>
//REVIEW -	Handling functions with a variable number of arguments.
# include <stdarg.h>
//REVIEW -	Standard boolean type support (bool).
# include <stdbool.h>

/* 
//SECTION - SDL2 Libraries (Graphics/Audio library, ensures portability)

//		SDL2 is a minimalist and cross-platform graphics/audio library,
//		originally developed by Sam Lantinga.
*/
//REVIEW -	Core SDL2 functionality
# include <SDL2/SDL.h>
//REVIEW -	Official SDL2 extensions
# include <SDL2/SDL_image.h>
# include <SDL2/SDL_mixer.h>
# include <SDL2/SDL_ttf.h>
# include <SDL2/SDL_net.h>

/*
//SECTION - Other Libraries

//		Additional third-party libraries that complement SDL2
//		for graphics, math, and file system support.
*/
//REVIEW - 	Virtual FileSystem, developed by Ryan C. Gordon (icculus)
# include <physfs.h>
//REVIEW - 	Mathematics library for graphics (OpenGL math), 
//			developed by the cglm project
# include <cglm/cglm.h>
#endif
