#!/bin/bash

ftest=$1

input=`sed -n "3p" $ftest.c | cut -d "_" -f 2 | sed "s/^O. //"`

O0exe="${ftest}_O0"
O3exe="${ftest}_O3"

echo "./$O0exe $input"
./$O0exe $input

echo "./$O3exe $input"
./$O3exe $input
