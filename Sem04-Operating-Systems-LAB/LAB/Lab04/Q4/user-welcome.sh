#!/bin/bash

# Get the current time
current_time=$(date +"%H:%M")

# Get the current date in the specified format
login_date=$(date +"%d/%m/%Y")
# Get the current day
login_day=$(date +"%A")
# Get the timezone
login_timezone=$(date +"%Z")

# Get the current hour
hour=$(date +"%H")

# Greet the user based on the time
if [ $hour -ge 0 -a $hour -lt 12 ]; then
    greeting="Good morning"
elif [ $hour -ge 12 -a $hour -lt 17 ]; then
    greeting="Good afternoon"
else
    greeting="Good evening"
fi

# Display the welcome message
echo "[⦿] Welcome Master"
echo "[⦿] $USER [Login Details ( Date: $login_date | Day: $login_day | Time: $current_time | Timezone: $login_timezone )]"
echo "[⦿] ———————————————————————————"
echo "[⦿] $greeting, Mr.$USER"

# Wait for 10 seconds
sleep 10

# Check if it's night when the user logs out
if [ $hour -ge 21 -o $hour -lt 4 ]; then
    farewell="Good night"
else
    farewell="Have a good day"
fi

# Display the farewell message upon logout
trap "echo '[ ] $farewell, $USER'" EXIT

# Keep the script running to display messages
while true; do
    sleep 1
done
