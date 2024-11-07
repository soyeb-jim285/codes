<h1 style='text-align: center;'> E. The Harmonization of XOR</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array of exactly $n$ numbers $[1,2,3,\ldots,n]$ along with integers $k$ and $x$.

Partition the array in exactly $k$ non-empty disjoint subsequences such that the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all numbers in each subsequence is $x$, and each number is in exactly one subsequence. Notice that there are no constraints on the length of each subsequence.

A sequence $a$ is a subsequence of a sequence $b$ if $a$ can be obtained from $b$ by the deletion of several (possibly, zero or all) elements.

For example, for $n = 15$, $k = 6$, $x = 7$, the following scheme is valid: 

* $[6,10,11]$, $6 \oplus 10 \oplus 11 = 7$,
* $[5,12,14]$, $5 \oplus 12 \oplus 14 = 7$,
* $[3,9,13]$, $3 \oplus 9 \oplus 13 = 7$,
* $[1,2,4]$, $1 \oplus 2 \oplus 4 = 7$,
* $[8,15]$, $8 \oplus 15 = 7$,
* $[7]$, $7 = 7$,

 where $\oplus$ represents the bitwise XOR operation.The following scheme is invalid, since $8$, $15$ do not appear: 

* $[6,10,11]$, $6 \oplus 10 \oplus 11 = 7$,
* $[5,12,14]$, $5 \oplus 12 \oplus 14 = 7$,
* $[3,9,13]$, $3 \oplus 9 \oplus 13 = 7$,
* $[1,2,4]$, $1 \oplus 2 \oplus 4 = 7$,
* $[7]$, $7 = 7$.

The following scheme is invalid, since $3$ appears twice, and $1$, $2$ do not appear: 

* $[6,10,11]$, $6 \oplus 10 \oplus 11 = 7$,
* $[5,12,14]$, $5 \oplus 12 \oplus 14 = 7$,
* $[3,9,13]$, $3 \oplus 9 \oplus 13 = 7$,
* $[3,4]$, $3 \oplus 4 = 7$,
* $[8,15]$, $8 \oplus 15 = 7$,
* $[7]$, $7 = 7$.
## Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases. 

The first and the only line of each test case contains three integers $n$, $k$, $x$ ($1 \le k \le n \le 2 \cdot 10^5$; $1\le x \le 10^9$) — the length of the array, the number of subsequences and the required XOR.

It's guaranteed that the sum of $n$ does not exceed $2 \cdot 10^5$.

## Output

For each test case, if it is possible to partition the sequence, print "YES" in the first line. In the $i$-th of the following $k$ lines first print the length $s_i$ of the $i$-th subsequence, then print $s_i$ integers, representing the elements in the $i$-th subsequence. If there are multiple answers, print any. ## Note

 that you can print a subsequence in any order.

If it is not possible to partition the sequence, print "NO".

## Example

## Input


```

715 6 711 4 55 3 24 1 46 1 711 5 511 6 5
```
## Output


```

YES
3 6 10 11
3 5 12 14
3 3 9 13
3 1 2 4
2 8 15
1 7
YES
2 1 4
2 2 7
2 3 6
5 5 8 9 10 11
NO
YES
4 1 2 3 4
YES
6 1 2 3 4 5 6
NO
NO
```
## Note

In the first test case, we construct the following $6$ subsequences: 

* $[6,10,11]$, $6 \oplus 10 \oplus 11 = 7$,
* $[5,12,14]$, $5 \oplus 12 \oplus 14 = 7$,
* $[3,9,13]$, $3 \oplus 9 \oplus 13 = 7$,
* $[1,2,4]$, $1 \oplus 2 \oplus 4 = 7$,
* $[8,15]$, $8 \oplus 15 = 7$,
* $[7]$, $7 = 7$.

In the second test case, we construct the following $4$ subsequences: 

* $[1,4]$, $1 \oplus 4 = 5$,
* $[2,7]$, $2 \oplus 7 = 5$,
* $[3,6]$, $3 \oplus 6 = 5$,
* $[5,8,9,10,11]$, $5 \oplus 8 \oplus 9 \oplus 10 \oplus 11 = 5$.

The following solution is considered correct in this test case as well: 

* $[1,4]$, $1 \oplus 4 = 5$,
* $[2,7]$, $2 \oplus 7 = 5$,
* $[5]$, $5 = 5$,
* $[3,6,8,9,10,11]$, $3 \oplus 6 \oplus 8 \oplus 9 \oplus 10 \oplus 11 = 5$.


#### tags 

#2100 #bitmasks #constructive_algorithms #greedy #math 