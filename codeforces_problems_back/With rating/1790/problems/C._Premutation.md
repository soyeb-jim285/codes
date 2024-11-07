<h1 style='text-align: center;'> C. Premutation</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A sequence of $n$ numbers is called permutation if it contains all integers from $1$ to $n$ exactly once. For example, the sequences [$3, 1, 4, 2$], [$1$] and [$2,1$] are permutations, but [$1,2,1$], [$0,1$] and [$1,3,4$] — are not.

Kristina had a permutation $p$ of $n$ elements. She wrote it on the whiteboard $n$ times in such a way that: 

* while writing the permutation at the $i$-th ($1 \le i \le n)$ time she skipped the element $p_i$

 So, she wrote in total $n$ sequences of length $n-1$ each.For example, suppose Kristina had a permutation $p$ = $[4,2,1,3]$ of length $4$. Then she did the following: 

1. Wrote the sequence $[2, 1, 3]$, skipping the element $p_1=4$ from the original permutation.
2. Wrote the sequence $[4, 1, 3]$, skipping the element $p_2=2$ from the original permutation.
3. Wrote the sequence $[4, 2, 3]$, skipping the element $p_3=1$ from the original permutation.
4. Wrote the sequence $[4, 2, 1]$, skipping the element $p_4=3$ from the original permutation.

You know all $n$ of sequences that have been written on the whiteboard, but you do not know the order in which they were written. They are given in arbitrary order. Reconstruct the original permutation from them.

For example, if you know the sequences $[4, 2, 1]$, $[4, 2, 3]$, $[2, 1, 3]$, $[4, 1, 3]$, then the original permutation will be $p$ = $[4, 2, 1, 3]$.

## Input

The first line of input data contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The description of the test cases follows.

The first line of each test case contains one integer $n$ ($3 \le n \le 100$).

This is followed by $n$ lines, each containing exactly $n-1$ integers and describing one of the sequences written out on the whiteboard.

It is guaranteed that all sequences could be obtained from some permutation $p$, and that the sum $n^2$ over all input sets does not exceed $2 \cdot 10^5$.

## Output

For each test case, output on a separate line a permutation $p$ such that the given $n$ sequences could be obtained from it.

It is guaranteed that the answer exists and it is the only one. In other words, for each test case the required permutation is sure to exist.

## Example

## Input


```

544 2 14 2 32 1 34 1 332 31 31 254 2 1 32 1 3 54 2 3 54 1 3 54 2 1 542 3 41 3 41 2 31 2 432 11 32 3
```
## Output


```

4 2 1 3 
1 2 3 
4 2 1 3 5 
1 2 3 4 
2 1 3 

```
## Note

The first test case is described in the problem statement.

In the second test case, the sequences are written in the correct order.



#### tags 

#1000 #brute_force #implementation #math 