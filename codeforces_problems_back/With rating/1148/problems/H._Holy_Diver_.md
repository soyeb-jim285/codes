<h1 style='text-align: center;'> H. Holy Diver </h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 1024 megabytes</h5>

You are given an array which is initially empty. You need to perform $n$ operations of the given format: 

* "$a$ $l$ $r$ $k$": append $a$ to the end of the array. After that count the number of integer pairs $x, y$ such that $l \leq x \leq y \leq r$ and $\operatorname{mex}(a_{x}, a_{x+1}, \ldots, a_{y}) = k$.

The elements of the array are numerated from $1$ in the order they are added to the array.

To make this problem more tricky we don't say your real parameters of the queries. Instead your are given $a'$, $l'$, $r'$, $k'$. To get $a$, $l$, $r$, $k$ on the $i$-th operation you need to perform the following: 

* $a := (a' + lans) \bmod(n + 1)$,
* $l := (l' + lans) \bmod{i} + 1$,
* $r := (r' + lans) \bmod{i} + 1$,
* if $l > r$ swap $l$ and $r$,
* $k := (k' + lans) \bmod(n + 1)$,

 where $lans$ is the answer to the previous operation, initially $lans$ is equal to zero. $i$ is the id of the operation, operations are numbered from $1$.The $\operatorname{mex}(S)$, where $S$ is a multiset of non-negative integers, is the smallest non-negative integer which does not appear in the set. For example, $\operatorname{mex}(\{2, 2, 3\}) = 0$ and $\operatorname{mex} (\{0, 1, 4, 1, 6\}) = 2$. 

## Input

The first line contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the length of the array.

The next $n$ lines contain the description of queries.

Each of them $n$ lines contains four non-negative integers $a'$, $l'$, $r'$, $k'$ ($0, \leq a', l', r', k' \leq 10^9$), describing one operation.

## Output

For each query print a single integer — the answer to this query.

## Examples

## Input


```

5
0 0 0 1
0 1 0 5
5 2 1 0
5 2 1 0
2 4 3 3

```
## Output


```

1
1
2
6
3

```
## Input


```

5
2 0 0 2
2 0 1 1
0 0 2 0
3 2 2 0
0 2 3 0

```
## Output


```

0
0
3
0
0

```
## Note

For the first example the decoded values of $a$, $l$, $r$, $k$ are the following:

$a_1=0,l_1=1,r_1=1,k_1=1$

$a_2=1,l_2=1,r_2=2,k_2=0$

$a_3=0,l_3=1,r_3=3,k_3=1$

$a_4=1,l_4=1,r_4=4,k_4=2$

$a_5=2,l_5=1,r_5=5,k_5=3$

For the second example the decoded values of $a$, $l$, $r$, $k$ are the following:

$a_1=2,l_1=1,r_1=1,k_1=2$

$a_2=2,l_2=1,r_2=2,k_2=1$

$a_3=0,l_3=1,r_3=3,k_3=0$

$a_4=0,l_4=2,r_4=2,k_4=3$

$a_5=0,l_5=3,r_5=4,k_5=0$



#### tags 

#3500 #data_structures 