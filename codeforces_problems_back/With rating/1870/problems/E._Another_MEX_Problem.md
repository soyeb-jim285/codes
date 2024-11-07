<h1 style='text-align: center;'> E. Another MEX Problem</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of integers $a$ of size $n$. You can choose a set of non-overlapping subarrays of the given array (note that some elements may be not included in any subarray, this is allowed). For each selected subarray, calculate the MEX of its elements, and then calculate the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all the obtained MEX values. What is the maximum bitwise XOR that can be obtained?

The MEX (minimum excluded) of an array is the smallest non-negative integer that does not belong to the array. For instance: 

* The MEX of $[2,2,1]$ is $0$, because $0$ does not belong to the array.
* The MEX of $[3,1,0,1]$ is $2$, because $0$ and $1$ belong to the array, but $2$ does not.
* The MEX of $[0,3,1,2]$ is $4$, because $0$, $1$, $2$ and $3$ belong to the array, but $4$ does not.
## Input

The first line contains an integer $t$ ($1 \leq t \leq 5000$) — the number of test cases. This is followed by the description of the test cases.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 5000$) — the size of the array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq n$) — the array $a$.

It is guaranteed that the sum of all $n$ values across all test cases does not exceed $5000$.

## Output

For each test case, output a single number — the maximum possible XOR of the MEX values of the selected subarrays.

## Example

## Input


```

421 0101 2 0 7 1 2 0 2 4 3102 1 0 7 1 2 0 2 4 331 2 1
```
## Output


```

2
6
7
0

```
## Note

In the first test case, the maximum XOR is $2$ if we take the entire array, $\operatorname{MEX}([1, 0]) = 2$.

In the second test case, the maximum XOR is $6$ if we partition the array into segments $[1, 2, 0]$ and $[7, 1, 2, 0, 2, 4, 3]$: 

* $\operatorname{MEX}([1, 2, 0]) = 3$,
* $\operatorname{MEX}([7, 1, 2, 0, 2, 4, 3]) = 5$,

 therefore, the XOR is $5 \oplus 3=6$.In the third test case, the maximum XOR is $7$ if we partition the array into segments $[1, 0]$ and $[7, 1, 2, 0, 2, 4, 3]$: 

* $\operatorname{MEX}([1, 0]) = 2$,
* $\operatorname{MEX}([7, 1, 2, 0, 2, 4, 3]) = 5$,

 therefore, the XOR is $5 \oplus 2 = 7$.

#### tags 

#2300 #bitmasks #brute_force #dp #shortest_paths 