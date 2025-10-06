#!/bin/bash

# Check if both arguments are provided
if [ $# -ne 2 ]; then
    echo "Error: Two arguments required - <file_path> <write_string>"
    exit 1
fi

writefile="$1"
writestr="$2"

# Extract the directory path from the full file path
dirpath=$(dirname "$writefile")

# Create the directory if it doesn't exist
mkdir -p "$dirpath"
if [ $? -ne 0 ]; then
    echo "Error: Failed to create directory '$dirpath'"
    exit 1
fi

# Write the string to the file, overwriting if it exists
echo "$writestr" > "$writefile"
if [ $? -ne 0 ]; then
    echo "Error: Failed to write to file '$writefile'"
    exit 1
fi

# Successful execution
exit 0
