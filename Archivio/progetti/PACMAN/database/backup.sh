#!/bin/bash

# Path to the SETTINGS file
SETTINGS="SETTINGS.md"

# Markers in SETTINGS.md that delimit the FLAGS and ENUM sections
MARKER="# -- FLAGS -- #"
MARKER2="# -- ENUM -- #"

# Command (or placeholder) to build a hash for a data file
INIT_HASH="echo"

# Indicates whether any hash‐files were created/updated
exit_message=0

# Default delimiter (overridden by DEFAULT_FLAGS in SETTINGS.md)
DELIM="."
# Read DEFAULT_FLAGS from SETTINGS.md to set DELIM
while IFS= read -r line; do
    if [[ "$line" == DEFAULT_FLAGS-">"* ]]; then
        DELIM="${line#DEFAULT_FLAGS->}"
        break
    fi
done < "$SETTINGS"

# Default hash‐table size (overridden by HASH_SIZE in SETTINGS.md)
HASH_SIZE="0"
# Read HASH_SIZE from SETTINGS.md
while IFS= read -r line; do
    if [[ "$line" == HASH_SIZE-">"* ]]; then
        HASH_SIZE="${line#HASH_SIZE->}"
        break
    fi
done < "$SETTINGS"

# Create a temporary file to build the updated SETTINGS.md
TMPFILE=$(mktemp)

# -----------------------------------------------------------------------------
# STEP 1: Copy everything up to and including the “# -- FLAGS -- #” marker
#         from SETTINGS.md into TMPFILE. We will later re‐emit the FLAGS lines.
# -----------------------------------------------------------------------------
awk -v marker="$MARKER" '
  { print }
  $0 == marker { exit }
' "$SETTINGS" > "$TMPFILE"

# -----------------------------------------------------------------------------
# STEP 2: Parse per‐file flag entries from SETTINGS.md into an associative array
# entries[file_path] = flags_string
# We only read lines between MARKER and MARKER2.
# -----------------------------------------------------------------------------
declare -A entries
found=0

while IFS= read -r line; do
    # When we hit the FLAGS marker, start capturing
    if [[ "$line" == "$MARKER" ]]; then
        found=1
        continue
    fi
    # If we hit the ENUM marker, stop capturing flags
    if [[ "$line" == "$MARKER2" ]]; then
        break
    fi

    # If inside the FLAGS section and line contains “->”, split at “->”
    if [[ $found -eq 1 && "$line" == *"->"* ]]; then
        filename="${line%%->*}"
        suffix="${line#*->}"
        entries["$filename"]="$suffix"
    fi
done < "$SETTINGS"

# -----------------------------------------------------------------------------
# STEP 3: Parse any existing ENUM entries into a separate associative array
# enum_entries[file_path] = enum_name
# So that user‐provided ENUM names are preserved.
# -----------------------------------------------------------------------------
declare -A enum_entries
found_enum=0

while IFS= read -r line; do
    # When we hit the ENUM marker, start capturing
    if [[ "$line" == "$MARKER2" ]]; then
        found_enum=1
        continue
    fi
    # If inside the ENUM section and line contains “->”, split at “->”
    if [[ $found_enum -eq 1 && "$line" == *"->"* ]]; then
        fpath="${line%%->*}"
        ename="${line#*->}"
        enum_entries["$fpath"]="$ename"
    fi
done < "$SETTINGS"

# -----------------------------------------------------------------------------
# STEP 4: Discover all “data” files on disk (excluding hash_data, source, and .md)
#         and save into the array real_files.
# -----------------------------------------------------------------------------
mapfile -t real_files < <(
    find . \( -path './hash_data' -o -path './program'  -o -path './.private' \) -prune -o -type f \
        ! -name "*.sh" \
        ! -name "*.c" \
        ! -name "*.h" \
        ! -name "*.o" \
        ! -name "Makefile" \
        ! -name "*.md" \
        -printf "%P\n"
)

# -----------------------------------------------------------------------------
# STEP 5: Add any newly found files into entries[], using the default delimiter.
#         If a file did not have an entry, notify user to update SETTINGS.md.
# -----------------------------------------------------------------------------
modification=0

