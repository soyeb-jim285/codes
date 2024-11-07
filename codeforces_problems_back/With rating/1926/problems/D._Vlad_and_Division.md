<h1 style='text-align: center;'> D. Vlad and Division</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vladislav has $n$ non-negative integers, and he wants to divide all of them into several groups so that in any group, any pair of numbers does not have matching bit values among bits from $1$-st to $31$-st bit (i.e., considering the $31$ least significant bits of the binary representation).

For an integer $k$, let $k_2(i)$ denote the $i$-th bit in its binary representation (from right to left, indexing from 1). For example, if $k=43$, since $43=101011_2$, then $43_2(1)=1$, $43_2(2)=1$, $43_2(3)=0$, $43_2(4)=1$, $43_2(5)=0$, $43_2(6)=1$, $43_2(7)=0$, $43_2(8)=0, \dots, 43_2(31)=0$.

Formally, for any two numbers $x$ and $y$ in the same group, the condition $x_2(i) \neq y_2(i)$ must hold for all $1 \leq i < 32$.

What is the minimum number of groups Vlad needs to achieve his goal? Each number must fall into exactly one group.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$) — the number of test cases.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the total number of integers.

The second line of each test case contains $n$ given integers $a_1, \ldots, a_n$ ($0 \leq a_j < 2^{31}$).

The sum of $n$ over all test cases in a test does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer  — the minimum number of groups required to satisfy the condition.

## Example

## Input


```

941 4 3 420 21474836475476319172 261956880 2136179468 1671164475 188552676731335890506 811593141 11282233624688873446 627404104 1520079543 1458610201461545621 2085938026 1269342732 143025857540 0 2147483647 214748364730 0 214748364781858058912 289424735 1858058912 2024818580 1858058912 289424735 122665067 289424735
```
## Output


```

4
1
3
2
2
3
2
2
4

```
## Note

In the first test case, any two numbers have the same last $31$ bits, so we need to place each number in its own group.

In the second test case, $a_1=0000000000000000000000000000000_2$, $a_2=1111111111111111111111111111111_2$ so they can be placed in the same group because $a_1(i) \ne a_2(i)$ for each $i$ between $1$ and $31$, inclusive.



#### tags 

#1300 #bitmasks #greedy 