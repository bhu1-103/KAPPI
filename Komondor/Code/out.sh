##################
#### Scenario 1
##################
NUM_APS=10
DEPLOYMENT_ID=0
output_folder="/home/pokeymystery/Komondor/Code/sce9a_output"
input="/home/pokeymystery/Komondor/Code/outputs/sce9a_output.txt"
sce_id="sce9a"
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
    last_line=$((3+$NUM_APS))
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
    elif [[ $line_id -gt $last_line ]]; then
	printf $line | paste -sd ',' >> $output_folder/sinr_$sce_id_$DEPLOYMENT_ID.csv 
    fi
    line_id=$((line_id+1))
  fi
done < "$input"

##################
#### Scenario 2
##################
NUM_APS=10
DEPLOYMENT_ID=0
output_folder="/home/pokeymystery/Komondor/Code/sce9b_output"
input="/home/pokeymystery/Komondor/Code/outputs/sce9b_output.txt"
sce_id="sce9b"
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
    last_line=$((3+$NUM_APS))
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
    elif [[ $line_id -gt $last_line ]]; then
	printf $line | paste -sd ',' >> $output_folder/sinr_$sce_id_$DEPLOYMENT_ID.csv 
    fi
    line_id=$((line_id+1))
  fi
done < "$input"

##################
#### Scenario 3
##################
NUM_APS=10
DEPLOYMENT_ID=0
output_folder="/home/pokeymystery/Komondor/Code/sce9c_output"
input="/home/pokeymystery/Komondor/Code/outputs/sce9c_output.txt"
sce_id="sce9c"
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
    last_line=$((3+$NUM_APS))
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
    elif [[ $line_id -gt $last_line ]]; then
	printf $line | paste -sd ',' >> $output_folder/sinr_$sce_id_$DEPLOYMENT_ID.csv 
    fi
    line_id=$((line_id+1))
  fi
done < "$input"
NUM_APS=10
DEPLOYMENT_ID=0
output_folder="/home/pokeymystery/Komondor/Code/sce9d_output"
input="/home/pokeymystery/Komondor/Code/outputs/sce9d_output.txt"
sce_id="sce9d"
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
    last_line=$((3+$NUM_APS))
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
    elif [[ $line_id -gt $last_line ]]; then
	printf $line | paste -sd ',' >> $output_folder/sinr_$sce_id_$DEPLOYMENT_ID.csv 
    fi
    line_id=$((line_id+1))
  fi
done < "$input"
NUM_APS=10
DEPLOYMENT_ID=0
output_folder="/home/pokeymystery/Komondor/Code/sce8d_output"
input="/home/pokeymystery/Komondor/Code/outputs/sce8d_output.txt"
sce_id="sce8d"
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
    last_line=$((3+$NUM_APS))
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
    elif [[ $line_id -gt $last_line ]]; then
	printf $line | paste -sd ',' >> $output_folder/sinr_$sce_id_$DEPLOYMENT_ID.csv 
    fi
    line_id=$((line_id+1))
  fi
done < "$input"
