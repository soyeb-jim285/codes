<h1 style='text-align: center;'> D. Array Repetition</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Jayden has an array $a$ which is initially empty. There are $n$ operations of two types he must perform in the given order.

1. Jayden appends an integer $x$ ($1 \leq x \leq n$) to the end of array $a$.
2. Jayden appends $x$ copies of array $a$ to the end of array $a$. In other words, array $a$ becomes $[a,\underbrace{a,\ldots,a}_{x}]$. It is guaranteed that he has done at least one operation of the first type before this.

Jayden has $q$ queries. For each query, you must tell him the $k$-th element of array $a$. The elements of the array are numbered from $1$.

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 5000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two integers $n$ and $q$ ($1 \leq n, q \leq 10^5$) — the number of operations and the number of queries.

The following $n$ lines describe the operations. Each line contains two integers $b$ and $x$ ($b \in \{1, 2\}$), where $b$ denotes the type of operation. If $b=1$, then $x$ ($1 \leq x \leq n$) is the integer Jayden appends to the end of the array. If $b=2$, then $x$ ($1 \leq x \leq 10^9$) is the number of copies Jayden appends to the end of the array. 

The next line of each test case contains $q$ integers $k_1, k_2, \ldots, k_q$ ($1 \leq k_i \leq \min(10^{18}, c)$), which denote the queries, where $c$ is the size of the array after finishing all $n$ operations.

It is guaranteed that the sum of $n$ and the sum of $q$ over all test cases does not exceed $10^5$. 

## Output

For each test case, output $q$ integers — answers to Jayden's queries.

## Example

## Input


```

45 101 11 22 11 32 31 2 3 4 5 6 14 15 16 2010 101 31 82 151 61 91 12 61 12 122 1032752 25178 3198 3199 2460 2461 31450 33260 9016 499612 51 61 112 3921303341 42 7448117501 101 52 2093737802 1789289841 32 6583264642 1000000000914576963034536490 640707385283752918 636773368365261971 584126563607944922 10000000000000000002 21 11 21 2
```
## Output


```

1 2 1 2 3 1 2 3 1 3
9 8 1 3 1 3 6 3 8 8
11 11 11 10 11
1 2

```
## Note

In the first test case:

* After the first operation $a = [1]$;
* After the second operation $a = [1, 2]$;
* After the third operation $a = [1, 2, 1, 2]$;
* After the fourth operation $a = [1, 2, 1, 2, 3]$;
* After the fifth operation $a = [1, 2, 1, 2, 3, 1, 2, 1, 2, 3, 1, 2, 1, 2, 3, 1, 2, 1, 2, 3]$.

In the fourth test case, after all operations $a = [1, 2]$.



#### tags 

#1900 #binary_search #brute_force #dsu #implementation #math 