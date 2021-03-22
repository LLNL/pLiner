#!/bin/bash

CC="/usr/bin/gcc"
CFLAGS=" -O0 -g -std=c99"
CFLAGS_trouble=" -O3 -ffast-math -g -std=c99"
THRESHOLD=8

ftrans=`echo $1 | cut -d '.' -f 1`
ftest=`echo $ftrans | sed "s/_trans$//"`

input=`sed -n "2p" $ftest.c | cut -d "/" -f 3 | sed "s/,/ /g"`

O0exe="${ftest}_O0"
O3exe="${ftrans}_O3"

#echo "$CC -o $O0exe $CFLAGS $ftest.c -lm"
$CC -o $O0exe $CFALGS $ftest.c -lm
rm -f $O3exe
#echo "$CC -o $O3exe ${CFLAGS_trouble} $ftrans.c -lm"
$CC -o $O3exe ${CFLAGS_trouble} $ftrans.c -lm
if [ ! -x $O3exe ]; then
  exit 1
fi

#echo "./$O0exe $input"
ans=`./$O0exe $input` 
echo $ans > runlog.txt 

#echo "./$O3exe $input"
result=`./$O3exe $input`
if [ $? -ne 0 ]; then
  exit 2
fi
echo $result >> runlog.txt

err=`awk -v r=$result -v a=$ans 'BEGIN{OFMT="%.$THRESHOLDf"; print (r-a)/a}' | awk '{if ($1==0) print 0; else print 1}'`
if [ $err -eq 0 -a "$ans" != "" ]; then
  #false ## false=1 success
  exit 0
else
  #true ## true=0 failed
  exit 3
fi
