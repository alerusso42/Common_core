#!/bin/bash

#	Usage: ./copy_lib.sh <src_mod> <src_ex> <dest_mod> <dest_ex>
#	./copy_lib	2 	1			3 	2

FILES=("lib" "*.hpp" "class_build.cpp" "Makefile")
MODULE="module"
EXERCISE="ex0"

error()
{
	printf "%s\n" $1
	exit 1
}

if [ $# -ne 4 ]; then
	error "Usage: ./copy_lib.sh_<src_mod>_<src_ex>_<dest_mod>_<dest_ex>"
fi
SRC_DIR="$MODULE""$1"
DEST_DIR="$MODULE""$3"
SRC_EX="$EXERCISE""$2"
DEST_EX="$EXERCISE""$4"
SRC="$SRC_DIR"/"$SRC_EX"
DEST="$DEST_DIR"/"$DEST_EX"

mkdir -p $DEST_DIR
mkdir -p $DEST


for file in "${FILES[@]}"; do
	echo "$file"
	cp -r $SRC/$file $DEST
done
printf "Copied from $SRC to $DEST\n"