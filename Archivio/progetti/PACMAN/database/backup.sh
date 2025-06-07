#!/bin/bash

SETTINGS="SETTINGS.md"
PRIVATE=".private"
HASH_DATA="$(PRIVATE)/""hash_data/"
# Save marker
MARKER="# -- FLAGS -- #"
MARKER2="# -- ENUM -- #"

INIT_HASH="echo"

exit_message=0

DELIM="."
while IFS= read -r line; do
    if [[ "$line" == DEFAULT_FLAGS-">"* ]]; then
        DELIM="${line#DEFAULT_FLAGS->}"
        continue
    fi
done < "$SETTINGS"

HASH_SIZE="0"
while IFS= read -r line; do
    if [[ "$line" == HASH_SIZE-">"* ]]; then
        HASH_SIZE="${line#DEFAULT_FLAGS->}"
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
    if [[ "$line" == "$MARKER2" ]]; then
        break
    fi

    if [[ $found -eq 1 && "$line" == *"->"* ]]; then
        filename="${line%%->*}"
        suffix="${line#*->}"
        entries["$filename"]="$suffix"
    fi
done < "$SETTINGS"

declare -A enum_entries
found_enum=0

while IFS= read -r line; do
    if [[ "$line" == "$MARKER2" ]]; then
        found_enum=1
        continue
    fi
    if [[ $found_enum -eq 1 && "$line" == *"->"* ]]; then
        fpath="${line%%->*}"
        ename="${line#*->}"
        enum_entries["$fpath"]="$ename"
    fi
done < "$SETTINGS"


#NOTE - Debug: print save entries
#for file in "${!entries[@]}"; do
#    echo "Saved: $file -> ${entries[$file]}"
#done

mapfile -t real_files < <(find . -path "$(HASH_DATA)" -prune -o -type f \
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
		exit_message=1
    fi
done

{
  # 1) Copy everything up to and including the FLAGS marker
  awk -v marker="$MARKER" '{ print; if ($0 == marker) exit }' "$SETTINGS"

  # 2) Re‐emit each file->flags in sorted order
  for key in $(printf '%s\n' "${!entries[@]}" | sort); do
      echo "$key->${entries[$key]}"
  done

  # 3) Append the ENUM marker
  echo "$MARKER2"

  # 4) For each file, either use the existing enum or generate a default
  for key in $(printf '%s\n' "${!entries[@]}" | sort); do
      if [[ -n "${enum_entries[$key]}" ]]; then
          # User has already provided a custom enum for this file—keep it
          echo "$key->${enum_entries[$key]}"
      else
          # No existing enum; generate one from the full path
          no_ext="${key#data/}"     # strip "data/" prefix if you still want to drop it
          no_ext="${no_ext%.*}"     # strip the ".txt" (or any) extension
		  enum_name="$(echo "$no_ext" | tr '/' '_' | tr -c '[:alnum:]_' '_' | tr '[:lower:]' '[:upper:]')"
          enum_name="${enum_name%_}"
		  echo "$key->$enum_name"
      fi
  done
} > "$TMPFILE"


# Sovrascrivi il SETTINGS finale
mv "$TMPFILE" "$SETTINGS"

find "$(HASH_DATA)" -type d -empty -exec rmdir {} \; 2>/dev/null

if [[ $modification == 1 ]]; then
	echo -e "\e[33mmodifications in files detected. Update new files delimitators in $SETTINGS, then launch again update.sh\e[0m"
	exit
fi

for file in "${real_files[@]}"; do
    hash_file="$(HASH_DATA)""hash_$file"

    # Skip if it's not a regular file
    [[ ! -f "$file" ]] && continue

    # Get delimiter from settings
    delim="${entries[$file]:0:1}"
    [[ -z "$delim" ]] && continue  # Skip if no entry found

    # Check if hash_file exists
    if [[ ! -f "$hash_file" ]]; then
		mkdir -p "$(dirname "$hash_file")"
		touch "$hash_file"
		echo $delim > "$hash_file"
		echo -ne "\e[33m$hash_file \e[0m"
        echo -e "\e[34mdoes not exist. Creating it...\e[0m"
		$INIT_HASH "$file" "$hash_file" "$delim" "$HASH_SIZE"
		exit_message=1
        continue
    fi

    # Get mod times
    file_time=$(stat -c %Y "$file")
    hash_time=$(stat -c %Y "$hash_file")

    # Compare
    if [[ "$file_time" -ne "$hash_time" ]]; then
		echo $delim > "$hash_file"
        echo -ne "\e[34mUpdating \e[0m"
		echo -ne "\e[33m$file \e[0m"
		echo -e "\e[34mhash_data...\e[0m"
       $INIT_HASH "$file" "$hash_file" "$delim" "$HASH_SIZE"
	   exit_message=1
	   continue
    fi

	# Old delimiter compare
	old_delim=$(head -c 1 $hash_file)
	if [[ "$delim" != "$old_delim" ]]; then
		echo $delim > "$hash_file"
        echo -ne "\e[34mUpdating \e[0m"
		echo -ne "\e[33m$file \e[0m"
		echo -e "\e[34mhash_data...\e[0m"
       $INIT_HASH "$file" "$hash_file" "$delim" "$HASH_SIZE"
	   exit_message=1
	   continue
    fi
done

#Create hash_files that does not exist yet
for file in "${real_files[@]}"; do
    hash_file=""$(HASH_DATA)"hash_$file"
    [[ -f "$file" && -f "$hash_file" ]] && touch -r "$file" "$hash_file"
done

#!/bin/bash
# … (qui vengono aggiornati FLAGS ed ENUM in SETTINGS.md) …

DAFT_HEADER="daft.h"

declare -a header_tail
found_endmark=0
i=0

while IFS= read -r line; do
    if [[ "$line" == "}" ]]; then
		header_tail[$i]="$line"
		((i++))
        found_endmark=1
        continue
    fi
    if [[ $found_endmark -eq 1 ]]; then
        header_tail[$i]="$line"
		((i++))
    fi
done < "$DAFT_HEADER"

TMP_ENUM=$(mktemp)

# 1. Leggi tutti i file->ENUM_NAME da SETTINGS.md sotto "# -- ENUM -- #"
#    Supponiamo che tu abbia creato in memoria (o sappia già) 
#    come estrarre queste coppie, ma in alternativa puoi farlo direttamente:
found_enum=0
while IFS= read -r line; do
    if [[ "$line" == "# -- ENUM -- #" ]]; then
        found_enum=1
        continue
    fi
    # Se incontriamo il marker di fine (oppure fine file), usciamo
    if [[ $found_enum -eq 1 ]] && [[ "$line" == "" ]]; then
        break
    fi
    if [[ $found_enum -eq 1 && "$line" == *"->"* ]]; then
        # Linea del tipo: data/pokedex/pokedex.txt->POKEDEX
        enum_name="${line#*->}"              # estrae "POKEDEX"
        # Riempiamo un file temporaneo con la riga: "\tDAFT_DB_POKEDEX,"
        printf "\t%s,\n" "$enum_name" >> "$TMP_ENUM"
    fi
done < "$SETTINGS"

# 2. Ordiniamo alfabeticamente le righe generate (opzionale, se non già ordinate)
sort "$TMP_ENUM" -o "$TMP_ENUM"

# 3. Ora sostituiamo, in daft.h, tutto ciò che sta fra "//MARKER" e "//MARKER_END"

# Per farlo, usiamo 'sed' con due passaggi:
# (a) Rimuoviamo le righe fra MARKER e MARKER_END (escluse).
# (b) Aggiungiamo le nuove righe subito dopo MARKER.

# 3a) Cancella tutte le righe _tra_ (ma non inclusi) i marker in daft.h
#     In questo modo conserviamo il commento "//MARKER" e "//MARKER_END" stessi.
# 3a) Sovrascrive daft.h rimuovendo tutto tra i marker, lasciandoli intatti
awk '/\{/{print; in_block=1; next}
     /\}/{in_block=0; print; next}
     !in_block' "$DAFT_HEADER" > "$DAFT_HEADER.tmp" && mv "$DAFT_HEADER.tmp" "$DAFT_HEADER"