for file in "${real_files[@]}"; do
    if [[ -z "${entries[$file]}" ]]; then
        entries["$file"]="$DELIM"
        echo -ne "\e[33m$file \e[0m"
        echo "added to settings. Remember to check $SETTINGS"
        modification=1
    fi
done

# -----------------------------------------------------------------------------
# STEP 6: Remove any entries whose files no longer exist, and delete their hash folder
# -----------------------------------------------------------------------------
for key in "${!entries[@]}"; do
    if ! printf '%s\n' "${real_files[@]}" | grep -qxF "$key"; then
        unset entries["$key"]
        echo -ne "\e[33m$key \e[0m"
        echo "deleted from settings"
        hash_file="hash_${key}"
        rm -rf "$hash_file"
        exit_message=1
    fi
done

# -----------------------------------------------------------------------------
# STEP 7: Rebuild SETTINGS.md:
#   a) Copy header+FLAGS marker (already in TMPFILE)
#   b) Re‐emit each “file->flags” line in sorted order
#   c) Append the ENUM marker
#   d) For each file, either preserve existing enum_entries[file] or generate a new one
# -----------------------------------------------------------------------------
{
  # 7a) Copy everything up to and including the FLAGS marker
  awk -v marker="$MARKER" '{ print; if ($0 == marker) exit }' "$SETTINGS"

  # 7b) Re‐emit each “file->flags” in sorted order
  for key in $(printf '%s\n' "${!entries[@]}" | sort); do
      echo "$key->${entries[$key]}"
  done

  # 7c) Append the ENUM marker
  echo "$MARKER2"

  # 7d) Emit each “file->enum_name”, preserving existing user‐provided enums
  for key in $(printf '%s\n' "${!entries[@]}" | sort); do
      if [[ -n "${enum_entries[$key]}" ]]; then
          # Use the user’s custom enum name
          echo "$key->${enum_entries[$key]}"
      else
          # Generate a default enum name from the file’s relative path
          no_ext="${key#data/}"        # Strip “data/” prefix
          no_ext="${no_ext%.*}"        # Strip extension (e.g. “.txt”)
          enum_name="$(echo "$no_ext" \
            | tr '/' '_' \
            | tr -c '[:alnum:]_' '_' \
            | tr '[:lower:]' '[:upper:]')"
          enum_name="${enum_name%_}"   # Remove any trailing underscore
          echo "$key->$enum_name"
      fi
  done
} > "$TMPFILE"

# Replace the old SETTINGS.md with the updated version
mv "$TMPFILE" "$SETTINGS"

# -----------------------------------------------------------------------------
# STEP 8: Clean up any empty directories under hash_data/
# -----------------------------------------------------------------------------
find hash_data -type d -empty -exec rmdir {} \; 2>/dev/null

# -----------------------------------------------------------------------------
# STEP 9: If modifications were made, notify the user and exit so they can update SETTINGS.md
# -----------------------------------------------------------------------------
if [[ $modification == 1 ]]; then
    echo -e "\e[33mModifications detected. Update new file delimiters in $SETTINGS, then run update.sh again.\e[0m"
    exit
fi

