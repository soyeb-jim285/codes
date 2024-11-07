<h1 style='text-align: center;'> A. Koxia and Whiteboards</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kiyora has $n$ whiteboards numbered from $1$ to $n$. Initially, the $i$-th whiteboard has the integer $a_i$ written on it.

Koxia performs $m$ operations. The $j$-th operation is to choose one of the whiteboards and change the integer written on it to $b_j$.

Find the maximum possible sum of integers written on the whiteboards after performing all $m$ operations.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The description of test cases follows.

The first line of each test case contains two integers $n$ and $m$ ($1 \le n,m \le 100$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$).

The third line of each test case contains $m$ integers $b_1, b_2, \ldots, b_m$ ($1 \le b_i \le 10^9$).

## Output

For each test case, output a single integer — the maximum possible sum of integers written on whiteboards after performing all $m$ operations.

## Example

## Input


```

43 21 2 34 52 31 23 4 51 110015 31 1 1 1 11000000000 1000000000 1000000000
```
## Output


```

12
9
1
3000000002

```
## Note

In the first test case, Koxia can perform the operations as follows:

1. Choose the $1$-st whiteboard and rewrite the integer written on it to $b_1=4$.
2. Choose the $2$-nd whiteboard and rewrite to $b_2=5$.

After performing all operations, the numbers on the three whiteboards are $4$, $5$ and $3$ respectively, and their sum is $12$. It can be proven that this is the maximum possible sum achievable.

In the second test case, Koxia can perform the operations as follows:

1. Choose the $2$-nd whiteboard and rewrite to $b_1=3$.
2. Choose the $1$-st whiteboard and rewrite to $b_2=4$.
3. Choose the $2$-nd whiteboard and rewrite to $b_3=5$.

The sum is $4 + 5 = 9$. It can be proven that this is the maximum possible sum achievable.



#### tags 

#1000 #brute_force #greedy 