#!/usr/bin/zsh
awk -F, '{
    for (i = 1; i <= NF; i++) {
        if (max == "" || $i < max) max = $i
    }
}
END {
    print max
}' rssi-corrected.csv
