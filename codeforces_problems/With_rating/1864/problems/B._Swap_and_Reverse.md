<h1 style='text-align: center;'> B. Swap and Reverse</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a string $s$ of length $n$ consisting of lowercase English letters, and an integer $k$. In one step you can perform any one of the two operations below:

* Pick an index $i$ ($1 \le i \le n - 2$) and swap $s_{i}$ and $s_{i+2}$.
* Pick an index $i$ ($1 \le i \le n-k+1$) and reverse the order of letters formed by the range $[i,i+k-1]$ of the string. Formally, if the string currently is equal to $s_1\ldots s_{i-1}s_is_{i+1}\ldots s_{i+k-2}s_{i+k-1}s_{i+k}\ldots s_{n-1}s_n$, change it to $s_1\ldots s_{i-1}s_{i+k-1}s_{i+k-2}\ldots s_{i+1}s_is_{i+k}\ldots s_{n-1}s_n$.

You can make as many steps as you want (possibly, zero). Your task is to find the lexicographically smallest string you can obtain after some number of steps. 

A string $a$ is lexicographically smaller than a string $b$ of the same length if and only if the following holds: 

* in the first position where $a$ and $b$ differ, the string $a$ has a letter that appears earlier in the alphabet than the corresponding letter in $b$.
### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $k$ ($1 \le k < n \le 10^5$).

The second line of each test case contains the string $s$ of length $n$ consisting of lowercase English letters.

It is guaranteed that the sum of $n$ over all test cases does not exceed $10^5$.

### Output

For each test case, print the lexicographically smallest string after doing some (possibly, zero) steps.

## Example

### Input


```text
54 2nima5 3panda9 2theforces7 3amirfar6 4rounds
```
### Output

```text

aimn
aandp
ceefhorst
aafmirr
dnorsu

```
## Note

In the first test case, we can obtain the string "aimn" using the following operations:

1. Reverse the range $[3,4]$. The string turns into "niam".
2. Swap $s_1$ and $s_3$. The string turns into "ainm".
3. Reverse the range $[3,4]$. The string turns into "aimn".

It can be proven that we cannot obtain any string lexicographically smaller than "aimn". Therefore, "aimn" is the answer.

In the second test case, we can obtain the string "aandp" using the following operations:

1. Swap $s_3$ and $s_5$. The string turns into "paadn".
2. Swap $s_1$ and $s_3$. The string turns into "aapdn".
3. Swap $s_3$ and $s_5$. The string turns into "aandp".

It can be proven that we cannot obtain any string lexicographically smaller than "aandp". Therefore, "aandp" is the answer.



#### Tags 

#1100 #OK #constructive_algorithms #greedy #sortings #strings 

## Blogs
- [All Contest Problems](../Harbour.Space_Scholarship_Contest_2023-2024_(Div._1_+_Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
