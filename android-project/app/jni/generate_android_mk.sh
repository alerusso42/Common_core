#!/bin/bash

set -e
shopt -s nullglob

SDL_ROOT="SDL2/src"

# Cartelle Android-specifiche
INCLUDE_DIRS=(
  ""  # root SDL2/src/
  "audio/android"
  "audio/aaudio"
  "power/android"
  "core/android"
  "filesystem/android"
  "haptic/android"
  "hidapi/android"
  "joystick/android"
  "locale/android"
  "main/android"
  "misc/android"
  "sensor/android"
  "video/android"
)

# Cartelle generiche SDL2
INCLUDE_FILES=(
  ""  # root SDL2/src/
  "audio"
  "atomic"
  "core"
  "cpuinfo"
  "dynapi"
  "events"
  "file"
  "filesystem"
  "haptic"
  "hidapi"
  "joystick"
  "libm"
  "loadso"
  "locale"
  "main"
  "misc"
  "power"
  "render"
  "sensor"
  "stdlib"
  "test"
  "thread"
  "thread/generic"
  "timer"
  "video"
)

# Merge e rimozione duplicati
ALL_DIRS=($(printf "%s\n" "${INCLUDE_DIRS[@]}" "${INCLUDE_FILES[@]}" | sort -u))

TMP_FILE="all_c_files.txt"
> "$TMP_FILE"

# Cerca .c e .cpp in ogni directory esistente
for d in "${ALL_DIRS[@]}"; do
  dir_path="$SDL_ROOT/$d"
  if [ -d "$dir_path" ]; then
    find "$dir_path" -maxdepth 1 \( -name "*.c" -o -name "*.cpp" \) >> "$TMP_FILE"
  fi
done

# Ordina e rimuove duplicati
sort -u "$TMP_FILE" -o "$TMP_FILE"

# Genera il LocalSrcFiles.mk
echo "LOCAL_SRC_FILES := \\" > LocalSrcFiles.mk
while IFS= read -r file; do
  rel_path=${file#*/}
  echo "    $rel_path \\" >> LocalSrcFiles.mk
done < "$TMP_FILE"

# Togli il backslash finale
sed -i '' -e '$ s/ \\$//' LocalSrcFiles.mk 2>/dev/null || sed -i '$ s/ \\$//' LocalSrcFiles.mk

rm "$TMP_FILE"
echo "LocalSrcFiles.mk generato correttamente"
