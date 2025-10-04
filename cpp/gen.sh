#!/bin/bash

# Header 42 standardizzato (puoi adattare nome/email/date con variabili se vuoi)
HEADER42="/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FILENAME											:+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alerusso <alerusso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: $(date '+%Y/%m/%d %H:%M:%S') by alerusso          #+#    #+#             */
/*   Updated: $(date '+%Y/%m/%d %H:%M:%S') by alerusso         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */"


Usage="Usage: ./gen.sh <src_mod> <src_ex> <dest_mod> <dest_ex> [Class1 Class2 ...]"

FILES=("lib")
MODULE="module"
EXERCISE="ex"

error() {
    echo -e "$1\n"
    exit 1
}

if [ $# -lt 4 ]; then
    error "$Usage"
fi

# Parametri
SRC_DIR="${MODULE}$1/${EXERCISE}0$2"
DEST_DIR="${MODULE}$3/${EXERCISE}0$4"

echo $SRC_DIR
echo $DEST_DIR

mkdir -p "$DEST_DIR"

# Copia i file base
for file in "${FILES[@]}"; do
    if [ -e "$SRC_DIR/$file" ]; then
        cp -r "$SRC_DIR/$file" "$DEST_DIR"
    fi
done
printf "Copied from $SRC_DIR to $DEST_DIR\n"

# Header principale

FILENAME="header.hpp"
echo "$HEADER42" | sed "s/FILENAME/$FILENAME/" > "$DEST_DIR/header.hpp"
echo "" >> "$DEST_DIR/header.hpp"
GUARD="HEADER_HPP"
HEADER_FILE="$DEST_DIR/header.hpp"
printf "#ifndef $GUARD\n# define $GUARD\n/* Auto-generated header aggregator */\n" >> "$HEADER_FILE"
printf "# include \"lib/lib.hpp\"\n" >> "$HEADER_FILE"

# Se ci sono classi aggiuntive
shift 4
if [ $# -gt 0 ]; then
    for class in "$@"; do
        HPP_FILE="$DEST_DIR/$class.hpp"
        CPP_FILE="$DEST_DIR/$class.cpp"

        # Guard name
        GUARD=$(echo "${class}_HPP" | tr '[:lower:]' '[:upper:]')

        # .hpp
		FILENAME="$class.hpp"
		echo "$HEADER42" | sed "s/FILENAME/$FILENAME/" > "$HPP_FILE"
		echo "" >> "$HPP_FILE"
        cat >> "$HPP_FILE" <<EOF
#ifndef $GUARD
# define $GUARD
# include "lib/lib.hpp"

class $class
{
public:
//	canonic form:
	$class();
	~$class();
	$class(const $class &other);
	$class &operator=(const $class &other);
};

#endif
EOF

        # .cpp
		FILENAME="$class.cpp"
		echo "$HEADER42" | sed "s/FILENAME/$FILENAME/" > "$CPP_FILE"
		echo "" >> "$CPP_FILE"
        cat >> "$CPP_FILE" <<EOF
#include "$class.hpp"

$class::$class()
{

}

$class::~$class()
{

}

$class::$class(const $class &other)
{ 
	if (this == &other)
		return ;
	// add field
}

$class &$class::operator=(const $class &other)
{
	if (this == &other)
		return (*this); 
	// add field
	return (*this);
}
EOF

        # Aggiungi include a header.hpp
        echo "#include \"$class.hpp\"" >> "$HEADER_FILE"
    done
fi

printf "\n#endif" >> "$HEADER_FILE"

# Crea main.cpp
FILENAME="main.cpp"
echo "$HEADER42" | sed "s/FILENAME/$FILENAME/" > "$DEST_DIR/main.cpp"
echo "" >> "$DEST_DIR/main.cpp"
cat >> "$DEST_DIR/main.cpp" <<EOF
# include "header.hpp"

int main() 
{
	std::cout << "\033[32mCompilation ok\033[0m" << std::endl;
	return (0);
}
EOF


# --- Generazione Makefile ---

# Nome eseguibile (puoi anche parametrizzarlo invece di "program")
NAME="	program"

# Lista sorgenti di base
SRC_LIST="	main.cpp"

# Aggiungi ogni classe alla lista sorgenti
for class in "$@"; do
    SRC_LIST="$SRC_LIST \\
				$class.cpp"
done

# Lista header (tutte le classi + aggregatore)
HEADER_LIST="	header.hpp"
for class in "$@"; do
    HEADER_LIST="$HEADER_LIST \\
			$class.hpp"
done

# Recupera tutti i .cpp dentro lib/ mantenendo struttura cartelle
LIB_SRC_LIST=$(find "$DEST_DIR/lib" -type f -name "*.cpp" | sed "s|$DEST_DIR/lib/||" | sort | sed 's|^|\t|' | sed 's|$| \\|' )
LIB_LIST='$(addprefix lib/, $(LIB_SRC))'

# Scrivi Makefile
cat > "$DEST_DIR/Makefile" <<EOF
NAME =	 	$NAME
SRC	=	 	$SRC_LIST

LIB_SRC	= 	$LIB_SRC_LIST

LIB	= 		$LIB_LIST

HEADER = 	$HEADER_LIST


C =		 c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: \$(NAME)

\$(NAME): \$(SRC) \$(LIB)
	\$(C) \$(CFLAGS) \$(SRC) \$(LIB) -o \$(NAME)

clean:
	@printf "no objects for %s\n" \$(NAME)

fclean:
	rm -rf \$(NAME)

re: fclean all

run: 
	make && ./\$(NAME)

val: 
	make && valgrind --track-fds=yes --show-leak-kinds=all --leak-check=full ./\$(NAME)
EOF

