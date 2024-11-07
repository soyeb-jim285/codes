<h1 style='text-align: center;'> E. MEX of LCM</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given an array $a$ of length $n$. A positive integer $x$ is called good if it is impossible to find a subsegment$^{\dagger}$ of the array such that the [least common multiple](https://en.wikipedia.org/wiki/Least_common_multiple) of all its elements is equal to $x$.

You need to find the smallest good integer.

A subsegment$^{\dagger}$ of the array $a$ is a set of elements $a_l, a_{l + 1}, \ldots, a_r$ for some $1 \le l \le r \le n$. We will denote such subsegment as $[l, r]$.

## Input

Each test consists of multiple test cases. The first line of each test case contains a single integer $t$ ($1 \le t \le 5 \cdot 10^4$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 3 \cdot 10^5$) — the length of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots , a_n$ ($1 \leq a_i \leq 10^9$) — the elements of the array $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

## Output

For each test case, output a single integer — the smallest good integer.

## Example

## Input


```

631 2 351 2 3 4 522 311000000000121 8 4 2 3 5 7 2 9 10 11 13127 2 5 4 2 1 1 2 3 11 8 9
```
## Output


```

4
7
1
1
16
13

```
## Note

In the first test case, $4$ is a good integer, and it is the smallest one, since the integers $1,2,3$ appear in the array, which means that there are subsegments of the array of length $1$ with least common multiples of $1,2,3$. However, it is impossible to find a subsegment of the array with a least common multiple equal to $4$.

In the second test case, $7$ is a good integer. The integers $1,2,3,4,5$ appear explicitly in the array, and the integer $6$ is the least common multiple of the subsegments $[2, 3]$ and $[1, 3]$.

In the third test case, $1$ is a good integer, since the least common multiples for the integer in the subsegments $[1, 1], [1, 2], [2, 2]$ are $2,6,3$, respectively.



#### tags 

#2300 #binary_search #data_structures #implementation #math #number_theory 