# Spieghiamo la sintassi di sed sopra:
# - '/\/\/MARKER/ { … }' trova la riga che contiene "//MARKER"
# - 'n' salta alla riga successiva (quindi NON cancella la linea con "//MARKER")
# - ':a; N; /\/\/MARKER_END/!ba;' aggiunge riga per riga finché NON trova "//MARKER_END"
# - 'd' elimina TUTTE quelle righe intermedie (ma lascia inalterate le due righe con i marker)

# 3b) Inserisci le righe generate (TMP_ENUM) subito dopo la linea "//MARKER"
#     Per mantenere la corretta indentazione (Norminette: tab, non spazi),
#     usiamo 'sed' con l’opzione 'r' per leggere un file.
#
#    Ci serve un piccolo trucco: trasformiamo TMP_ENUM in una forma compatibile con sed.
#    Qui supponiamo che TMP_ENUM contenga già le righe correttamente indentate:

sed -i "/{/ r $TMP_ENUM" "$DAFT_HEADER"

# NOTA: questo inserisce ESATTAMENTE il contenuto di TMP_ENUM
#       subito dopo la riga che contiene "//MARKER".

# 4. Rimuoviamo il file temporaneo
rm "$TMP_ENUM"

#head -c -1 "$DAFT_HEADER" > tmp.txt && mv tmp.txt "$DAFT_HEADER"

for line in "${header_tail[@]}"; do
    echo "$line" >> "$DAFT_HEADER"
done

# Restore leftovers


if [[ $exit_message == 1 ]]; then
	echo -e "\e[32mfiles updated.\e[0m"
	exit 0
fi
if [[ $exit_message == 0 ]]; then
	echo "Nothing to be done with the database."
	exit 0
fi