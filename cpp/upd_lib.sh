#!/bin/bash

Usage="Usage:_./copy_lib.sh_<src_mod>_<src_ex>"
#	./copy_lib	2 	1			3 	2

MODULE="module"
EXERCISE="ex0"

error()
{
	echo -e "$1\n"
	exit 1
}

if [ $# -lt 2 ]; then
	error $Usage
fi
SRC_DIR="$MODULE""$1"
SRC_EX="$EXERCISE""$2"
SRC="$SRC_DIR"/"$SRC_EX"
DEST="./"

mkdir -p $DEST

cp -r "$SRC/lib" "$DEST"

printf "Updated lib\n"