# -----------------------------------------------------------------------------
# STEP 10: Build or update hash files for each data file
# -----------------------------------------------------------------------------
i="-1"
for file in "${real_files[@]}"; do
	((++i))
    hash_file="hash_$file"
    # Skip if it somehow isn’t a regular file
    [[ ! -f "$file" ]] && continue

    # Get the single‐character delimiter from entries[file]
    delim="${entries[$file]:0:1}"
    [[ -z "$delim" ]] && continue

    # If the hash file does not exist yet, create it and build it
    if [[ ! -f "$hash_file" ]]; then
        mkdir -p "$(dirname "$hash_file")"
        touch "$hash_file"
		chmod 777 "$hash_file"
        echo -n "$delim" > "$hash_file"
        echo -ne "\e[33m$hash_file \e[0m"
        echo -e "\e[34mdoes not exist. Creating it...\e[0m"
        $INIT_HASH "$file" "$hash_file" $i "$delim" "${entries[$file]:0:999}" "$HASH_SIZE"
        exit_message=1
        continue
    fi

    # Compare modification times between data file and hash file
    file_time=$(stat -c %Y "$file")
    hash_time=$(stat -c %Y "$hash_file")

    if [[ "$file_time" -ne "$hash_time" ]]; then
        # Data file changed: overwrite delimiter in hash file and rebuild
        echo -n "$delim" > "$hash_file"
        echo -ne "\e[34mUpdating \e[0m"
        echo -ne "\e[33m$file \e[0m"
        echo -e "\e[34mhash_data...\e[0m"
        $INIT_HASH "$file" "$hash_file" $i "$delim" "${entries[$file]:0:999}" "$HASH_SIZE"
        exit_message=1
        continue
    fi

    # Check if the stored delimiter in the first byte of hash_file changed
    old_delim=$(head -c 1 "$hash_file")
    if [[ "$delim" != "$old_delim" ]]; then
        # Delimiter changed: overwrite first byte and rebuild
        echo -n "$delim" > "$hash_file"
        echo -ne "\e[34mUpdating \e[0m"
        echo -ne "\e[33m$file \e[0m"
        echo -e "\e[34mhash_data...\e[0m"
        $INIT_HASH "$file" "$hash_file" $i "$delim" "${entries[$file]:0:999}" "$HASH_SIZE"
        exit_message=1
        continue
    fi
done

# -----------------------------------------------------------------------------
# STEP 11: Sync hash file timestamps to match data file timestamps
# -----------------------------------------------------------------------------
for file in "${real_files[@]}"; do
    hash_file="hash_$file"
    [[ -f "$file" && -f "$hash_file" ]] && touch -r "$file" "$hash_file"
done

# -----------------------------------------------------------------------------
# STEP 12: Update daft.h’s enum block
#   a) Save everything in daft.h after the final “}” into header_tail[]
#   b) Generate new enum lines from SETTINGS.md’s “# -- ENUM -- #” section
#   c) Remove old enum block from daft.h and insert the new lines
#   d) Append back the saved header_tail lines (everything after the closing brace)
# -----------------------------------------------------------------------------

DAFT_HEADER="daft.h"

# (a) Read and save all lines following the closing “}” in daft.h
declare -a header_tail
found_endmark=0
i=0

while IFS= read -r line; do
    # Once we find the closing brace “}”, start saving all subsequent lines
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

# (b) Extract ENUM entries from SETTINGS.md into TMP_ENUM
TMP_ENUM=$(mktemp)
found_enum=0

while IFS= read -r line; do
    if [[ "$line" == "# -- ENUM -- #" ]]; then
        found_enum=1
        continue
    fi
    # End if we hit a blank line after starting to capture
    if [[ $found_enum -eq 1 && "$line" == "" ]]; then
        break
    fi
    if [[ $found_enum -eq 1 && "$line" == *"->"* ]]; then
        # Extract the Enum name (the part after “->”)
        enum_name="${line#*->}"
        # Prepare a line with a leading tab for Norminette, e.g. “\tPOKEDEX,”
        printf "\t%s,\n" "$enum_name" >> "$TMP_ENUM"
    fi
done < "$SETTINGS"

# Sort alphabetically (optional)
sort "$TMP_ENUM" -o "$TMP_ENUM"

# (c) Remove everything between “{” and “}” (exclusive) in daft.h,
#     but preserve the braces themselves.
awk '/\{/{print; in_block=1; next}
     /\}/{in_block=0; print; next}
     !in_block' "$DAFT_HEADER" > "$DAFT_HEADER.tmp" && mv "$DAFT_HEADER.tmp" "$DAFT_HEADER"

# Insert the new enum lines immediately after “{”
sed -i "/{/ r $TMP_ENUM" "$DAFT_HEADER"

# Delete the temporary enum file
rm "$TMP_ENUM"

# (d) Append back the saved tail lines (everything after “}”)
for line in "${header_tail[@]}"; do
    echo "$line" >> "$DAFT_HEADER"
done

# -----------------------------------------------------------------------------
# STEP 13: Final exit message
# -----------------------------------------------------------------------------
if [[ $exit_message == 1 ]]; then
    echo -e "\e[32mFiles updated.\e[0m"
    exit 0
fi

echo "Nothing to be done with the database."
exit 0