<h1 style='text-align: center;'> A. Increasing and Decreasing</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given three integers $x$, $y$, and $n$.

Your task is to construct an array $a$ consisting of $n$ integers which satisfies the following conditions:

1. $a_1=x$, $a_n=y$;
2. $a$ is strictly increasing (i.e. $a_1 < a_2 < \ldots < a_n$);
3. if we denote $b_i=a_{i+1}-a_{i}$ for $1 \leq i \leq n-1$, then $b$ is strictly decreasing (i.e. $b_1 > b_2 > \ldots > b_{n-1}$).

If there is no such array $a$, print a single integer $-1$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 1000$). The description of the test cases follows.

The only line of each test case contains three integers $x$, $y$, $n$ ($1 \le x < y \le 1000,3 \le n \le 1000$).

## Output

For each test case, output $n$ integers $a_1,a_2,\ldots,a_n$. If there are multiple solutions, print any of them.

If there is no solution, print a single integer $-1$.

## Example

## Input


```

31 4 31 3 3100 200 4
```
## Output


```

1 3 4
-1
100 150 180 200

```
## Note

In the first test case, $a=[1,3,4]$, which is strictly increasing. Next, $b_1=a_2-a_1=3-1=2$, $b_2=a_3-a_2=4-3=1$, thus $b=[2,1]$, which is strictly decreasing.

In the second test case, there is no array $a$ that satisfies all the conditions above.



#### tags 

#800 #constructive_algorithms #greedy #implementation #math 