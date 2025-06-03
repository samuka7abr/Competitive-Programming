#!/bin/bash

cd CodeForces/

read -p "Contest number (e.g., 1028): " contest_number
read -p "Problem number: " problem_number

contest_dir=$(find . -type d -name "*${contest_number}*" | head -n 1)

if [ -z "$contest_dir" ]; then
  echo "Error: Contest folder containing '$contest_number' not found."
  exit 1
fi

problem_path="$contest_dir/$(printf '%02d' "$problem_number")"
letter=$(printf "\\$(printf '%03o' $((64 + problem_number)))")

if [ ! -f "$problem_path/${letter}.cpp" ]; then
  echo "Error: Source file not found: $problem_path/${letter}.cpp"
  exit 1
fi

g++ "$problem_path/${letter}.cpp" -o "$problem_path/exec"

"$problem_path/exec" < "$problem_path/args/input" > "$problem_path/args/output"

if diff -p <(sed 's/[[:space:]]\+$//' "$problem_path/args/output") \
          <(sed 's/[[:space:]]\+$//' "$problem_path/args/expected"); then
  echo -e "\033[1;32mSuccess: Output matches expected.\033[0m"
else
  echo -e "\033[1;31mError: Output differs from expected.\033[0m"
fi
