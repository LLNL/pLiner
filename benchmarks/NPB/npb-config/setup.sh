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
            rm -rf NPB-$benchmark-$class-$tr-O3
            cp -r NPB-base-O3 NPB-$benchmark-$class-$tr-O3
            rm -rf NPB-$benchmark-$class-$tr-O0
            cp -r NPB-base-O0 NPB-$benchmark-$class-$tr-O0

            pushd NPB-$benchmark-$class-$tr-O3
            sed -i "7s/.*/benchmark=$benchmark/" run.sh
            sed -i "8s/.*/class=$class/" run.sh
            sed -i "9s/.*/threshold=$tr/" run.sh
            bsub ./run.sh
            popd

            pushd NPB-$benchmark-$class-$tr-O0
            bsub ./run.sh $benchmark $class $tr &
            sed -i "7s/.*/benchmark=$benchmark/" run.sh
            sed -i "8s/.*/class=$class/" run.sh
            sed -i "9s/.*/threshold=$tr/" run.sh
            bsub ./run.sh
            popd

            echo "$benchmark $class $tr - done."
            tr=$((tr+1))
        done

    done
done
