#!/bin/bash

# Read the maximum value for process IDs from /proc/sys/kernel/pid_max
max_pid=$(cat /proc/sys/kernel/pid_max)

# Print the maximum PID value
echo "The maximum process ID value is: $max_pid"
