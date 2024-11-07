#!/bin/bash

echo "Simple Calculator"
echo "------------------"

# Read input values
read -p "Enter the first number: " num1
read -p "Enter the second number: " num2

# Perform operations
sum=$(echo "$num1 + $num2" | bc)
difference=$(echo "$num1 - $num2" | bc)
product=$(echo "$num1 * $num2" | bc)

# Check for division by zero
if [ "$num2" -eq 0 ]; then
    echo "Error: Division by zero is undefined."
else
    quotient=$(echo "scale=2; $num1 / $num2" | bc)
    echo "Sum: $sum"
    echo "Difference: $difference"
    echo "Product: $product"
    echo "Quotient: $quotient"
fi
