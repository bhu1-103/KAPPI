#!/bin/bash

MIN= $(./min.sh throughput-corrected.csv)
MAX= $(./max.sh throughput-corrected.csv)

INTERVAL=$(echo "scale=2; ($MAX - $MIN) / 3" | bc)

awk -F, -v min="$MIN" -v interval="$INTERVAL" -v max="$MAX" '
{
    for (i = 1; i <= NF; i++) {
        if ($i ~ /^[+-]?[0-9]*\.?[0-9]+$/) {  # Adjust regex to handle optional sign and decimal point
            value = $i + 0  # Convert the value to a number (awk handles it as float)
            if (value <= min + interval) {
                category = "low"
            } else if (value <= min + 2 * interval) {
                category = "mid"
            } else {
                category = "high"
            }
            print $i ", " category
        }
    }
}' throughput-corrected.csv

