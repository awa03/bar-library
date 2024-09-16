#!/bin/bash

i=0
h=100
w=1

while [ $i -ne 100 ]
do
  i=$((i + 1))  # Corrected assignment and increment
  ./example-script-driver.x "$h" "$w" "$i"
  sleep .1
done

