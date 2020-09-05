#!/bin/bash
#BSUB -nnodes 1
#BSUB -q pbatch
#BSUB -G guests
#BSUB -W 600

benchmark=$1
class=$2
threshold=$3
dir=`echo $benchmark | tr '[:lower:]' '[:upper:]'`

rm -rf bin result
mkdir -p bin
mkdir -p result

date

### set the threshold
verify="verify.c"
if [[ $benchmark == "cg" || $benchmark == "mg" ]]; then
  verify=$benchmark.c
fi

pushd $dir
ll=`grep -n "epsilon = 1.0e" $verify | cut -d ":" -f 1`
sed -i "$ll s/.*/  epsilon = 1.0e-$threshold;/" $verify
popd

### compile
echo "compiling $benchmark.$class. (SER-C)"
make $benchmark CLASS=$class

### run
echo "running $benchmark.$class. (SER-C)"
lrun -T1 -N1 bin/$benchmark.$class.x 2> result/benchmark.$class.out
echo "done.\n"

wait

date
