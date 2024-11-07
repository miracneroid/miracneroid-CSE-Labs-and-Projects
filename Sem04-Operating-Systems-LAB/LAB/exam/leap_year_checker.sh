#!/bin/bash

is_leap_year() {
    year=$1

    if ( year % 4 == 0 ); then
        if ( year % 100 == 0 ); then
            if ( year % 400 == 0 ); then
                return 0 
            else
                return 1 
            fi
        else
            return 0
        fi
    else
        return 1 
    fi
}

read -p "Enter a year: " year

if is_leap_year "$year"; then
    echo "$year is a leap year."
else
    echo "$year is not a leap year."
fi