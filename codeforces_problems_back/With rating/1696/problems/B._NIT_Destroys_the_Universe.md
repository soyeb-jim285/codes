<h1 style='text-align: center;'> B. NIT Destroys the Universe</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

For a collection of integers $S$, define $\operatorname{mex}(S)$ as the smallest non-negative integer that does not appear in $S$.

NIT, the cleaver, decides to destroy the universe. He is not so powerful as Thanos, so he can only destroy the universe by snapping his fingers several times.

The universe can be represented as a 1-indexed array $a$ of length $n$. When NIT snaps his fingers, he does the following operation on the array:

* He selects positive integers $l$ and $r$ such that $1\le l\le r\le n$. Let $w=\operatorname{mex}(\{a_l,a_{l+1},\dots,a_r\})$. Then, for all $l\le i\le r$, set $a_i$ to $w$.

We say the universe is destroyed if and only if for all $1\le i\le n$, $a_i=0$ holds.

Find the minimum number of times NIT needs to snap his fingers to destroy the universe. That is, find the minimum number of operations NIT needs to perform to make all elements in the array equal to $0$.

## Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). Description of the test cases follows.

The first line of each test case contains one integer $n$ ($1\le n\le 10^5$).

The second line of each test case contains $n$ integers $a_1$, $a_2$, $\ldots$, $a_n$ ($0\le a_i\le 10^9$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2\cdot 10^5$.

## Output

For each test case, print one integer — the answer to the problem.

## Example

## Input


```

440 0 0 050 1 2 3 470 2 3 0 1 2 011000000000
```
## Output


```

0
1
2
1

```
## Note

In the first test case, we do $0$ operations and all elements in the array are already equal to $0$.

In the second test case, one optimal way is doing the operation with $l=2$, $r=5$.

In the third test case, one optimal way is doing the operation twice, respectively with $l=4$, $r=4$ and $l=2$, $r=6$.

In the fourth test case, one optimal way is doing the operation with $l=1$, $r=1$.



#### tags 

#900 #greedy 