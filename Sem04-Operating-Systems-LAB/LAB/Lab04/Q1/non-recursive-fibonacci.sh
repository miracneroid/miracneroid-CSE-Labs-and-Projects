#!/bin/bash

fibonacci_non_recursive() {
  a=0
  b=1
  for (( i = 0; i < $1; i++ )); do
    echo -n "$a "
    temp=$((a + b))
    a=$b
    b=$temp
  done
}

echo "Enter the number of terms in the Fibonacci series:"
read n

echo "Fibonacci series without recursion:"
fibonacci_non_recursive $n
