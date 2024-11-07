<h1 style='text-align: center;'> A. Min Or Sum</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of size $n$.

You can perform the following operation on the array: 

* Choose two different integers $i, j$ $(1 \leq i < j \leq n$), replace $a_i$ with $x$ and $a_j$ with $y$. In order not to break the array, $a_i | a_j = x | y$ must be held, where $|$ denotes the [bitwise OR operation](https://en.wikipedia.org/wiki/Bitwise_operation#OR). Notice that $x$ and $y$ are non-negative integers.

Please output the minimum sum of the array you can get after using the operation above any number of times.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ $(1 \leq t \leq 1000)$. Description of the test cases follows.

The first line of each test case contains an integer $n$ $(2 \leq n \leq 100)$ — the size of array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots ,a_n$ $(0 \leq a_i < 2^{30})$.

## Output

For each test case, print one number in a line — the minimum possible sum of the array.

## Example

## Input


```

431 3 251 2 4 8 1626 633 5 6
```
## Output


```

3
31
6
7

```
## Note

In the first example, you can perform the following operations to obtain the array $[1, 0, 2]$:

1. choose $i = 1, j = 2$, change $a_1 = 1$ and $a_2 = 2$, it's valid since $1 | 3 = 1 | 2$. The array becomes $[1, 2, 2]$.

2. choose $i = 2, j = 3$, change $a_2 = 0$ and $a_3 = 2$, it's valid since $2 | 2 = 0 | 2$. The array becomes $[1, 0, 2]$.

We can prove that the minimum sum is $1 + 0 + 2 = 3$

In the second example, We don't need any operations.



#### tags 

#800 #bitmasks #greedy 