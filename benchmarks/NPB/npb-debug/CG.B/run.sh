#!/bin/bash

inputs=$@

## compile
for input in $inputs; do
  ftrans=`echo $input | cut -d '.' -f 1`
  ftest=`echo $ftrans | sed "s/_trans$//"`
  cp $ftrans.c $ftest.c
done
cd .. #&>/dev/null
rm -f bin/cg.B.x
make cg CLASS=B #&>/dev/null
if [ ! -x bin/cg.B.x ]; then
  cd -
  for input in $inputs; do
    ftrans=`echo $input | cut -d '.' -f 1`
    ftest=`echo $ftrans | sed "s/_trans$//"`
    cp $ftest.c.ori $ftest.c
  done
  exit 1
fi

## run
cd - #&>/dev/null
for input in $inputs; do
  ftrans=`echo $input | cut -d '.' -f 1`
  ftest=`echo $ftrans | sed "s/_trans$//"`
  cp $ftest.c.ori $ftest.c
done

rm -f runlog.txt
../bin/cg.B.x > runlog.txt
if [ $? -ne 0 ]; then
  exit 2
fi

## verification
#res=`cat runlog.txt | grep "Verification" | sed "s/ \+/ /g" | cut -d " " -f 4`
res=`cat runlog.txt | grep "Verification    =" | sed "s/ \+/ /g" | cut -d " " -f 4`
randomv=$(($RANDOM%2))
#randomv=$((0+1))
#if [ "$res" == "SUCCESSFUL" -a $randomv -eq 1 ]; then
if [ "$res" == "SUCCESSFUL" ]; then
  exit 0 ## false=1 success
else
  #true ## true=0 failed
  exit 3
fi
