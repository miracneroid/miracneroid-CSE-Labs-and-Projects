#!/bin/bash

echo "Enter five integers to calculate their sum:"

sum=0

for (( i=1; i<=5; i++ ))
do
    read -p "Enter integer $i: " num
    sum=$((sum + num))
done

echo "Sum of the five integers is: $sum"

