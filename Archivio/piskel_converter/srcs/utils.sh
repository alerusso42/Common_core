#!/bin/bash

#SECTION - utils functions

error()
{
	if [ [ $1 == "" ] || [ $1 == "usage" ] ]; then
		echo -e "\033[31m$USAGE\033[0m"
	elif [[ $SILENT == false ]]; then
		exit 1 
	else
		echo -e "\033[31m$1\033[0m"
	fi
	exit 1
}

clean()
{
	(cd $ROOT || error "Project must be put inside $ROOT"\
	&&	rm -rf $D_OLD_GIF/* $D_OLD_RES/*)
	if [[  $SILENT == true ]]; then
		echo $NAME clean
	fi
	exit 0
}

fclean()
{
	(cd $ROOT || error "Project must be put inside $ROOT"\
	&&	rm -rf $D_GIF/* $D_OLD_GIF/* $D_RES/* $D_OLD_RES/*)
	if [[  $SILENT == true ]]; then
		echo $NAME fclean
	fi
	exit 0
}

install_magik()
{
	sudo apt install imagemagick || error "cannot install imagemagick."
}