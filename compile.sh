#!/bin/bash

# Check if the input file is provided
if [ -z "$1" ]; then
  echo "Usage: $0 <cpp_file>"
  exit 1
fi

filename=$(basename -- "$1")
output_name="${filename%.*}"

mkdir -p out

g++ -std=c++11 "$1" -o "out/$output_name"

if [ $? -eq 0 ]; then
  echo "Compilation successful. Output binary: out/$output_name"
else
  echo "Compilation failed."
fi
