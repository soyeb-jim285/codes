<h1 style='text-align: center;'> C. Make Equal With Mod</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of $n$ non-negative integers $a_1, a_2, \ldots, a_n$. You can make the following operation: choose an integer $x \geq 2$ and replace each number of the array by the remainder when dividing that number by $x$, that is, for all $1 \leq i \leq n$ set $a_i$ to $a_i \bmod x$.

Determine if it is possible to make all the elements of the array equal by applying the operation zero or more times.

## Input

The input consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 10^5$) — the length of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 10^9$) where $a_i$ is the $i$-th element of the array.

The sum of $n$ for all test cases is at most $2 \cdot 10^5$.

## Output

For each test case, print a line with YES if you can make all elements of the list equal by applying the operation. Otherwise, print NO.

You may print each letter in any case (for example, "YES", "Yes", "yes", "yEs" will all be recognized as a positive answer).

## Example

## Input


```

442 5 6 831 1 154 1 7 0 845 9 17 5
```
## Output


```

YES
YES
NO
YES

```
## Note

In the first test case, one can apply the operation with $x = 3$ to obtain the array $[2, 2, 0, 2]$, and then apply the operation with $x = 2$ to obtain $[0, 0, 0, 0]$.

In the second test case, all numbers are already equal.

In the fourth test case, applying the operation with $x = 4$ results in the array $[1, 1, 1, 1]$.



#### tags 

#1200 #constructive_algorithms #math #number_theory #sortings 