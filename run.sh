#!/usr/bin/zsh

cd step1; nvim input-java.csv; ./step1.sh; cd ../
cd step2; ./step2.sh; ./points.sh|pbcopy; ./0.4/pls-work $(pbpaste); xdotool key super+f; cd ../
cd step3; ./combine.sh; cd ../
cd step4; ./saigo-no-steppu.sh;
cp -r sce1a_output/rssi rssi
cp -r sce1a_output/throughput thruput
echo "done"
