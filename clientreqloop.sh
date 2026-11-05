#!/bin/bash

i=1
while  true
do
  ./client $((${i} % 7 + 1)).txt
  i=$((i + 1))
  if [ $i -gt 7 ]; then
    i=1
  fi
done
wait