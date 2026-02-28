#!/bin/bash

usage="usage: 'new [NEW PROG NAME]'"

#Do not use this
check_exist()
{
	echo "$1" " $2"
	if [[ $1 == $2 ]]; then
		return 0
	fi
	echo $(which $2 > /dev/null ; echo $?)
	if [ $(which $2 > /dev/null ; echo $?) != 0 ]; then
		echo Installing $2 ...
		~/script/install/.sh $2 > /dev/null
	fi
	return 0
}

check_success()
{
	if [ $? != 0 ]; then
		return 0
	fi
	echo -e -n "\033[31mInstallation success!\nUpdating list: \033[0m"
	echo $1 >> ~/script/install/list
	echo "Done."
	exit 0
}

#STARTING POINT
echo $1
#check if the following bin exists. If not, install them
if [ $(which snap > /dev/null ; echo $?) != 0 ]; then
	sudo apt update && sudo apt install snapd
fi

#check if new argument exists
if [[ "$1" == "" ]]; then
	echo -e $usage
	exit 1
fi
#check if exists
exist=$(which $1 > /dev/null ; echo $?)
if [ $exist == 0 ]; then
	echo -e "\033[31mprogram " $1 " already exists!" "\nPath: \033[0m" $(which $1)
	exit $exist
fi
#try to install with apt
sudo apt update && sudo apt install $1
check_success $1
#try to install with snap
sudo snap install $1 || sudo snap install --classic $1
check_success $1
#if none of the above succeed:
echo -e "\033[31mInstallation failed!\033[0m"
exit $install


