#!/bin/bash

for benchmark in ft mg cg lu bt sp; do
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
            rm -rf NPB-$benchmark-$class-$tr-O*
            tr=$((tr+1))
        done

    done
done
