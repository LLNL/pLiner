#!/bin/bash
herbgrind="/home/huiguo15/herbgrind/valgrind/herbgrind-install/bin/valgrind --tool=herbgrind"

ftest=$1

input=`sed -n "2p" $ftest.c | cut -d "/" -f 3 | sed "s/,/ /g" `

O0exe="${ftest}_O0"
O3exe="${ftest}_O3"

echo "$herbgrind ./$O0exe $input"
$herbgrind ./$O0exe $input

echo "$herbgrind ./$O3exe $input"
$herbgrind ./$O3exe $input
