<h1 style='text-align: center;'> C. Different Differences</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

An array $a$ consisting of $k$ integers is strictly increasing if $a_1 < a_2 < \dots < a_k$. For example, the arrays $[1, 3, 5]$, $[1, 2, 3, 4]$, $[3, 5, 6]$ are strictly increasing; the arrays $[2, 2]$, $[3, 7, 5]$, $[7, 4, 3]$, $[1, 2, 2, 3]$ are not.

For a strictly increasing array $a$ of $k$ elements, let's denote the characteristic as the number of different elements in the array $[a_2 - a_1, a_3 - a_2, \dots, a_k - a_{k-1}]$. For example, the characteristic of the array $[1, 3, 4, 7, 8]$ is $3$ since the array $[2, 1, 3, 1]$ contains $3$ different elements: $2$, $1$ and $3$.

You are given two integers $k$ and $n$ ($k \le n$). Construct an increasing array of $k$ integers from $1$ to $n$ with maximum possible characteristic.

### Input

The first line contains one integer $t$ ($1 \le t \le 819$) — the number of test cases.

Each test case consists of one line containing two integers $k$ and $n$ ($2 \le k \le n \le 40$).

### Output

For each test case, print $k$ integers — the elements of the strictly increasing array $a$ with the maximum possible characteristic. If there are multiple answers, print any of them.

## Example

### Input


```text
75 94 123 33 44 44 68 11
```
### Output

```text

1 3 4 7 8
2 4 7 12
1 2 3
1 3 4
1 2 3 4
2 4 5 6
1 2 3 5 6 7 8 11

```


#### Tags 

#1000 #OK #constructive_algorithms #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_839_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
