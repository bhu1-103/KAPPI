#!/usr/bin/zsh
##################
#### Scenario 1
##################

mkdir -p sce1a_output
rm sce1a_output/*

echo -n "enter number of APs: "
read AP

DEPLOYMENT_ID=0
input="../step3/sce1a_output.txt"
output_folder="sce1a_output"
sce_id="sce1a"
if [ -d "$output_folder" ]; then rm -Rf $output_folder; fi
mkdir -p $output_folder
while IFS= read -r line
do
  if [[ $line == *"KOMONDOR SIMULATION"* ]]; then
    DEPLOYMENT_ID=$((DEPLOYMENT_ID+1))
    line_id=1
  else
    # Remove separators
    line="${line//\{}"
    line="${line//\}}"
	last_line=$((3+$AP))
    # Throughput (label 1)
    if [[ $line_id -eq 1 ]]; then
		printf $line | paste -sd ',' >> $output_folder/throughput_$sce_id_$DEPLOYMENT_ID.csv
    # Airtime (label 2)    
    elif [[ $line_id -eq 2 ]]; then
        printf $line | paste -sd ',' >> $output_folder/airtime_$sce_id_$DEPLOYMENT_ID.csv    
    # RSSI list (feature 1)    
    elif [[ $line_id -eq 3 ]]; then    
        printf $line | paste -sd ',' >> $output_folder/rssi_$sce_id_$DEPLOYMENT_ID.csv 
    # Interference map (feature 2)   
    elif [[ $line_id -gt 3 && $line_id -le $last_line ]]; then
		echo $line >> $output_folder/interference_$sce_id_$DEPLOYMENT_ID.csv
    # Average SINR (feature 3)
	elif [[ $line_id -eq $((4+$AP)) ]]; then
		echo $line | paste -sd ',' >> $output_folder/sinr_$sce_id_$DEPLOYMENT_ID.csv 
    fi
    line_id=$((line_id+1))
  fi
done < "$input"
