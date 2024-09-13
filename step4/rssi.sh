#!/usr/bin/zsh

for i in {0..12}
do
	for j in {0..100}
	do
		cat rssi/rssi_$(printf "%03d" $j).csv | awk -F "," '{sum=0; for(i=1;i<=NF;i++)sum += $i; print sum/NF}'
	done
done

