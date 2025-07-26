cmake_minimum_required(VERSION 3.4.1)
project(pacman)

# Set C and C++ standards
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Recursively gather all source files in Libft, daft_src, and srcs
file(GLOB_RECURSE LIBFT_SRC "${CMAKE_CURRENT_SOURCE_DIR}/Libft/*.c")
file(GLOB_RECURSE DAFT_SRC "${CMAKE_CURRENT_SOURCE_DIR}/daft_src/*.c")
file(GLOB_RECURSE GAME_SRC "${CMAKE_CURRENT_SOURCE_DIR}/srcs/*.c")

# Combine all source files
set(ALL_SRC ${LIBFT_SRC} ${DAFT_SRC} ${GAME_SRC})

# Define the shared library
add_library(pacman SHARED ${ALL_SRC})

# Include directories
target_include_directories(pacman PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/includes"
)

# Link against SDL2, SDL2_mixer, SDL2_image, and Android log
find_library(log-lib log)

# SDL2
add_library(SDL2 STATIC IMPORTED)
set_target_properties(SDL2 PROPERTIES IMPORTED_LOCATION
    "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/SDL2/lib/${ANDROID_ABI}/libSDL2.a"
)

# SDL2_mixer
add_library(SDL2_mixer STATIC IMPORTED)
set_target_properties(SDL2_mixer PROPERTIES IMPORTED_LOCATION
    "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/SDL2_mixer/lib/${ANDROID_ABI}/libSDL2_mixer.a"
)

# SDL2_image
add_library(SDL2_image STATIC IMPORTED)
set_target_properties(SDL2_image PROPERTIES IMPORTED_LOCATION
    "${CMAKE_CURRENT_SOURCE_DIR}/../../libs/SDL2_image/lib/${ANDROID_ABI}/libSDL2_image.a"
)

# Link everything together
target_link_libraries(pacman
    SDL2
    SDL2_mixer
    SDL2_image
    ${log-lib}
)
