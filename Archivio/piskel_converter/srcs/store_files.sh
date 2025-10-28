#!/bin/bash

create_dir()
{
	mkdir -p "$ROOT/$D_RES/$1"
	out_dir[$j]="$ROOT/$D_RES/$1"
	((++j))
}

read_files()
{
	i=0
	for file in "$@"
	do
		file="${file%.gif}"
		files_path[$i]="$PWD/$file"
		files[$i]="$file"
		create_dir "${files[$i]}"
		((++i))
	done
}

read_dir()
{
	echo "test"
	cd $ROOT/$D_GIF || error "project not found"\
	&&	files=$(echo *); cd $OLDPWD
	if [[ "${files[0]}" == "*" ]]; then
		error "$D_GIF is empty."
	fi
	i=0
	for file in "${files[@]}"
	do
		files_path[$i]="$ROOT/$D_GIF/$file"
		create_dir "${files[$i]}"
		files[$i]="${files[$i]%.gif}"
		((++i))
	done
}