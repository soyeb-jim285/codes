<h1 style='text-align: center;'> D. Prefix Purchase</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have an array $a$ of size $n$, initially filled with zeros ($a_1 = a_2 = \ldots = a_n = 0$). You also have an array of integers $c$ of size $n$.

Initially, you have $k$ coins. By paying $c_i$ coins, you can add $1$ to all elements of the array $a$ from the first to the $i$-th element ($a_j \mathrel{+}= 1$ for all $1 \leq j \leq i$). You can buy any $c_i$ any number of times. A purchase is only possible if $k \geq c_i$, meaning that at any moment $k \geq 0$ must hold true.

Find the lexicographically largest array $a$ that can be obtained.

An array $a$ is lexicographically smaller than an array $b$ of the same length if and only if in the first position where $a$ and $b$ differ, the element in array $a$ is smaller than the corresponding element in $b$.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases. This is followed by a description of the test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the size of arrays $a$ and $c$.

The second line of each test case contains $n$ integers $c_1, c_2, \ldots, c_n$ ($1 \leq c_i \leq 10^9$) — the array $c$.

The third line of each test case contains a single integer $k$ ($1 \leq k \leq 10^9$) — the number of coins you have.

It is guaranteed that the sum of all $n$ values across all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output $n$ integers $a_1, a_2, \ldots, a_n$ — the lexicographically largest array $a$ that can be obtained.

## Example

## Input


```

431 2 3523 4733 2 12610 6 4 6 3 47
```
## Output


```

5 0 0 
2 1 
2 2 2 
2 2 2 2 2 1 

```
## Note

In the first test case, $a_1$ cannot be greater than $5$, and if we buy $c_1$ five times, we will run out of money, so $a = [5, 0, 0]$.

In the second test case, $a_1$ cannot be greater than $2$, but we can buy $c_1$ and $c_2$ once each (buying $c_2$ twice is not possible), so $a = [2, 1]$.



#### tags 

#1800 #greedy #implementation #sortings 