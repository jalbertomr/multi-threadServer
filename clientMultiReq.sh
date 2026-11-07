#!/bin/bash

for i in {1..500}  # Adjust the range as needed
do
  ./client $((${i} % 7 + 1)).txt &
done
wait