#!/bin/bash

Usage="Usage: ./gen.sh <src_mod> <src_ex> <dest_mod> <dest_ex> [Class1 Class2 ...]"

FILES=("Makefile" "lib")
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
SRC_DIR="${MODULE}$1/${EXERCISE}$2"
DEST_DIR="${MODULE}$3/${EXERCISE}$4"

mkdir -p "$DEST_DIR"

# Copia i file base
for file in "${FILES[@]}"; do
    if [ -e "$SRC_DIR/$file" ]; then
        cp -r "$SRC_DIR/$file" "$DEST_DIR"
    fi
done
printf "Copied from $SRC_DIR to $DEST_DIR\n"

# Header principale
HEADER_FILE="$DEST_DIR/header.hpp"
echo "/* Auto-generated header aggregator */" > "$HEADER_FILE"

# Se ci sono classi aggiuntive
shift 4
if [ $# -gt 0 ]; then
    for class in "$@"; do
        HPP_FILE="$DEST_DIR/$class.hpp"
        CPP_FILE="$DEST_DIR/$class.cpp"

        # Guard name
        GUARD=$(echo "${class}_HPP" | tr '[:lower:]' '[:upper:]')

        # .hpp
        cat > "$HPP_FILE" <<EOF
#ifndef $GUARD
# define $GUARD

class $class {
public:
    $class();
    ~$class();
    $class(const $class &other);
    $class &operator=(const $class &other);
};

#endif
EOF

        # .cpp
        cat > "$CPP_FILE" <<EOF
#include "$class.hpp"

$class::$class() {}
$class::~$class() {}
$class::$class(const $class &other) { *this = other; }
$class &$class::operator=(const $class &other) {
    if (this != &other) {
        // copy fields
    }
    return *this;
}
EOF

        # Aggiungi include a header.hpp
        echo "#include \"$class.hpp\"" >> "$HEADER_FILE"
    done
fi

# Crea main.cpp
cat > "$DEST_DIR/main.cpp" <<EOF
#include "header.hpp"
#include <iostream>

int main() {
    std::cout << "Program start" << std::endl;
    return 0;
}
EOF
