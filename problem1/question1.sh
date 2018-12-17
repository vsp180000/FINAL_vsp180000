#!/bin/bash

trials=$1
count=0
i=0
for ((i=0; i<trials; i++));
do
	radius=1.00
	n=`awk -v seed=$RANDOM 'BEGIN{srand(seed);print rand()}'`
	m=`awk -v seed=$RANDOM 'BEGIN{srand(seed);print rand()}'`
	total=`echo "($n*$n + $m*$m)" | bc -l`
	sqr=`echo "scale=4; sqrt($total)" | bc -l`
	if (($(echo "$sqr <= $radius" | bc )));
	then 
#	i=$((i+1)) 
#	else
	count=$((count+1))
	fi
	i=$((i+1))
done

pi=`echo "(4.0*$count)/$1" | bc -l`
echo Estimated Value of pi= $pi

Deviation=`echo "(22/7) - $pi" | bc -l`
echo Deviation= $Deviation


Error=`echo "($Deviation*7*100)/22" | bc -l`
echo Error is= $Error


