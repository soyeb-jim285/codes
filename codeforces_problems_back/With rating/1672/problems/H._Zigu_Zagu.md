<h1 style='text-align: center;'> H. Zigu Zagu</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a binary string $a$ of length $n$ consisting only of digits $0$ and $1$. 

You are given $q$ queries. In the $i$-th query, you are given two indices $l$ and $r$ such that $1 \le l \le r \le n$. 

Let $s=a[l,r]$. You are allowed to do the following operation on $s$:

1. Choose two indices $x$ and $y$ such that $1 \le x \le y \le |s|$. Let $t$ be the substring $t = s[x, y]$. Then for all $1 \le i \le |t| - 1$, the condition $t_i \neq t_{i+1}$ has to hold. ## Note

 that $x = y$ is always a valid substring.
2. Delete the substring $s[x, y]$ from $s$.

For each of the $q$ queries, find the minimum number of operations needed to make $s$ an empty string.

## Note

 that for a string $s$, $s[l,r]$ denotes the subsegment $s_l,s_{l+1},\ldots,s_r$.

## Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10 ^ 5$)  — the length of the binary string $a$ and the number of queries respectively.

The second line contains a binary string $a$ of length $n$ ($a_i \in \{0, 1\}$).

Each of the next $q$ lines contains two integers $l$ and $r$ ($1 \le l \le r \le n$)  — representing the substring of each query.

## Output

Print $q$ lines, the $i$-th line representing the minimum number of operations needed for the $i$-th query.

## Examples

## Input


```

5 3
11011
2 4
1 5
3 5

```
## Output


```

1
3
2

```
## Input


```

10 3
1001110110
1 10
2 5
5 10

```
## Output


```

4
2
3

```
## Note

In the first test case, 

1. The substring is $\texttt{101}$, so we can do one operation to make the substring empty.
2. The substring is $\texttt{11011}$, so we can do one operation on $s[2, 4]$ to make $\texttt{11}$, then use two more operations to make the substring empty.
3. The substring is $\texttt{011}$, so we can do one operation on $s[1, 2]$ to make $\texttt{1}$, then use one more operation to make the substring empty.


#### tags 

#2700 #constructive_algorithms #data_structures #greedy 