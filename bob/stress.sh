#!/bin/bash
# chmod +x stresstest.sh
[[ $# -ne 3 ]] && echo "Usage: $0 test_file brute_file mycode_file" && exit 1
g++ -O2 "$1" -o test && g++ -O2 "$2" -o brute && g++ -O2 "$3" -o mycode
for ((i = 1; i <= 10000; i++)); do
  ./test >tests.txt
  ./brute <tests.txt >correct.txt
  timeout 1 ./mycode <tests.txt >myans.txt || {
    echo "Execution time exceeded"
    break
  }
  diff -q correct.txt myans.txt >/dev/null || {
    echo -e "Test $i: \e[31mFailed ❌\e[0m"
    break
  }
  echo -e "Test $i: \e[32mPassed ✔\e[0m"
done
