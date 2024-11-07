<h1 style='text-align: center;'> D. Divisible Pairs</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarp has two favorite integers $x$ and $y$ (they can be equal), and he has found an array $a$ of length $n$.

Polycarp considers a pair of indices $\langle i, j \rangle$ ($1 \le i < j \le n$) beautiful if: 

* $a_i + a_j$ is divisible by $x$;
* $a_i - a_j$ is divisible by $y$.

For example, if $x=5$, $y=2$, $n=6$, $a=$[$1, 2, 7, 4, 9, 6$], then the only beautiful pairs are: 

* $\langle 1, 5 \rangle$: $a_1 + a_5 = 1 + 9 = 10$ ($10$ is divisible by $5$) and $a_1 - a_5 = 1 - 9 = -8$ ($-8$ is divisible by $2$);
* $\langle 4, 6 \rangle$: $a_4 + a_6 = 4 + 6 = 10$ ($10$ is divisible by $5$) and $a_4 - a_6 = 4 - 6 = -2$ ($-2$ is divisible by $2$).

 Find the number of beautiful pairs in the array $a$.## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. Then the descriptions of the test cases follow.

The first line of each test case contains three integers $n$, $x$, and $y$ ($2 \le n \le 2 \cdot 10^5$, $1 \le x, y \le 10^9$) — the size of the array and Polycarp's favorite integers.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer — the number of beautiful pairs in the array $a$.

## Example

## Input


```

76 5 21 2 7 4 9 67 9 51 10 15 3 8 12 159 4 1014 10 2 2 11 11 13 5 69 5 610 7 6 7 9 7 7 10 109 6 24 9 7 1 2 2 13 3 159 2 314 6 1 15 12 15 8 2 1510 5 713 3 3 2 12 11 3 7 13 14
```
## Output


```

2
0
1
3
5
7
0

```


#### tags 

#1300 #combinatorics #math #number_theory 