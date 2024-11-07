#!/bin/bash

echo "Files and directories with both read and write permissions in the current directory:"
echo "--------------------------------------------------------"

for item in *; do
  if [ -r "$item" ] && [ -w "$item" ]; then
    echo "$item"
  fi
done
