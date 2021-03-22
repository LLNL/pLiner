#!/bin/bash
verrou="/home/huiguo15/valgrind/build/bin/valgrind --tool=verrou --rounding-mode=random -s"
rep=5

ftest=$1

input=`sed -n "2p" $ftest.c | cut -d "/" -f 3 | sed "s/,/ /g" `

O0exe="${ftest}_O0"
O3exe="${ftest}_O3"

echo "$verrou ./$O0exe $input"

id=0
rm -f values.txt
touch values.txt
while [ $id -lt $rep ]; do
  $verrou ./$O0exe $input &> verrou_out_O0
  v=`cat verrou_out_O0 | grep -v "=="`
  echo $v >> values.txt
  id=$((id+1))
done
rm -f verrou_out_O0
#cat values.txt
python utils/stats.py values.txt
rm values.txt

echo "$verrou ./$O3exe $input"
id=0
touch values.txt
while [ $id -lt $rep ]; do
  $verrou ./$O3exe $input &> verrou_out_O3
  v=`cat verrou_out_O3 | grep -v "=="`
  echo $v >> values.txt
  id=$((id+1))
done
rm -f verrou_out_O3
#cat values.txt
python utils/stats.py values.txt
