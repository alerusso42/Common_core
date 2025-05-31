#!/bin/bash

NPHILO="5"
TIME_DIE="405"
TIME_EAT="200"
TIME_SLEEP="200"
N_EAT=""

clear
philo_output="./philo $NPHILO $TIME_DIE $TIME_EAT $TIME_SLEEP $N_EAT"
$philo_output | awk '
/died/ { died_id = $2 }
{ lines[NR] = $0; ids[NR] = $2 }
END {
    for (i = 1; i <= NR; i++) {
        if (ids[i] == died_id)
            print "\033[1;31m" lines[i] "\033[0m";
        else
            print lines[i];
    }
}'


