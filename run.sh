#!/bin/bash

# Check if the exercise name is provided
if [ -z "$1" ]; then
    echo "Usage: ./run.sh <exercise_name>"
    exit 1
fi

EXERCISE_NAME=$1

# Find the file corresponding to the exercise name
EXERCISE_FILE="./$EXERCISE_NAME.cpp"

# Check if the exercise file exists
if [ ! -f "$EXERCISE_FILE" ]; then
    echo "Error: File $EXERCISE_FILE does not exist."
    exit 1
fi

# Compile the C++ code
g++ "$EXERCISE_FILE" -o "./output"
if [ $? -ne 0 ]; then
    echo "Compilation failed."
    exit 1
fi

# Run the compiled program
echo "Running $EXERCISE_NAME:"
"./output"
