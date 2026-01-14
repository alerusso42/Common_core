#!/bin/bash

while true; do
	rm test_file
    ./a.out 2> test_file
    exit_code=$?
    if [ "$exit_code" -ne 0 ]; then
        break
    fi
done
