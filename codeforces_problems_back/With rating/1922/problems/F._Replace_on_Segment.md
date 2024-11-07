<h1 style='text-align: center;'> F. Replace on Segment</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \dots, a_n$, where each element is an integer from $1$ to $x$.

You can perform the following operation with it any number of times:

* choose three integers $l$, $r$ and $k$ such that $1 \le l \le r \le n$, $1 \le k \le x$ and each element $a_i$ such that $l \le i \le r$ is different from $k$. Then, for each $i \in [l, r]$, replace $a_i$ with $k$.

In other words, you choose a subsegment of the array and an integer from $1$ to $x$ which does not appear in that subsegment, and replace every element in the subsegment with that chosen integer.

Your goal is to make all elements in the array equal. What is the minimum number of operations that you have to perform?

## Input

The first line contains one integer $t$ ($1 \le t \le 100$) — the number of test cases.

Each test case consists of two lines:

* the first line contains two integers $n$ and $x$ ($1 \le x \le n \le 100$);
* the second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le x$).

Additional constraint on the input: the sum of $n$ over all test cases does not exceed $500$.

## Output

For each test case, print one integer — the minimum number of operations you have to perform.

## Example

## Input


```

33 21 2 16 31 2 3 1 2 312 33 1 3 1 2 1 1 2 3 1 1 3
```
## Output


```

1
2
2

```


#### tags 

#2500 #dp #graph_matchings 