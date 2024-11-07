x#!/bin/bash

echo "Listing files in long format with modification time:"
ls -lt

echo -e "\nCurrent Working Directory:"
pwd

echo -e "\nDisk Usage of the Current Directory:"
du

echo -e "\nDisk Space Usage:"
df

echo -e "\nPing Google (www.google.com):"
ping -c 4 www.google.com

