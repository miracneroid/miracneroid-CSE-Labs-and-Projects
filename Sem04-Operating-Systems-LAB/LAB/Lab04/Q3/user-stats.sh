#!/bin/bash

echo "Users logged into the system with their login time:"
echo "--------------------------------------------------"

who | while read line; do
  user=$(echo $line | awk '{print $1}')
  login_time=$(echo $line | awk '{print $3, $4}')
  echo "User: $user | Login Time: $login_time"
done
