<h1 style='text-align: center;'> B. MKnez's ConstructiveForces Task</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

MKnez wants to construct an array $s_1,s_2, \ldots , s_n$ satisfying the following conditions:

* Each element is an integer number different from $0$;
* For each pair of adjacent elements their sum is equal to the sum of the whole array.

More formally, $s_i \neq 0$ must hold for each $1 \leq i \leq n$. Moreover, it must hold that $s_1 + s_2 + \cdots + s_n = s_i + s_{i+1}$ for each $1 \leq i < n$.

Help MKnez to construct an array with these properties or determine that it does not exist.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \leq t \leq 100$). The description of the test cases follows.

The only line of each test case contains a single integer $n$ ($2 \leq n \leq 1000$) — the length of the array.

## Output

For each test case, print "YES" if an array of length $n$ satisfying the conditions exists. Otherwise, print "NO". If the answer is "YES", on the next line print a sequence $s_1,s_2, \ldots, s_n$ satisfying the conditions. Each element should be a non-zero integer in the range $[-5000,5000]$, i. e. $-5000 \leq s_i \leq 5000$ and $s_i \neq 0$ should hold for each $1 \leq i \leq n$.

It can be proved that if a solution exists then there also exists one which satisfies the additional constraints on the range.

If there are several correct answers, print any of them. 

## Example

## Input


```

2
2
3

```
## Output


```

YES
9 5
NO

```
## Note

In the first test case, $[9,5]$ is a valid answer since $9+5$ (the sum of the two adjacent elements $s_1+s_2$) is equal to $9+5$ (the sum of all elements). Other solutions include $[6,-9], [-1,-2], [-5000,5000], \ldots$

For the second test case, let us show why some arrays do not satisfy the constraints:

* $[1,1,1]$  — $s_1+s_2 = 1+1 = 2$ and $s_1+s_2+s_3=1+1+1 = 3$ differ;
* $[1,-1,1]$  — $s_1+s_2=1+(-1)=0$ and $s_1+s_2+s_3=1+(-1)+1 = 1$ differ;
* $[0,0,0]$  — The array $s$ cannot contain a $0$.

This is not a proof, but it can be shown that the answer is "NO".



#### tags 

#900 #constructive_algorithms #math 