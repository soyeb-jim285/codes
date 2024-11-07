<h1 style='text-align: center;'> I. Two Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 8 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Consider an array of integers $C = [c_1, c_2, \ldots, c_n]$ of length $n$. Let's build the sequence of arrays $D_0, D_1, D_2, \ldots, D_{n}$ of length $n+1$ in the following way:

* The first element of this sequence will be equals $C$: $D_0 = C$.
* For each $1 \leq i \leq n$ array $D_i$ will be constructed from $D_{i-1}$ in the following way:
	+ Let's find the lexicographically smallest subarray of $D_{i-1}$ of length $i$. Then, the first $n-i$ elements of $D_i$ will be equals to the corresponding $n-i$ elements of array $D_{i-1}$ and the last $i$ elements of $D_i$ will be equals to the corresponding elements of the found subarray of length $i$.

Array $x$ is subarray of array $y$, if $x$ can be obtained by deletion of several (possibly, zero or all) elements from the beginning of $y$ and several (possibly, zero or all) elements from the end of $y$.

For array $C$ let's denote array $D_n$ as $op(C)$.

Alice has an array of integers $A = [a_1, a_2, \ldots, a_n]$ of length $n$. She will build the sequence of arrays $B_0, B_1, \ldots, B_n$ of length $n+1$ in the following way:

* The first element of this sequence will be equals $A$: $B_0 = A$.
* For each $1 \leq i \leq n$ array $B_i$ will be equals $op(B_{i-1})$, where $op$ is the transformation described above.

She will ask you $q$ queries about elements of sequence of arrays $B_0, B_1, \ldots, B_n$. Each query consists of two integers $i$ and $j$, and the answer to this query is the value of the $j$-th element of array $B_i$.

## Input

The first line contains the single integer $n$ ($1 \leq n \leq 10^5$) — the length of array $A$.

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \leq a_i \leq n$) — the array $A$.

The third line contains the single integer $q$ ($1 \leq q \leq 10^6$) — the number of queries.

Each of the next $q$ lines contains two integers $i$, $j$ ($1 \leq i, j \leq n$) — parameters of queries.

## Output

## Output

 $q$ integers: values of $B_{i, j}$ for required $i$, $j$.

## Example

## Input


```

4
2 1 3 1
4
1 1
1 2
1 3
1 4

```
## Output


```

2
1
1
3

```
## Note

In the first test case $B_0 = A = [2, 1, 3, 1]$.

$B_1$ is constructed in the following way:

* Initially, $D_0 = [2, 1, 3, 1]$.
* For $i=1$ the lexicographically smallest subarray of $D_0$ of length $1$ is $[1]$, so $D_1$ will be $[2, 1, 3, 1]$.
* For $i=2$ the lexicographically smallest subarray of $D_1$ of length $2$ is $[1, 3]$, so $D_2$ will be $[2, 1, 1, 3]$.
* For $i=3$ the lexicographically smallest subarray of $D_2$ of length $3$ is $[1, 1, 3]$, so $D_3$ will be $[2, 1, 1, 3]$.
* For $i=4$ the lexicographically smallest subarray of $D_3$ of length $4$ is $[2, 1, 1, 3]$, so $D_4$ will be $[2, 1, 1, 3]$.
* So, $B_1 = op(B_0) = op([2, 1, 3, 1]) = [2, 1, 1, 3]$.


#### tags 

#3500 #data_structures #hashing #string_suffix_structures 