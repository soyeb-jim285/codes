<h1 style='text-align: center;'> D. Flipper</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a permutation $p$ of length $n$.

A permutation is an array consisting of $n$ distinct integers from $1$ to $n$ in any order. For example, $\{2,3,1,5,4\}$ is a permutation, while $\{1,2,2\}$ is not (since $2$ appears twice), and $\{1,3,4\}$ is also not a permutation (as $n=3$, but the array contains $4$).

To the permutation $p$, you need to apply the following operation exactly once:

* First you choose a segment $[l, r]$ ($1 \le l \le r \le n$, a segment is a continuous sequence of numbers $\{p_l, p_{l+1}, \ldots, p_{r-1}, p_r\}$) and reverse it. Reversing a segment means swapping pairs of numbers $(p_l, p_r)$, $(p_{l+1}, p_{r-1})$, ..., $(p_{l + i}, p_{r - i})$ (where $l + i \le r - i$).
* Then you swap the prefix and suffix: $[r+1, n]$ and $[1, l - 1]$ (note that these segments may be empty).

For example, given $n = 5, p = \{2, \color{blue}{3}, \color{blue}{1}, 5, 4\}$, if you choose the segment $[l = 2, r = 3]$, after reversing the segment $p = \{\color{green}{2}, \color{blue}{1}, \color{blue}{3}, \color{green}{5}, \color{green}{4}\}$, then you swap the segments $[4, 5]$ and $[1, 1]$. Thus, $p = \{\color{green}{5}, \color{green}{4}, 1, 3, \color{green}{2}\}$. It can be shown that this is the maximum possible result for the given permutation.

You need to output the lexicographically maximum permutation that can be obtained by applying the operation described exactly once.

A permutation $a$ is lexicographically greater than permutation $b$ if there exists an $i$ ($1 \le i \le n$) such that $a_j = b_j$ for $1 \le j < i$ and $a_i > b_i$.

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

Then the descriptions of the test cases follow.

The first line of each test case contains a single integer $n$ ($1 \le n \le 2000$) — the size of the permutation.

The second line of each test case contains $n$ integers: $p_1, p_2, \ldots, p_n$ ($1 \le p_i \le n$) — the permutation $p$ itself.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2000$.

## Output

For each test case, output in a separate line the lexicographically maximum permutation of length $n$ that can be obtained from $p$ by applying the operation described in the problem exactly once.

## Example

## Input


```

952 3 1 5 494 1 6 7 2 8 5 3 944 3 2 122 163 2 4 1 5 673 2 1 5 7 6 41010 2 5 6 1 9 3 8 4 744 2 1 311
```
## Output


```

5 4 1 3 2 
9 4 1 6 7 2 8 5 3 
3 2 1 4 
1 2 
6 5 3 2 4 1 
7 6 4 5 3 2 1 
9 3 8 4 7 1 10 2 5 6 
3 4 2 1 
1 

```
## Note

The first example is explained in the problem statement.

In the second example, the segment $[l = 9, r = 9]$ should be chosen.

In the third example, the segment $[l = 1, r = 1]$ should be chosen.

In the fourth example, the segment $[l = 1, r = 2]$ should be chosen.

In the fifth example, the segment $[l = 5, r = 6]$ should be chosen.

In the sixth example, the segment $[l = 4, r = 4]$ should be chosen.

In the seventh example, the segment $[l = 5, r = 5]$ should be chosen.



#### tags 

#1400 #brute_force #constructive_algorithms #greedy 