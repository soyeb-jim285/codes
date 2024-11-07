<h1 style='text-align: center;'> D. Deducing Sortability</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Let's say Pak Chanek has an array $A$ consisting of $N$ positive integers. Pak Chanek will do a number of operations. In each operation, Pak Chanek will do the following: 

1. Choose an index $p$ ($1 \leq p \leq N$).
2. Let $c$ be the number of operations that have been done on index $p$ before this operation.
3. Decrease the value of $A_p$ by $2^c$.
4. Multiply the value of $A_p$ by $2$.

After each operation, all elements of $A$ must be positive integers.

An array $A$ is said to be sortable if and only if Pak Chanek can do zero or more operations so that $A_1 < A_2 < A_3 < A_4 < \ldots < A_N$.

Pak Chanek must find an array $A$ that is sortable with length $N$ such that $A_1 + A_2 + A_3 + A_4 + \ldots + A_N$ is the minimum possible. If there are more than one possibilities, Pak Chanek must choose the array that is lexicographically minimum among them.

Pak Chanek must solve the following things: 

* Pak Chanek must print the value of $A_1 + A_2 + A_3 + A_4 + \ldots + A_N$ for that array.
* $Q$ questions will be given. For the $i$-th question, an integer $P_i$ is given. Pak Chanek must print the value of $A_{P_i}$.

Help Pak Chanek solve the problem.

## Note

: an array $B$ of size $N$ is said to be lexicographically smaller than an array $C$ that is also of size $N$ if and only if there exists an index $i$ such that $B_i < C_i$ and for each $j < i$, $B_j = C_j$.

## Input

The first line contains two integers $N$ and $Q$ ($1 \leq N \leq 10^9$, $0 \leq Q \leq \min(N, 10^5)$) — the required length of array $A$ and the number of questions.

The $i$-th of the next $Q$ lines contains a single integer $P_i$ ($1 \leq P_1 < P_2 < \ldots < P_Q \leq N$) — the index asked in the $i$-th question.

## Output

Print $Q+1$ lines. The $1$-st line contains an integer representing $A_1 + A_2 + A_3 + A_4 + \ldots + A_N$. For each $1 \leq i \leq Q$, the $(i+1)$-th line contains an integer representing $A_{P_i}$.

## Examples

## Input


```

6 3
1
4
5

```
## Output


```

17
1
3
4

```
## Input


```

1 0

```
## Output


```

1

```
## Note

In the first example, the array $A$ obtained is $[1, 2, 3, 3, 4, 4]$. We can see that the array is sortable by doing the following operations: 

* Choose index $5$, then $A = [1, 2, 3, 3, 6, 4]$.
* Choose index $6$, then $A = [1, 2, 3, 3, 6, 6]$.
* Choose index $4$, then $A = [1, 2, 3, 4, 6, 6]$.
* Choose index $6$, then $A = [1, 2, 3, 4, 6, 8]$.


#### tags 

#2900 #binary_search #bitmasks #math 