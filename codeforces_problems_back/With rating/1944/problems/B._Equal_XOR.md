<h1 style='text-align: center;'> B. Equal XOR</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ of length $2n$, consisting of each integer from $1$ to $n$ exactly twice.

You are also given an integer $k$ ($1 \leq k \leq \lfloor \frac{n}{2} \rfloor $).

You need to find two arrays $l$ and $r$ each of length $\mathbf{2k}$ such that: 

* $l$ is a subset$^\dagger$ of $[a_1, a_2, \ldots a_n]$
* $r$ is a subset of $[a_{n+1}, a_{n+2}, \ldots a_{2n}]$
* [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of elements of $l$ is equal to the bitwise XOR of elements of $r$; in other words, $l_1 \oplus l_2 \oplus \ldots \oplus l_{2k} = r_1 \oplus r_2 \oplus \ldots \oplus r_{2k}$

It can be proved that at least one pair of $l$ and $r$ always exists. If there are multiple solutions, you may output any one of them.

$^\dagger$ A sequence $x$ is a subset of a sequence $y$ if $x$ can be obtained by deleting several (possibly none or all) elements of $y$ and rearranging the elements in any order. For example, $[3,1,2,1]$, $[1, 2, 3]$, $[1, 1]$ and $[3, 2]$ are subsets of $[1, 1, 2, 3]$ but $[4]$ and $[2, 2]$ are not subsets of $[1, 1, 2, 3]$.

## Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 5000$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains $2$ integers $n$ and $k$ ($2 \le n \le 5 \cdot 10^4$, $1 \leq k \leq \lfloor \frac{n}{2} \rfloor $).

The second line contains $2n$ integers $a_1, a_2, \ldots, a_{2n}$ ($1 \le a_i \le n$). It is guaranteed that every integer from $1$ to $n$ occurs exactly twice in $a$.

It is guaranteed that the sum of $n$ over all test cases does not exceed $5 \cdot 10^4$.

## Output

For each test case, output two lines. 

On the first line of output, output $2k$ integers $l_1, l_2, \ldots, l_{2k}$.

On the second line of output, output $2k$ integers $r_1, r_2, \ldots r_{2k}$.

If there are multiple solutions, you may output any one of them.

## Example

## Input


```

42 11 2 2 16 16 4 2 1 2 3 1 6 3 5 5 44 11 2 3 4 1 2 3 46 25 1 3 3 5 1 2 6 4 6 4 2
```
## Output


```

2 1
2 1
6 4
1 3
1 2
1 2
5 1 3 3
6 4 2 4

```
## Note

In the first test case, we choose $l=[2,1]$ and $r=[2,1]$. $[2, 1]$ is a subset of $[a_1, a_2]$ and $[2, 1]$ is a subset of $[a_3, a_4]$, and $2 \oplus 1 = 2 \oplus 1 = 3$.

In the second test case, $6 \oplus 4 = 1 \oplus 3 = 2$.



#### tags 

#1100 #bitmasks #constructive_algorithms 