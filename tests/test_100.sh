#!/bin/bash

# Function to execute push_swap with each permutation
# Arguments:
#   $1 - permutation to execute push_swap with
execute_push_swap() {
    local permutation="$1"
    echo "Executing push_swap with permutation: $permutation"
    ./push_swap "$permutation" > output.txt
    #cat output.txt
    command_count=$(wc -l < output.txt)
    echo "Number of commands printed: $command_count"
}

# Read permutations from file and execute push_swap
while IFS= read -r permutation; do
    execute_push_swap "$permutation"
done < tests/numbers_100_small.txt
