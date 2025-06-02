#!/bin/bash

SETTINGS="SETTINGS.md"
# Save marker
MARKER="# --MARKER -- #"

INIT_HASH="echo"

DELIM="."
while IFS= read -r line; do
    if [[ "$line" == DEFAULT_LIMITER-">"* ]]; then
        DELIM="${line#DEFAULT_LIMITER->}"
        continue
    fi
done < "$SETTINGS"


# Temporary file
TMPFILE=$(mktemp)


# 1. Copy lines up to and including the marker to tmp
awk -v marker="$MARKER" '
  { print }
  $0 == marker { exit }
' $SETTINGS > "$TMPFILE"


declare -A entries
found=0

while IFS= read -r line; do
    if [[ "$line" == "$MARKER" ]]; then
        found=1
        continue
    fi

    if [[ $found -eq 1 && "$line" == *"->"* ]]; then
        filename="${line%%->*}"
        suffix="${line#*->}"
        entries["$filename"]="$suffix"
    fi
done < "$SETTINGS"

#NOTE - Debug: print save entries
#for file in "${!entries[@]}"; do
#    echo "Saved: $file -> ${entries[$file]}"
#done

mapfile -t real_files < <(find . -path './hash_data' -prune -o -type f \
    ! -name "*.sh" \
    ! -name "*.c" \
    ! -name "*.h" \
    ! -name "*.o" \
    ! -name "Makefile" \
    ! -name "*.md" \
    -printf "%P\n")



modification=0

for file in "${real_files[@]}"; do
    if [[ -z "${entries[$file]}" ]]; then
		entries["$file"]="$DELIM"
		echo -ne "\e[33m$file \e[0m"
		echo "added to settings. Remember to check $SETTINGS"
		modification=1
    fi
done


for key in "${!entries[@]}"; do
    if ! printf '%s\n' "${real_files[@]}" | grep -qxF "$key"; then
        unset entries["$key"]
		echo -ne "\e[33m$key \e[0m"
		echo "deleted from settings"
		hash_file="hash_${key}"
		rm -rf $hash_file
    fi
done

{
    # Prima parte fino al marker
    awk -v marker="$MARKER" '{ print; if ($0 == marker) exit }' "$SETTINGS"

    # Ordinamento e stampa dell’array aggiornato
    for key in $(printf '%s\n' "${!entries[@]}" | sort); do
        echo "$key->${entries[$key]}"
    done
} > "$TMPFILE"

# Sovrascrivi il SETTINGS finale
mv "$TMPFILE" "$SETTINGS"

find hash_data -type d -empty -exec rmdir {} \; 2>/dev/null

if [[ $modification == 1 ]]; then
	echo -e "\e[33mmodifications in files detected. Update new files delimitators in $SETTINGS, then launch again update.sh\e[0m"
	exit
fi

exit_message=0

for file in "${real_files[@]}"; do
    hash_file="hash_$file"

    # Skip if it's not a regular file
    [[ ! -f "$file" ]] && continue

    # Get delimiter from settings
    delim="${entries[$file]}"
    [[ -z "$delim" ]] && continue  # Skip if no entry found

    # Check if hash_file exists
    if [[ ! -f "$hash_file" ]]; then
		mkdir -p "$(dirname "$hash_file")"
		touch "$hash_file"
		echo -ne "\e[33m$hash_file \e[0m"
        echo -e "\e[34mdoes not exist. Creating it...\e[0m"
		$INIT_HASH "$file" "$hash_file" "$delim"
		exit_message=1
        continue
    fi

    # Get mod times
    file_time=$(stat -c %Y "$file")
    hash_time=$(stat -c %Y "$hash_file")

    # Compare
    if [[ "$file_time" -ne "$hash_time" ]]; then
        echo -ne "\e[34mUpdating \e[0m"
		echo -ne "\e[33m$file \e[0m"
		echo -e "\e[34mhash_data...\e[0m"
       $INIT_HASH "$file" "$hash_file" "$delim"
	   exit_message=1
    fi
done

for file in "${real_files[@]}"; do
    hash_file="hash_$file"
    [[ -f "$file" && -f "$hash_file" ]] && touch -r "$file" "$hash_file"
done

if [[ $exit_message == 1 ]]; then
	echo -e "\e[32mhash files updated.\e[0m"
	exit 0
fi
if [[ $exit_message == 0 ]]; then
	echo -e "\e[30mNothing to be done with the database.\e[0m"
	exit 0
fi