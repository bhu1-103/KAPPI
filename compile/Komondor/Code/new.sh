##################
#### Scenario 1
##################
NUM_APS=4
DEPLOYMENT_ID=0
output_folder="test_output_sce1"
input="/home/pokeymystery/Komondor/Code/outputs/test_sce1_output.txt"
sce_id="sce1"
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
NUM_APS=4
DEPLOYMENT_ID=0
output_folder="test_output_sce2"
input="/home/pokeymystery/Komondor/Code/outputs/test_sce2_output.txt"
sce_id="sce2"
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
NUM_APS=4
DEPLOYMENT_ID=0
output_folder="test_output_sce3"
input="/home/pokeymystery/Komondor/Code/outputs/test_sce3_output.txt"
sce_id="sce3"
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
#### Scenario 4
##################
NUM_APS=4
DEPLOYMENT_ID=0
output_folder="test_output_sce4"
input="/home/pokeymystery/Komondor/Code/outputs/test_sce4_output.txt"
sce_id="sce4"
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
#### Scenario 5
##################
NUM_APS=4
DEPLOYMENT_ID=0
output_folder="test_output_sce5"
input="/home/pokeymystery/Komondor/Code/outputs/test_sce5_output.txt"
sce_id="sce5"
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
#### Scenario 6
##################
NUM_APS=4
DEPLOYMENT_ID=0
output_folder="test_output_sce6"
input="/home/pokeymystery/Komondor/Code/outputs/test_sce6_output.txt"
sce_id="sce6"
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
#### Scenario 7
##################
NUM_APS=4
DEPLOYMENT_ID=0
output_folder="test_output_sce7"
input="/home/pokeymystery/Komondor/Code/outputs/test_sce7_output.txt"
sce_id="sce7"
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
