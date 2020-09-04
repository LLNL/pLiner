#!/bin/bash

ftest=$1

input=`sed -n "2p" $ftest.c | cut -d "/"  -f 3 | sed "s/,/ /g" `

O0exe="${ftest}_O0"
O3exe="${ftest}_O3"

echo "./$O0exe $input"
./$O0exe $input

echo "./$O3exe $input"
./$O3exe $input
