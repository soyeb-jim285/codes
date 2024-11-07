#!/bin/bash
# chmod +x stresstest.sh
if [ "$#" -ne 2 ]; then
  echo "Usage: ./your_script.sh test_file brute_file mycode_file"
  exit 1
fi
test_file=$1
brute_file=$2
g++ -Wall -O2 "$test_file" -o test
g++ -Wall -O2 "$brute_file" -o brute
for ((i = 1; i <= 10000; i++)); do
  ./brute >myans.txt
  # Print the execution time
  if ! diff -q correct.txt myans.txt >/dev/null 2>&1; then
    echo -e "Test $i: \e[31mFailed \xE2\x9D\x8C\e[0m"
    # cat tests.txt
    break
  fi
  echo -e "Test $i: \e[32mPassed \u2714\ufe0e\e[0m"
done
