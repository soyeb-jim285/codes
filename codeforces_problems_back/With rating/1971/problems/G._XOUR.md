<h1 style='text-align: center;'> G. XOUR</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ nonnegative integers. 

You can swap the elements at positions $i$ and $j$ if $a_i~\mathsf{XOR}~a_j < 4$, where $\mathsf{XOR}$ is the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

Find the lexicographically smallest array that can be made with any number of swaps.

An array $x$ is lexicographically smaller than an array $y$ if in the first position where $x$ and $y$ differ, $x_i < y_i$.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2\cdot10^5$) — the length of the array.

The second line of each test case contains $n$ integers $a_i$ ($0 \leq a_i \leq 10^9$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output $n$ integers — the lexicographically smallest array that can be made with any number of swaps.

## Example

## Input


```

441 0 3 252 7 1 5 681 2 1 2 1 2 1 2416 4 1 64
```
## Output


```

0 1 2 3 
1 5 2 6 7 
1 1 1 1 2 2 2 2 
16 4 1 64 

```
## Note

For the first test case, you can swap any two elements, so we can produce the sorted array.

For the second test case, you can swap $2$ and $1$ (their $\mathsf{XOR}$ is $3$), $7$ and $5$ (their $\mathsf{XOR}$ is $2$), and $7$ and $6$ (their $\mathsf{XOR}$ is $1$) to get the lexicographically smallest array.



#### tags 

#1700 #data_structures #dsu #sortings 