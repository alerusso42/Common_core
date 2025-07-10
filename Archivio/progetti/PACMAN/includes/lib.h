#ifndef LIB_H
# define LIB_H

/*
//SECTION - C Standard Library (libc) Headers

//		These libraries are supported by any C compiler that conforms 
//		to standard specifications (C89, C99, C11, etc.) and are 
//		independent of the operating system.
//		We should not face portability issues when using them.
*/
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
//REVIEW -	Limits.
# include <limits.h>
//REVIEW -	Error handling utilities.
# include <errno.h>
//REVIEW -	Handling functions with a variable number of arguments.
# include <stdarg.h>
//REVIEW -	Standard boolean type support (bool).
# include <stdbool.h>

/* 
//SECTION - SDL3 Libraries (Graphics/Audio library, ensures portability)

//		SDL3 is a minimalist and cross-platform graphics/audio library,
//		originally developed by Sam Lantinga.
*/
//REVIEW -	Core SDL3 functionality
# include <SDL3/SDL.h>
# include <SDL3_mixer/SDL_mixer.h>
# include <SDL3_image/SDL_image.h>
//REVIEW -	Official SDL3 extension

/*
//SECTION - Other Libraries

//		Additional third-party libraries that complement SDL3
//		for graphics, math, and file system support.
*/
//REVIEW - 	Virtual FileSystem, developed by Ryan C. Gordon (icculus)
//# include <physfs.h>
//REVIEW - 	Mathematics library for graphics (OpenGL math), 
//			developed by the cglm project
//# include <cglm/cglm.h>
#endif
