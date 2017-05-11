#!/bin/bash
$i=1;
for (( ; ; ))
do
   sleep $i
   echo "Number: $((i++))"
done