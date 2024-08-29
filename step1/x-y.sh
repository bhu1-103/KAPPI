#!/usr/bin/zsh
cat x-y_output/$1.csv | awk -F ";" '{print $4 , $5}'
