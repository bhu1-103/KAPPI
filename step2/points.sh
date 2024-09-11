#!/usr/bin/zsh
cat input_nodes_copy_deployment_000.csv | awk -F ";" '{printf "%s %s %s %s %s ", $2, $3, $4, $5, $6}'
