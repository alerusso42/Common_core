#!/bin/bash

#	Usage: src(mod, ex)-->dest(mod, ex)
#	./copy_lib	2 	1			3 	2

MODULE="module"
EXERCISE="ex0"

error()
{
	printf "%s\n" $1
	exit 1
}

if [ [ $# != 2 ] ]
	error "Insert at least two args."
SRC_DIR="$MODULE""$1"
DEST_DIR="$MODULE""$3"
SRC_EX="$EXERCISE""$2"
DEST_EX="$EXERCISE""$4"
SRC="$SRC_DIR"/"$SRC_EX"
DEST="$DEST_DIR"/"$DEST_EX"

mkdir -p $DEST_DIR
mkdir -p $DEST

FILES=("lib" "*.hpp" "class_build.cpp" "Makefile")

for file in "${FILES[@]}"; do
	echo "$file"
	cp -r $SRC/$file $DEST
done