<h1 style='text-align: center;'> E. MinimizOR</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of $n$ non-negative integers, numbered from $1$ to $n$.

Let's define the cost of the array $a$ as $\displaystyle \min_{i \neq j} a_i | a_j$, where $|$ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR).

There are $q$ queries. For each query you are given two integers $l$ and $r$ ($l < r$). For each query you should find the cost of the subarray $a_{l}, a_{l + 1}, \ldots, a_{r}$.

## Input

Each test case consists of several test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains an integer $n$ ($2 \le n \le 10^5$) — the length array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i < 2^{30}$) — the elements of $a$.

The third line of each test case contains an integer $q$ ($1 \le q \le 10^5$) — the number of queries.

Each of the next $q$ lines contains two integers $l_j$, $r_j$ ($1 \le l_j < r_j \le n$) — the description of the $j$-th query.

It is guaranteed that the sum of $n$ and the sum of $q$ over all test cases do not exceed $10^5$.

## Output

For each test case print $q$ numbers, where the $j$-th number is the cost of array $a_{l_j}, a_{l_j + 1}, \ldots, a_{r_j}$.

## Example

## Input


```

256 1 3 2 141 22 32 42 540 2 1 107374182341 22 31 33 4
```
## Output


```

7
3
3
1
2
3
1
1073741823

```
## Note

In the first test case the array $a$ is

$110_2, 001_2, 011_2, 010_2, 001_2$.

That's why the answers for the queries are:

* $[1; 2]$: $a_1 | a_2 = 110_2 | 001_2 = 111_2 = 7$;
* $[2; 3]$: $a_2 | a_3 = 001_2 | 011_2 = 011_2 = 3$;
* $[2; 4]$: $a_2 | a_3 = a_3 | a_4 = a_2 | a_4 = 011_2 = 3$;
* $[2; 5]$: $a_2 | a_5 = 001_2 = 1$.

In the second test case the array $a$ is

$00_2, 10_2, 01_2, \underbrace{11\ldots 1_2}_{30}$ ($a_4 = 2^{30} - 1$).

That's why the answers for the queries are:

* $[1; 2]$: $a_1 | a_2 = 10_2 = 2$;
* $[2; 3]$: $a_2 | a_3 = 11_2 = 3$;
* $[1; 3]$: $a_1 | a_3 = 01_2 = 1$;
* $[3; 4]$: $a_3 | a_4 = 01_2 | \underbrace{11\ldots 1_2}_{30} = 2^{30} - 1 = 1073741823$.


#### tags 

#2500 #bitmasks #brute_force #data_structures #divide_and_conquer #greedy #implementation #two_pointers 