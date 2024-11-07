<h1 style='text-align: center;'> E. Increasing Subsequences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Let's recall that an increasing subsequence of the array $a$ is a sequence that can be obtained from it by removing some elements without changing the order of the remaining elements, and the remaining elements are strictly increasing (i. e $a_{b_1} < a_{b_2} < \dots < a_{b_k}$ and $b_1 < b_2 < \dots < b_k$). Note that an empty subsequence is also increasing.

You are given a positive integer $X$. Your task is to find an array of integers of length at most $200$, such that it has exactly $X$ increasing subsequences, or report that there is no such array. If there are several answers, you can print any of them.

If two subsequences consist of the same elements, but correspond to different positions in the array, they are considered different (for example, the array $[2, 2]$ has two different subsequences equal to $[2]$).

## Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The only line of each test case contains a single integer $X$ ($2 \le X \le 10^{18}$).

## Output

For each query, print the answer to it. If it is impossible to find the required array, print -1 on the first line. Otherwise, print a positive integer $n$ on the first line — the length of the array. On the second line, print $n$ integers — the required array itself. If there are several answers, you can print any of them. All elements of the array should be in the range $[-10^9; 10^9]$.

## Example

## Input


```

4251337
```
## Output


```

1
0
3
0 1 0
5
2 2 3 4 2
7
-1 -1 0 0 2 3 -1
```


#### tags 

#1800 #bitmasks #constructive_algorithms #divide_and_conquer #greedy #math 