<h1 style='text-align: center;'> D. Mathematical Problem</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The mathematicians of the 31st lyceum were given the following task:

You are given an odd number $n$, and you need to find $n$ different numbers that are squares of integers. But it's not that simple. Each number should have a length of $n$ (and should not have leading zeros), and the multiset of digits of all the numbers should be the same. For example, for $\mathtt{234}$ and $\mathtt{432}$, and $\mathtt{11223}$ and $\mathtt{32211}$, the multisets of digits are the same, but for $\mathtt{123}$ and $\mathtt{112233}$, they are not.

The mathematicians couldn't solve this problem. Can you?

## Input

The first line contains an integer $t$ ($1 \leq t \leq 100$) — the number of test cases.

The following $t$ lines contain one odd integer $n$ ($1 \leq n \leq 99$) — the number of numbers to be found and their length.

It is guaranteed that the solution exists within the given constraints.

It is guaranteed that the sum of $n^2$ does not exceed $10^5$.

The numbers can be output in any order.

## Output

For each test case, you need to output $n$ numbers of length $n$ — the answer to the problem.

If there are several answers, print any of them.

## Example

## Input


```

3135
```
## Output


```

1
169
196
961
16384
31684
36481
38416
43681

```
## Note

Below are the squares of the numbers that are the answers for the second test case:

$\mathtt{169}$ = $\mathtt{13}^2$

$\mathtt{196}$ = $\mathtt{14}^2$

$\mathtt{961}$ = $\mathtt{31}^2$

Below are the squares of the numbers that are the answers for the third test case:

$\mathtt{16384}$ = $\mathtt{128}^2$

$\mathtt{31684}$ = $\mathtt{178}^2$

$\mathtt{36481}$ = $\mathtt{191}^2$

$\mathtt{38416}$ = $\mathtt{196}^2$

$\mathtt{43681}$ = $\mathtt{209}^2$



#### tags 

#1700 #brute_force #constructive_algorithms #geometry #math 