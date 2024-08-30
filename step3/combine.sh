# define execution parameters
SIM_TIME=0.2
SEED=900
# compile KOMONDOR
#pwd
#cd ..
#pwd
#cd main
#pwd
#./build_local
#echo 'EXECUTING KOMONDOR SIMULATIONS WITH FULL CONFIGURATION... '
#cd ..
#pwd
# remove old script output file and node logs
#rm output/*

# get input files path in folder 'script_input_files'
#cd input/sce9d
#pwd
#echo 'DETECTED KOMONDOR INPUT FILES: '

cd ../step2/z_output/
pwd

file_ix=0
while read line
do
	array[ $file_ix ]="$line"
	echo "- ${array[file_ix]}"
	(( file_ix++ ))
done < <(ls)

(( file_ix --));

# execute files
cd ..
cd ..
pwd
cd Komondor/Code/main
pwd

for (( executing_ix=0; executing_ix < (file_ix + 1); executing_ix++))
do 
	echo ""
	echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo "- EXECUTING ${array[executing_ix]} (${executing_ix}/${file_ix})"
	./komondor_main ../../../step2/z_output/${array[executing_ix]} ../../../step3/sce1a_output.txt sim_${array[executing_ix]} 0 1 1 $SIM_TIME $SEED >> ../../../step3/logs_console.txt 

	
	echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
	echo ""
done
