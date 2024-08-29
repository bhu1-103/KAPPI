#!/bin/bash

MIN=852
MAX=1660

INTERVAL=$(( (MAX - MIN) / 3 ))

awk -F, -v min="$MIN" -v interval="$INTERVAL" -v max="$MAX" '
{
    for (i = 1; i <= NF; i++) {
        if ($i ~ /^[0-9]+(\.[0-9]+)?$/) {
            if ($i <= min + interval) {
                category = "ugly"
            } else if ($i <= min + 2 * interval) {
                category = "bad"
            } else {
                category = "good"
            }
            print $i ", " category
        }
    }
}' rajan.csv
