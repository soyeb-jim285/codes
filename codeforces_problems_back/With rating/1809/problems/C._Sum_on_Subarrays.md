<h1 style='text-align: center;'> C. Sum on Subarrays</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

For an array $a = [a_1, a_2, \dots, a_n]$, let's denote its subarray $a[l, r]$ as the array $[a_l, a_{l+1}, \dots, a_r]$.

For example, the array $a = [1, -3, 1]$ has $6$ non-empty subarrays:

* $a[1,1] = [1]$;
* $a[1,2] = [1,-3]$;
* $a[1,3] = [1,-3,1]$;
* $a[2,2] = [-3]$;
* $a[2,3] = [-3,1]$;
* $a[3,3] = [1]$.

You are given two integers $n$ and $k$. Construct an array $a$ consisting of $n$ integers such that:

* all elements of $a$ are from $-1000$ to $1000$;
* $a$ has exactly $k$ subarrays with positive sums;
* the rest $\dfrac{(n+1) \cdot n}{2}-k$ subarrays of $a$ have negative sums.
## Input

The first line contains one integer $t$ ($1 \le t \le 5000$) — the number of test cases.

Each test case consists of one line containing two integers $n$ and $k$ ($2 \le n \le 30$; $0 \le k \le \dfrac{(n+1) \cdot n}{2}$).

## Output

For each test case, print $n$ integers — the elements of the array meeting the constraints. It can be shown that the answer always exists. If there are multiple answers, print any of them.

## Example

## Input


```

43 22 02 24 6
```
## Output


```

1 -3 1
-13 -42
-13 42
-3 -4 10 -2

```


#### tags 

#1500 #constructive_algorithms #greedy #math 