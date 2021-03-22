#!/bin/bash

CC=/usr/tce/packages/xl/xl-2019.08.20/bin/xlc

ftrans=`echo $1 | cut -d '.' -f 1`
#ftest=`echo $ftrans | sed "s/_trans$//"`
ftest=$ftrans

input=`sed -n "3p" $ftest.c | cut -d "_" -f 2 | sed "s/^O. //"`

O0exe="${ftest}_O0"
O3exe="${ftrans}_O3"

echo "$CC -o $O0exe -O0 $ftest.c -lm"
$CC -o $O0exe -O0 $ftest.c -lm
echo "$CC -o $O3exe -O3 $ftrans.c -lm"
$CC -o $O3exe -O3 $ftrans.c -lm

echo "./$O0exe $input"
ans=`./$O0exe $input` 
#ans=`echo $ans | awk -F"E" 'BEGIN{OFMT="%10.10f"} {print $1 * (10 ^ $2)}'` 
echo $ans > runlog.txt 

echo "./$O3exe $input"
result=`./$O3exe $input`
echo $result >> runlog.txt

#err=`echo "scale=11; ($result-$ans)/$ans" | bc -q`
if [ "$ans" == "$result" -a "$ans" != "" ]; then
  false ## false=1 success
else
  true ## true=0 failed
fi
