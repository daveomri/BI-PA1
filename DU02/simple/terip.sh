#!/usr/bin/env bash

for i in '0000' '0001' '0002' '0003' '0004' '0005' '0006' '0007' '0008' '0009' '0010' '0011' '0012' '0013'; do
  ./a.out < CZE/${i}_in.txt > out.txt
  if  ! diff CZE/${i}_out.txt out.txt ; then
    echo "Error on $i";
    exit 1;
  fi
done
