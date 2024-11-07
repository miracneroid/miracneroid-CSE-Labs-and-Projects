#!/bin/bash

# Assigning values to variables
number1=10
number2=20

# Taking input from the user
echo "Enter first number:"
read number1
echo "Enter second number:"
read number2

# Checking if the numbers are equal
if [ "$number1" -eq "$number2" ]; then
    echo "The numbers are equal."
else
    echo "The numbers are not equal."
fi
