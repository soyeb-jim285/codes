<h1 style='text-align: center;'> A. Wonderful Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

God's Blessing on This PermutationForces!A Random PebbleYou are given a permutation $p_1,p_2,\ldots,p_n$ of length $n$ and a positive integer $k \le n$. 

In one operation you can choose two indices $i$ and $j$ ($1 \le i < j \le n$) and swap $p_i$ with $p_j$.

Find the minimum number of operations needed to make the sum $p_1 + p_2 + \ldots + p_k$ as small as possible.

A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in arbitrary order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation ($2$ appears twice in the array) and $[1,3,4]$ is also not a permutation ($n=3$ but there is $4$ in the array).

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 100$).

The second line of each test case contains $n$ integers $p_1,p_2,\ldots,p_n$ ($1 \le p_i \le n$). It is guaranteed that the given numbers form a permutation of length $n$.

## Output

For each test case print one integer — the minimum number of operations needed to make the sum $p_1 + p_2 + \ldots + p_k$ as small as possible.

## Example

## Input


```

43 12 3 13 31 2 34 23 4 1 21 11
```
## Output


```

1
0
2
0

```
## Note

In the first test case, the value of $p_1 + p_2 + \ldots + p_k$ is initially equal to $2$, but the smallest possible value is $1$. You can achieve it by swapping $p_1$ with $p_3$, resulting in the permutation $[1, 3, 2]$.

In the second test case, the sum is already as small as possible, so the answer is $0$.



#### tags 

#800 #greedy #implementation 