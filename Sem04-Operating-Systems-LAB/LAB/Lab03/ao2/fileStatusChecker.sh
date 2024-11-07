#!/bin/bash

# Taking input from the user
echo "Enter the path to the file or directory:"
read file_path

# Check if the file or directory exists
if [ -e "$file_path" ]; then
    # Check if it's a regular file
    if [ -f "$file_path" ]; then
        echo "It is a regular file."
        
        # Check if the file is empty
        if [ -s "$file_path" ]; then
            echo "The file is not empty."
        else
            echo "The file is empty."
        fi

        # Check if the file is readable
        if [ -r "$file_path" ]; then
            echo "The file is readable."
        else
            echo "The file is not readable."
        fi

        # Check if the file is writable
        if [ -w "$file_path" ]; then
            echo "The file is writable."
        else
            echo "The file is not writable."
        fi

        # Check if the file is executable
        if [ -x "$file_path" ]; then
            echo "The file is executable."
        else
            echo "The file is not executable."
        fi
    elif [ -d "$file_path" ]; then
        echo "It is a directory."
    else
        echo "It is neither a regular file nor a directory."
    fi
else
    echo "File or directory not found."
fi

