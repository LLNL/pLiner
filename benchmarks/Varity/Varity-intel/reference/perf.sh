#!/bin/bash

res=performance.txt
timelog=varity-results.txt

perf_pLiner(){
  test=$1
  ## number of configs
  config=`cat $test-log.txt | wc -l`
  
  ## time
  line=`grep -n "$test:" $timelog | cut -d ':' -f 1`
  line=$((line+4))
  ptime=`sed -n "$line p" $timelog | awk '{print $2}'`
  ptime=`echo $ptime | sed "s/[ms]/:/g" | awk -F: '{print $1*60+$2}'`

  ## etime
  etime=`grep -n "$test:" $timelog | awk '{print $3}'`
  etime=`echo $etime | sed "s/[ms]/:/g" | awk -F: '{print $1*60+$2}'`

  overhead=`echo "scale=1; $ptime/$etime" | bc -l`  

  #echo $config $ptime $etime $overhead
  echo "[$config, $ptime],"
}

perf_herbgrind(){
  test=$1
  line=`grep -n "$test:" $timelog | cut -d ':' -f 1`
  line=$((line+1))
  htime=`sed -n "$line p" $timelog | awk '{print $3}'`
  htime=`echo $htime | sed "s/[ms]/:/g" | awk -F: '{print $1*60+$2}'`

  ## etime
  etime=`grep -n "$test:" $timelog | awk '{print $3}'`
  etime=`echo $etime | sed "s/[ms]/:/g" | awk -F: '{print $1*60+$2}'`
  
  overhead=`echo "scale=1; $htime/$etime" | bc -l`  
  
  #echo $htime $etime $overhead
  echo "[$htime],"
}

tool=$1
tests=`ls *.c | sed -n "/test_[0-9]*.c/p" | cut -d '.' -f 1`
rm -rf $res; touch $res
for test in $tests; do
  #echo $test

  if [ "$tool" = "pLiner" ]; then 
    perf_pLiner $test
  elif [ "$tool" = "herbgrind" ]; then
    perf_herbgrind $test
  fi
done
