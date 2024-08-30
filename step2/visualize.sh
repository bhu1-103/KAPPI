#!/usr/bin/zsh
cat z_output/input_nodes_copy_deployment_$1.csv | awk -F ";" '{print $4 , $5}'
