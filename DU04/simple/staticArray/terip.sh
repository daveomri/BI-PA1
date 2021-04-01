#!/usr/bin/env bash

for i in '0000' '0001' '0002' '0003' '0004' '0005'; do
  ./a.out < CZE/${i}_in.txt > out.txt
  if  ! diff CZE/${i}_out.txt out.txt ; then
    echo "Error on $i";
    exit 1;
  fi
done
