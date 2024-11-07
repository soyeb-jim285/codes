<h1 style='text-align: center;'> B. AND Sequences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A sequence of $n$ non-negative integers ($n \ge 2$) $a_1, a_2, \dots, a_n$ is called good if for all $i$ from $1$ to $n-1$ the following condition holds true: $$a_1 \: \\& \: a_2 \: \\& \: \dots \: \\& \: a_i = a_{i+1} \: \\& \: a_{i+2} \: \\& \: \dots \: \\& \: a_n,$$ where $\\&$ denotes the [bitwise AND operation](https://en.wikipedia.org/wiki/Bitwise_operation#AND).

You are given an array $a$ of size $n$ ($n \geq 2$). Find the number of permutations $p$ of numbers ranging from $1$ to $n$, for which the sequence $a_{p_1}$, $a_{p_2}$, ... ,$a_{p_n}$ is good. Since this number can be large, output it modulo $10^9+7$.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 10^4$), denoting the number of test cases.

The first line of each test case contains a single integer $n$ ($2 \le n \le 2 \cdot 10^5$) — the size of the array.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$) — the elements of the array.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

## Output

 $t$ lines, where the $i$-th line contains the number of good permutations in the $i$-th test case modulo $10^9 + 7$.

## Example

## Input


```

4
3
1 1 1
5
1 2 3 4 5
5
0 2 0 3 0
4
1 3 5 1

```
## Output


```

6
0
36
4

```
## Note

In the first test case, since all the numbers are equal, whatever permutation we take, the sequence is good. There are a total of $6$ permutations possible with numbers from $1$ to $3$: $[1,2,3]$, $[1,3,2]$, $[2,1,3]$, $[2,3,1]$, $[3,1,2]$, $[3,2,1]$.

In the second test case, it can be proved that no permutation exists for which the sequence is good.

In the third test case, there are a total of $36$ permutations for which the sequence is good. One of them is the permutation $[1,5,4,2,3]$ which results in the sequence $s=[0,0,3,2,0]$. This is a good sequence because 

* $ s_1 = s_2 \: \\& \: s_3 \: \\& \: s_4 \: \\& \: s_5 = 0$,
* $ s_1 \: \\& \: s_2 = s_3 \: \\& \: s_4 \: \\& \: s_5 = 0$,
* $ s_1 \: \\& \: s_2 \: \\& \: s_3 = s_4 \: \\& \: s_5 = 0$,
* $ s_1 \: \\& \: s_2 \: \\& \: s_3 \: \\& \: s_4 = s_5 = 0$.

 



#### tags 

#1400 #bitmasks #combinatorics #constructive_algorithms #math 