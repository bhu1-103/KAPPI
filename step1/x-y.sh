#!/usr/bin/zsh
cat x-y_output/000.csv | awk -F ";" '{print $4 , $5}'
