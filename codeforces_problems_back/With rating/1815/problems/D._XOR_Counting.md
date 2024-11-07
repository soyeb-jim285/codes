<h1 style='text-align: center;'> D. XOR Counting</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given two positive integers $n$ and $m$. Find the sum of all possible values of $a_1\bigoplus a_2\bigoplus\ldots\bigoplus a_m$, where $a_1,a_2,\ldots,a_m$ are non-negative integers such that $a_1+a_2+\ldots+a_m=n$.

## Note

 that all possible values $a_1\bigoplus a_2\bigoplus\ldots\bigoplus a_m$ should be counted in the sum exactly once.

As the answer may be too large, output your answer modulo $998244353$.

Here, $\bigoplus$ denotes the [bitwise XOR operation](https://en.wikipedia.org/wiki/Bitwise_operation#XOR).

## Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of test cases follows.

The first and only line of each test case contains two integers $n$ and $m$ ($0\le n\le 10^{18}, 1\le m\le 10^5$) — the sum and the number of integers in the set, respectively.

## Output

For each test case, output the sum of all possible values of $a_1\bigoplus a_2\bigoplus\ldots\bigoplus a_m$ among all non-negative integers $a_1,a_2,\ldots,a_m$ with $a_1+a_2+\ldots+a_m=n$. As the answer may be too large, output your answer modulo $998244353$.

## Example

## Input


```

769 15 20 10420 6912 2673 341000000000000000000 10
```
## Output


```

69
6
0
44310
42
1369
216734648

```
## Note

For the first test case, we must have $a_1=69$, so it's the only possible value of $a_1$, therefore our answer is $69$.

For the second test case, $(a_1,a_2)$ can be $(0,5), (1,4), (2,3), (3,2), (4,1)$ or $(5,0)$, in which $a_1\bigoplus a_2$ are $5,5,1,1,5,5$ respectively. So $a_1\bigoplus a_2$ can be $1$ or $5$, therefore our answer is $1+5=6$.

For the third test case, $a_1,a_2,\ldots,a_{10}$ must be all $0$, so $a_1\bigoplus a_2\bigoplus\ldots\bigoplus a_{10}=0$. Therefore our answer is $0$.



#### tags 

#2600 #bitmasks #combinatorics #dp #math 