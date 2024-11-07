<h1 style='text-align: center;'> C. awoo's Favorite Problem</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two strings $s$ and $t$, both of length $n$. Each character in both string is 'a', 'b' or 'c'.

In one move, you can perform one of the following actions: 

* choose an occurrence of "ab" in $s$ and replace it with "ba";
* choose an occurrence of "bc" in $s$ and replace it with "cb".

You are allowed to perform an arbitrary amount of moves (possibly, zero). Can you change string $s$ to make it equal to string $t$?

## Input

The first line contains a single integer $q$ ($1 \le q \le 10^4$) — the number of testcases.

The first line of each testcase contains a single integer $n$ ($1 \le n \le 10^5$) — the length of strings $s$ and $t$.

The second line contains string $s$ of length $n$. Each character is 'a', 'b' or 'c'.

The third line contains string $t$ of length $n$. Each character is 'a', 'b' or 'c'.

The sum of $n$ over all testcases doesn't exceed $10^5$.

## Output

For each testcase, print "YES" if you can change string $s$ to make it equal to string $t$ by performing an arbitrary amount of moves (possibly, zero). Otherwise, print "NO".

## Example

## Input


```

53cabcab1ab6abbabcbbaacb10bcaabababccbbababaac2baab
```
## Output


```

YES
NO
YES
YES
NO

```


#### tags 

#1400 #binary_search #constructive_algorithms #data_structures #greedy #implementation #strings #two_pointers 