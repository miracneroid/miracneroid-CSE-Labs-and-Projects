#!/bin/bash

# Function to calculate the grade based on average marks
calculate_grade() {
    average_marks=$1

    if [ "$average_marks" -ge 90 ]; then
        grade="A+"
    elif [ "$average_marks" -ge 80 ]; then
        grade="A"
    elif [ "$average_marks" -ge 70 ]; then
        grade="B"
    elif [ "$average_marks" -ge 60 ]; then
        grade="C"
    elif [ "$average_marks" -ge 50 ]; then
        grade="D"
    else
        grade="F"
    fi
}

# Taking input for five subjects
echo "Enter marks for Subject 1:"
read subject1
echo "Enter marks for Subject 2:"
read subject2
echo "Enter marks for Subject 3:"
read subject3
echo "Enter marks for Subject 4:"
read subject4
echo "Enter marks for Subject 5:"
read subject5

# Calculate average marks
total_marks=$((subject1 + subject2 + subject3 + subject4 + subject5))
average_marks=$((total_marks / 5))

# Display average marks and calculate grade
echo "Average Marks: $average_marks"
calculate_grade "$average_marks"
echo "Grade: $grade"
