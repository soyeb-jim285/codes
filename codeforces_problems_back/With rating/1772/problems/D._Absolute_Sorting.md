<h1 style='text-align: center;'> D. Absolute Sorting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a$ consisting of $n$ integers. The array is sorted if $a_1 \le a_2 \le \dots \le a_n$.

You want to make the array $a$ sorted by applying the following operation exactly once:

* choose an integer $x$, then for every $i \in [1, n]$, replace $a_i$ by $|a_i - x|$.

Find any value of $x$ that will make the array sorted, or report that there is no such value.

## Input

The first line contains one integer $t$ ($1 \le t \le 2 \cdot 10^4$) — the number of test cases.

Each test case consists of two lines. The first line contains one integer $n$ ($2 \le n \le 2 \cdot 10^5$). The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^8$).

Additional constraint on the input: the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, print any integer $x$ ($0 \le x \le 10^9$) that makes the array sorted. It can be shown that if such an integer $x$ exists, there is at least one such integer between $0$ and $10^9$.

If there is no such integer, then print $-1$. If there are multiple suitable values of $x$, print any of them.

## Example

## Input


```

855 3 3 3 545 3 4 581 2 3 4 5 6 7 8610 5 4 3 2 133 3 1342 43 422100000000 99999999629613295 52036613 75100585 78027446 81409090 73215
```
## Output


```

4
-1
0
42
2
-1
100000000
40741153

```
## Note

In the first test case, after using $x = 4$, the array becomes $[1, 1, 1, 1, 1]$.

In the third test case, after using $x = 0$, the array becomes $[1, 2, 3, 4, 5, 6, 7, 8]$.

In the fourth test case, after using $x = 42$, the array becomes $[32, 37, 38, 39, 40, 41]$.



#### tags 

#1400 #constructive_algorithms #math 