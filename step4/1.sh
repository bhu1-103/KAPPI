#!/usr/bin/zsh
#
DIRECTORY="thruput"
if [ ! -d "$DIRECTORY" ]; then
    echo "Directory $DIRECTORY not found!"
    exit 1
fi
total_sum=0
for file in "$DIRECTORY"/throughput_*.csv; do
    if [ -f "$file" ]; then
        file_sum=$(awk -F, '{for(i=1;i<=NF;i++) total+=$i} END {print total}' "$file")
		echo "$file_sum"
    fi
done
