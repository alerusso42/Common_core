#!/bin/bash

clear
read -p "Insert commit message: " M
git add . && git commit -m "$M" && git push