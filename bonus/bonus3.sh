#!/bin/bash


divisors() { 
n=$(($1));
for i in $(seq $n); 
do test $(($n % $i)) -eq 0 && echo $i;
done; }


sigma()
{ 
sum=0;
n=$(($1));
for f in $(divisors $n);
do sum=$(($sum + $f));
done;
echo $sum; }

while read N; do
	  abundance=$((`sigma $N` - 2*$N))
		if test $abundance -gt 0; then
       			echo -e "$N abundant by $abundance";
	  	elif test $abundance -lt 0; then
	      		echo -e "$N deficient"
	        else
		    	echo -e "$N neither"
		fi
  done
