<h1 style='text-align: center;'> B. Mex Master</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given an array $a$ of length $n$. The score of $a$ is the MEX$^{\dagger}$ of $[a_1+a_2,a_2+a_3,\ldots,a_{n-1}+a_n]$. Find the minimum score of $a$ if you are allowed to rearrange elements of $a$ in any order. ## Note

 that you are not required to construct the array $a$ that achieves the minimum score.

$^{\dagger}$ The MEX (minimum excluded) of an array is the smallest non-negative integer that does not belong to the array. For instance:

* The MEX of $[2,2,1]$ is $0$, because $0$ does not belong to the array.
* The MEX of $[3,1,0,1]$ is $2$, because $0$ and $1$ belong to the array, but $2$ does not.
* The MEX of $[0,3,1,2]$ is $4$ because $0$, $1$, $2$, and $3$ belong to the array, but $4$ does not.
## Input

The first line contains a single integer $t$ ($1\le t\le 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($2\le n\le 2\cdot10^5$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 2\cdot 10^5$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

## Output

For each test case, output the minimum score of $a$ after rearranging the elements of $a$ in any order.

## Example

## Input


```

320 030 0 181 0 0 0 2 0 3 0
```
## Output


```

1
0
1

```
## Note

In the first test case, it is optimal to rearrange $a$ as $[0,0]$, the score of this array is the MEX of $[0+0]=[0]$, which is $1$.

In the second test case, it is optimal to rearrange $a$ as $[0,1,0]$, the score of this array is the MEX of $[0+1,1+0]=[1,1]$, which is $0$.



#### tags 

#900 #constructive_algorithms #greedy 