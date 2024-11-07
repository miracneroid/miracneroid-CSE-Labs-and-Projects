#!/bin/bash

echo "Multiply 5 Integers"
echo "---------------------"

# Initialize product to 1
product=1

# Read and multiply 5 integers
for ((i=1; i<=5; i++)); do
    read -p "Enter integer $i: " num
    product=$((product * num))
done

echo "Product of the 5 integers is: $product"

