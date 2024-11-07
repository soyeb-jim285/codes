<h1 style='text-align: center;'> A. Tokitsukaze and All Zero Sequence</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Tokitsukaze has a sequence $a$ of length $n$. For each operation, she selects two numbers $a_i$ and $a_j$ ($i \ne j$; $1 \leq i,j \leq n$). 

* If $a_i = a_j$, change one of them to $0$.
* Otherwise change both of them to $\min(a_i, a_j)$.

Tokitsukaze wants to know the minimum number of operations to change all numbers in the sequence to $0$. It can be proved that the answer always exists.

## Input

The first line contains a single positive integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

For each test case, the first line contains a single integer $n$ ($2 \leq n \leq 100$) — the length of the sequence $a$.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 100$) — the sequence $a$.

## Output

For each test case, print a single integer — the minimum number of operations to change all numbers in the sequence to $0$.

## Example

## Input


```

331 2 331 2 231 2 0
```
## Output


```

4
3
2

```
## Note

In the first test case, one of the possible ways to change all numbers in the sequence to $0$:

In the $1$-st operation, $a_1 < a_2$, after the operation, $a_2 = a_1 = 1$. Now the sequence $a$ is $[1,1,3]$.

In the $2$-nd operation, $a_1 = a_2 = 1$, after the operation, $a_1 = 0$. Now the sequence $a$ is $[0,1,3]$.

In the $3$-rd operation, $a_1 < a_2$, after the operation, $a_2 = 0$. Now the sequence $a$ is $[0,0,3]$.

In the $4$-th operation, $a_2 < a_3$, after the operation, $a_3 = 0$. Now the sequence $a$ is $[0,0,0]$.

So the minimum number of operations is $4$.



#### tags 

#800 #implementation 