#!/bin/bash
herbgrind="/home/huiguo15/herbgrind/valgrind/herbgrind-install/bin/valgrind --tool=herbgrind"

res=varity-results.txt

exe_pLiner(){
  echo "  pLiner $1 ..."
  test=$1
  echo "    -python ../pLiner-search.py $test.c "-- " >tmp" 
  { time python ../pLiner-search.py $test.c "-- " >tmp; } &>tmptmp
  
  time=`tail -n 3 tmptmp | grep real | sed "s/real *//"`  
  
  out=`cat $test-log.txt | grep "success" | tail -n 1`
  echo -e "  -pLiner- $time \n    $out" >>$res
}

exe_herbgrind(){
  echo "  herbgrind $1 ..."
  test=$1
  input=`sed -n "2p" $test.c | cut -d "/" -f 3 | sed "s/,/ /g" `
  
  echo "    -$herbgrind ./${test}_O0 $input >tmp"
  { time $herbgrind ./${test}_O0 $input >tmp; } &>tmptmp
  timeO0=`tail -n 3 tmptmp | grep real | sed "s/real *//"`  
  echo "    -$herbgrind ./${test}_O3 $input >tmp"
  { time $herbgrind ./${test}_O3 $input >tmp; } &>tmptmp
  timeO3=`tail -n 3 tmptmp | grep real | sed "s/real *//"`  

  fO0=${test}_O0.gh
  fO3=${test}_O3.gh
 
  outO0=`cat $fO0 | grep -n "Influenced by erroneous expressions" | cut -d ":" -f 1`
  outO3=`cat $fO3 | grep -n "Influenced by erroneous expressions" | cut -d ":" -f 1`

  errO0=''
  for line in $outO0; do
    line=$((line+4))
    errO0+=`sed -n "$line p" $fO0`
  done 

  errO3=''
  for line in $outO3; do
    line=$((line+4))
    errO3+=`sed -n "$line p" $fO3`
  done 

  echo "  -herbgrind- $timeO0 $timeO3">>$res
  echo "    O0- $errO0" >>$res
  echo "    O3- $errO3" >>$res
}

exe(){
  echo "  execute $1 ..."
  test=$1
  input=`sed -n "2p" $test.c | cut -d "/" -f 3 | sed "s/,/ /g" `

  { time ./${test}_O0 $input &>tmp; } &>tmptmp
  timeO0=`tail -n 3 tmptmp | grep real | sed "s/real *//"`  
  { time ./${test}_O3 $input &>tmp; } &>tmptmp
  timeO3=`tail -n 3 tmptmp | grep real | sed "s/real *//"`  
  
  echo "$test: $timeO0 $timeO3" >> $res
}

tests=`ls *.c | sed -n "/test_[0-9]*.c/p" | cut -d '.' -f 1`
echo $tests
rm -rf $res; touch $res
for test in $tests; do
  echo $test

  exe $test
  exe_herbgrind $test
  exe_pLiner $test
  #exe_herbgrind $test
done
