#!/bin/bash

DIRECTORY="thruput"
if [ ! -d "$DIRECTORY" ]; then
    echo "Directory $DIRECTORY not found!"
    exit 1
fi

cd "$DIRECTORY" || exit

for file in throughput_*.csv; do
    # Extract the numeric part of the filename
    number=$(echo "$file" | sed 's/throughput_\([0-9]*\)\.csv/\1/')
    
    # Format the number with leading zeros
    new_number=$(printf "%03d" "$number")
    
    # Create the new filename
    new_file="throughput_${new_number}.csv"
    
    # Rename the file
    mv "$file" "$new_file"
done

