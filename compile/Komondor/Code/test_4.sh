##################
#### Scenario 1
##################
NUM_APS=4
DEPLOYMENT_ID=0
outputfolder="test_sce1_output"
input="/home/pokeymystery/Komondor/Code/outputs/test_sce1_output.txt"
sce_id="sce1"
if [ -d "$outputfolder" ]; then rm -Rf $outputfolder; fi
mkdir -p $outputfolder
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
	printf $line | paste -sd ',' >> $outputfolder/throughput_$sce_id_$DEPLOYMENT_ID.csv
    # Airtime (label 2)    
    elif [[ $line_id -eq 2 ]]; then
        printf $line | paste -sd ',' >> $outputfolder/airtime_$sce_id_$DEPLOYMENT_ID.csv    
    # RSSI list (feature 1)    
    elif [[ $line_id -eq 3 ]]; then    
        printf $line | paste -sd ',' >> $outputfolder/rssi_$sce_id_$DEPLOYMENT_ID.csv 
    # Interference map (feature 2)   
    elif [[ $line_id -gt 3 && $line_id -le $last_line ]]; then
	echo $line >> $outputfolder/interference_$sce_id_$DEPLOYMENT_ID.csv
    # Average SINR (feature 3)
    elif [[ $line_id -gt $last_line ]]; then
	printf $line | paste -sd ',' >> $outputfolder/sinr_$sce_id_$DEPLOYMENT_ID.csv 
    fi
    line_id=$((line_id+1))
  fi
done < "$input"

##################
#### Scenario 2
##################
NUM_APS=6
DEPLOYMENT_ID=0
outputfolder="test_sce2_output"
input="/home/pokeymystery/Komondor/Code/outputs/test_sce2_output.txt"
sce_id="sce2"
if [ -d "$outputfolder" ]; then rm -Rf $outputfolder; fi
mkdir -p $outputfolder
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
	printf $line | paste -sd ',' >> $outputfolder/throughput_$sce_id_$DEPLOYMENT_ID.csv
    # Airtime (label 2)    
    elif [[ $line_id -eq 2 ]]; then
        printf $line | paste -sd ',' >> $outputfolder/airtime_$sce_id_$DEPLOYMENT_ID.csv    
    # RSSI list (feature 1)    
    elif [[ $line_id -eq 3 ]]; then    
        printf $line | paste -sd ',' >> $outputfolder/rssi_$sce_id_$DEPLOYMENT_ID.csv 
    # Interference map (feature 2)   
    elif [[ $line_id -gt 3 && $line_id -le $last_line ]]; then
	echo $line >> $outputfolder/interference_$sce_id_$DEPLOYMENT_ID.csv
    # Average SINR (feature 3)
    elif [[ $line_id -gt $last_line ]]; then
	printf $line | paste -sd ',' >> $outputfolder/sinr_$sce_id_$DEPLOYMENT_ID.csv 
    fi
    line_id=$((line_id+1))
  fi
done < "$input"

##################
#### Scenario 3
##################
NUM_APS=8
DEPLOYMENT_ID=0
outputfolder="test_sce3_output"
input="/home/pokeymystery/Komondor/Code/outputs/test_sce3_output.txt"
sce_id="sce3"
if [ -d "$outputfolder" ]; then rm -Rf $outputfolder; fi
mkdir -p $outputfolder
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
	printf $line | paste -sd ',' >> $outputfolder/throughput_$sce_id_$DEPLOYMENT_ID.csv
    # Airtime (label 2)    
    elif [[ $line_id -eq 2 ]]; then
        printf $line | paste -sd ',' >> $outputfolder/airtime_$sce_id_$DEPLOYMENT_ID.csv    
    # RSSI list (feature 1)    
    elif [[ $line_id -eq 3 ]]; then    
        printf $line | paste -sd ',' >> $outputfolder/rssi_$sce_id_$DEPLOYMENT_ID.csv 
    # Interference map (feature 2)   
    elif [[ $line_id -gt 3 && $line_id -le $last_line ]]; then
	echo $line >> $outputfolder/interference_$sce_id_$DEPLOYMENT_ID.csv
    # Average SINR (feature 3)
    elif [[ $line_id -gt $last_line ]]; then
	printf $line | paste -sd ',' >> $outputfolder/sinr_$sce_id_$DEPLOYMENT_ID.csv 
    fi
    line_id=$((line_id+1))
  fi
done < "$input"

##################
#### Scenario 4
##################
NUM_APS=10
DEPLOYMENT_ID=0
outputfolder="test_sce4_output"
input="/home/pokeymystery/Komondor/Code/outputs/test_sce4_output.txt"
sce_id="sce4"
if [ -d "$outputfolder" ]; then rm -Rf $outputfolder; fi
mkdir -p $outputfolder
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
	printf $line | paste -sd ',' >> $outputfolder/throughput_$sce_id_$DEPLOYMENT_ID.csv
    # Airtime (label 2)    
    elif [[ $line_id -eq 2 ]]; then
        printf $line | paste -sd ',' >> $outputfolder/airtime_$sce_id_$DEPLOYMENT_ID.csv    
    # RSSI list (feature 1)    
    elif [[ $line_id -eq 3 ]]; then    
        printf $line | paste -sd ',' >> $outputfolder/rssi_$sce_id_$DEPLOYMENT_ID.csv 
    # Interference map (feature 2)   
    elif [[ $line_id -gt 3 && $line_id -le $last_line ]]; then
	echo $line >> $outputfolder/interference_$sce_id_$DEPLOYMENT_ID.csv
    # Average SINR (feature 3)
    elif [[ $line_id -gt $last_line ]]; then
	printf $line | paste -sd ',' >> $outputfolder/sinr_$sce_id_$DEPLOYMENT_ID.csv 
    fi
    line_id=$((line_id+1))
  fi
done < "$input"
