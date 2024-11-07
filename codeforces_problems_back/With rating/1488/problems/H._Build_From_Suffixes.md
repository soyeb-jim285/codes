<h1 style='text-align: center;'> H. Build From Suffixes</h1>

<h5 style='text-align: center;'>time limit per test: 10 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an integer $n$ and a sequence $a$ of $n-1$ integers, each element is either $0$ or $1$.

You are asked to build a string of length $n$ such that: 

* each letter is one of "abcd";
* if $a_i=1$, then the $i$-th suffix of the string is lexicographically smaller than the $(i+1)$-th suffix;
* if $a_i=0$, then the $i$-th suffix of the string is lexicographically greater than the $(i+1)$-th suffix.

You will be asked $q$ queries of form: 

* $i$ ($1 \le i \le n - 1$) — flip the value of $a_i$ (if $a_i=0$, then set $a_i$ to $1$, and vice versa).

After each query print the number of different strings that satisfy the given constraints modulo $998\,244\,353$.

## Input

The first line contains two integers $n$ and $q$ ($2 \le n \le 10^5$; $1 \le q \le 10^5$) — the length of the string and the number of queries.

The second line contains $n-1$ integers $a_1, a_2, \dots, a_{n-1}$ ($a_i \in \{0, 1\}$) — the constraints on suffixes of the string.

Each of the next $q$ lines contains a query: an integer $i$ ($1 \le i \le n - 1$) — flip the value of $a_i$ (if $a_i=0$, then set $a_i$ to $1$, and vice versa).

## Output

After each query print the number of different strings that satisfy the given constraints modulo $998\,244\,353$.

## Examples

## Input


```

2 2
0
1
1

```
## Output


```

6
10

```
## Input


```

3 4
0 0
1
2
1
2

```
## Output


```

20
10
14
20

```
## Input


```

10 10
0 0 0 1 1 1 0 1 0
4
1
8
4
2
9
5
6
6
8

```
## Output


```

1815
3201
2710
2776
2290
1644
2668
1271
2668
2436

```
## Note

The $i$-th suffix of a string is a continuous substring that starts from the $i$-th position and ends in the last position.

A string $a$ is lexicographically smaller than a string $b$ if and only if one of the following holds: 

* $a$ is a prefix of $b$, but $a \ne b$;
* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.

Two strings $a$ and $b$ of length $n$ differ if there exists a position $i$ such that $a_i \neq b_i$.



#### tags 

#2800 #*special #combinatorics #data_structures 