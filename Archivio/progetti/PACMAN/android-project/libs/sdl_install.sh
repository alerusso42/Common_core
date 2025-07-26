#!/bin/bash
#SECTION 0) requires

which cmake > /dev/null || sudo apt install cmake
CURR_PWD=$(pwd)
LIB_DIR="$HOME/.local/bin/sdl"
LIB_PREF="lib"
CMAKE_SDL_SETTINGS=(
    -DCMAKE_INSTALL_PREFIX=$HOME/.local
    -DSDL_VIDEO=ON
    -DSDL_VIDEO_DRIVER_X11=ON
    -DSDL_X11=ON
    -DSDL_WAYLAND=OFF
    -DSDL_DIRECTFB=OFF
    -DSDL_KMSDRM=OFF
	-DSDL_STATIC=ON 
	-DSDL_SHARED=OFF
)
error () {
	printf "%s\n" $1
	cd $CURR_PWD
	exit 1
	return 1
}

compile () {
	#SECTION 1)	clone repos
	ls | grep -q $1 || git clone "git@github.com:libsdl-org/""$1"".git" || error "can't find lib $1"
	#SECTION 2) compile SDL
	cd $1
	mkdir -p build;cd build
	if [ "$1" = "SDL" ]; then
		cmake .. "${CMAKE_SDL_SETTINGS[@]}" || error "can't configure $1"
	else
		cmake ..  -DCMAKE_INSTALL_PREFIX=$HOME/.local -DSDL3_DIR=$HOME/.local/lib/cmake/SDL3 || error "can't configure $1"
	fi
	make -j 8 || make || error "can't compile $1"
	local lib="$1"
	lib="${lib/SDL/SDL3}"
	cp "$LIB_PREF""$lib"* $LIB_DIR ; ls
	cd $CURR_PWD
}

mkdir -p "$LIB_DIR"
rm -f "$LIB_DIR"/*
export CMAKE_PREFIX_PATH=$HOME/.local
export PKG_CONFIG_PATH=$HOME/.local/lib/pkgconfig
export LD_LIBRARY_PATH=$HOME/.local/lib:$LD_LIBRARY_PATH
export PATH=$HOME/.local/bin:$PATH
compile SDL
compile SDL_mixer
compile SDL_image