#!/bin/bash

num=0
for file in CZE/*_in.txt ;do
  ./a.out < $file > mydata/${num}_out.txt
  num='000'$(($num+1))
done

num=0
while test $num -lt 8; do
  diff CZE/000${num}_out.txt mydata/000${num}_out.txt
  num=$(($num+1))
done
