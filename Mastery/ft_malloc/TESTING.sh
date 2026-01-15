#!/bin/bash

while true; do
	rm -f test_file$1
    ./a.out 2> test_file$1
    exit_code=$?
    if [ "$exit_code" -ne 0 ]; then
        break
    fi
done
