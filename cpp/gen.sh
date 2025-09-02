#!/bin/bash

Usage="Usage: ./gen.sh <src mod> <src_ex> <dest_mod> <dest_ex>\
\nOptional: <header_file> <file1.cpp> <filen.cpp>"
#	./gen.sh	2 	1			3 	2

FILES=("Makefile" "lib")
MODULE="module"
EXERCISE="ex0"

error()
{
	echo -e "$1\n"
	exit 1
}

if [ $# -lt 4 ]; then
	error "$Usage"
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

#SECTION - copy other empty files

HEADER="\
/* ************************************************************************** */\n\
/*                                                                            */\n\
/*                                                        :::      ::::::::   */\n\
/*   megaphone.cpp                                      :+:      :+:    :+:   */\n\
/*                                                    +:+ +:+         +:+     */\n\
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */\n\
/*                                                +#+#+#+#+#+   +#+           */\n\
/*   Created: 2025/07/09 14:52:59 by alerusso          #+#    #+#             */\n\
/*   Updated: 2025/07/09 14:53:00 by alerusso         ###   ########.fr       */\n\
/*                                                                            */\n\
/* ************************************************************************** */\n"


TMP=$(mktemp)
trap 'rm -f "$TMP"' EXIT
cat > $TMP <<EOF

#include <iostream>
#include <string>
#include <cstdlib>
#include "lib/lib.hpp"

#endif
EOF
if [ $# -eq 4 ]; then
	rm $TMP
	exit 0
fi
# Scrive l'header file con define guard
HEADER_FILE="$5"
DEFINE=${5^^}
DEFINE="${DEFINE//./_}"
printf "$HEADER\n" > "$DEST/$HEADER_FILE"
printf "#ifndef $DEFINE\n# define $DEFINE\n" >> "$DEST/$HEADER_FILE"
cat -A "$TMP"
while IFS= read -r line; do
  if [ "$line" = "#endif" ]; then
	 printf "#endif" >> "$DEST/$HEADER_FILE"
	break
  fi
  printf "%s\n" "$line" >> "$DEST/$HEADER_FILE"
done < "$TMP"
rm $TMP
# Altri file da creare e includere l'header
i=6
while [ $i -le $# ]; do
	file="${!i}"
	printf "$HEADER\n" > "$DEST/$file"
	printf "#include \"$HEADER_FILE\"\n" >> "$DEST/$file"
	((i++))
done