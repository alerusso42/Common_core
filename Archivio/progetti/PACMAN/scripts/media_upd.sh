#!/bin/bash

#	Header files

H_DIR="includes/media/"

ERR="rm $TEMP; echo error!; exit 1"
TEMP="temp"
DIR="daft/data/"
DATA_DIR="media/"
LIST_FILE="$DIR""media_list"
#	Media location
T_NAME="textures"
M_NAME="mus"
TEXTURES=$DATA_DIR$T_NAME"/"
MUSIC=$DATA_DIR$M_NAME"/"

function open_temp() {
	local HEADER="$H_DIR$1"".h"
	while IFS= read -r line; do
		if [[ ${line:0:1} == "{" ]];
		then
			echo $line >> $H_TEMP
			break ;
		fi
		echo $line >> $H_TEMP
	done < $HEADER
}

function close_temp() {
	local HEADER="$H_DIR$1"".h"
	local print=0
	while IFS= read -r line; do
		if [[ ${line:0:1} == "}" ]]; 
		then
			print=1
		fi
		if [[ $print == 1 ]]; 
		then
			echo $line >> $H_TEMP
		fi
	done < $HEADER
	> $HEADER
	while IFS= read -r line; do
		if [[ ${line:0:1} != "/" ]];
		then
			echo $line >> $HEADER
		fi 
	done < $H_TEMP
}

function update_media()	{
	local FILES="$1"
	local TYPE
	if [[ "$1" == "$TEXTURES" ]];
	then
		TYPE="$T_NAME"
	elif [[ "$1" == "$MUSIC" ]];
	then
		TYPE="$M_NAME"
	else
		return 1
	fi
	H_TEMP=$(mktemp)
	echo -n "$TYPE:" >> "$LIST_FILE"
	ls "$FILES" > "$TEMP"
	open_temp $TYPE
	while IFS= read -r line; do
		upper=${line^^}
		upper="${upper%.*}"
		line=$FILES$line
		echo -n "$line""," >> $LIST_FILE
		printf $'\t%s,\n' "$upper" >> "$H_TEMP"
	done < $TEMP
	printf $'\t%s,\n' "TOTAL_""${TYPE^^}" >> "$H_TEMP"
	close_temp $TYPE
	echo >> $LIST_FILE
	return 0
}

touch $TEMP && chmod 777 $TEMP || exit 1
> $LIST_FILE
update_media "$TEXTURES" || { eval "$ERR"; }
update_media "$MUSIC" || { eval "$ERR"; }
rm $TEMP