#!/bin/bash

fibonacci_recursive() {
  if [ "$1" -le 1 ]; then
    echo "$1"
  else
    echo $(( $(fibonacci_recursive $(( $1 - 1 ))) + $(fibonacci_recursive $(( $1 - 2 ))) ))
  fi
}

echo "Enter the number of terms in the Fibonacci series:"
read n

echo "Fibonacci series using recursion:"
for (( i = 0; i < n; i++ )); do
  echo -n "$(fibonacci_recursive $i) "
done
