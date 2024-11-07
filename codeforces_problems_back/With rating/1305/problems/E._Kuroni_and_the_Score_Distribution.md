<h1 style='text-align: center;'> E. Kuroni and the Score Distribution</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Kuroni is the coordinator of the next Mathforces round written by the "Proof by AC" team. All the preparation has been done, and he is discussing with the team about the score distribution for the round.

The round consists of $n$ problems, numbered from $1$ to $n$. The problems are ordered in increasing order of difficulty, no two problems have the same difficulty. A score distribution for the round can be denoted by an array $a_1, a_2, \dots, a_n$, where $a_i$ is the score of $i$-th problem. 

Kuroni thinks that the score distribution should satisfy the following requirements:

* The score of each problem should be a positive integer not exceeding $10^9$.
* A harder problem should grant a strictly higher score than an easier problem. In other words, $1 \leq a_1 < a_2 < \dots < a_n \leq 10^9$.
* The balance of the score distribution, defined as the number of triples $(i, j, k)$ such that $1 \leq i < j < k \leq n$ and $a_i + a_j = a_k$, should be exactly $m$.

Help the team find a score distribution that satisfies Kuroni's requirement. In case such a score distribution does not exist, output $-1$.

## Input

The first and single line contains two integers $n$ and $m$ ($1 \le n \le 5000$, $0 \leq m \leq 10^9$) — the number of problems and the required balance.

## Output

If there is no solution, print a single integer $-1$.

Otherwise, print a line containing $n$ integers $a_1, a_2, \dots, a_n$, representing a score distribution that satisfies all the requirements. If there are multiple answers, print any of them.

## Examples

## Input


```

5 3

```
## Output


```

4 5 9 13 18
```
## Input


```

8 0

```
## Output


```

10 11 12 13 14 15 16 17

```
## Input


```

4 10

```
## Output


```

-1

```
## Note

In the first example, there are $3$ triples $(i, j, k)$ that contribute to the balance of the score distribution. 

* $(1, 2, 3)$
* $(1, 3, 4)$
* $(2, 4, 5)$


#### tags 

#2200 #constructive_algorithms #greedy #implementation #math 