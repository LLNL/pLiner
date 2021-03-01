#!/bin/bash

for benchmark in ft mg cg lu bt sp; do
#for benchmark in ft lu bt sp; do
#for benchmark in mg cg; do
    for class in A B C; do
        trstart=8
        if [ $benchmark == "cg" ]; then
          trstart=10
        elif [ $benchmark == "ft" ]; then
          trstart=12
        fi
        trend=17
        
        tr=$((trstart+1))
        while [ $tr -le $trend ]; do
            O3_fail=`grep "UNSUCCESSFUL" NPB-$benchmark-$class-$tr-O3/result/*.$class.out`
            O3_suc=`grep " SUCCESS" NPB-$benchmark-$class-$tr-O3/result/*.$class.out`
            O3_res="UNKNOWN"
            if [ "$O3_fail" == "" -a "$O3_suc" != "" ]; then
	       O3_res="SUCCESS"
            fi
            if [ "$O3_fail" != "" ]; then
	       O3_res="FAILED"
            fi

            O0_fail=`grep "UNSUCCESSFUL" NPB-$benchmark-$class-$tr-O0/result/*.$class.out`
            O0_suc=`grep " SUCCESS" NPB-$benchmark-$class-$tr-O0/result/*.$class.out`
	    O0_res="UNKNOWN"
            if [ "$O0_fail" == "" -a "$O0_suc" != "" ]; then
	       O0_res="SUCCESS"
            fi
            if [ "$O0_fail" != "" ]; then
	       O0_res="FAILED"
            fi

            echo "$benchmark $class $tr $O3_res $O0_res"
           # if [ "$O3_res" == "UNKNOWN" ]; then
           #    echo "-O3"
           #    echo $O3_suc
           #    echo $O3_suc
           # fi

           # if [ "$O0_res" == "UNKNOWN" ]; then
           #    echo "-O0"
           #    echo $O0_suc
           #    echo $O0_suc
           # fi
            tr=$((tr+1))
        done

    done
done
