<h1 style='text-align: center;'> A. United We Stand</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Given an array $a$ of length $n$, containing integers. And there are two initially empty arrays $b$ and $c$. You need to add each element of array $a$ to exactly one of the arrays $b$ or $c$, in order to satisfy the following conditions:

* Both arrays $b$ and $c$ are non-empty. More formally, let $l_b$ be the length of array $b$, and $l_c$ be the length of array $c$. Then $l_b, l_c \ge 1$.
* For any two indices $i$ and $j$ ($1 \le i \le l_b, 1 \le j \le l_c$), $c_j$ is not a divisor of $b_i$.

### Output

 the arrays $b$ and $c$ that can be obtained, or output $-1$ if they do not exist.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 500$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains a single integer $n$ ($2 \le n \le 100$) — the length of array $a$.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the elements of array $a$.

### Output

For each test case, output a single integer $-1$ if a solution does not exist.

Otherwise, in the first line, output two integers $l_b$ and $l_c$ — the lengths of arrays $b$ and $c$ respectively.

In the second line, output $l_b$ integers $b_1, b_2, \ldots, b_{l_b}$ — the elements of array $b$.

In the third line, output $l_c$ integers $c_1, c_2, \ldots, c_{l_c}$ — the elements of array $c$.

If there are multiple solutions, output any of them. You can output the elements of the arrays in any order.

## Example

### Input


```text
532 2 251 2 3 4 531 3 571 7 7 2 9 1 454 8 12 12 4
```
### Output

```text

-1
3 2
1 3 5 
2 4 
1 2
1 
3 5 
2 5
1 1 
2 4 7 7 9 
3 2
4 8 4 
12 12 

```
## Note

In the first test case, a solution does not exist.

In the second test case, we can obtain $b = [1, 3, 5]$ and $c = [2, 4]$. Then elements $2$ and $4$ do not divide elements $1, 3$ and $5$.

In the fifth test case, we can obtain $b = [4, 8, 4]$ and $c = [12, 12]$.



#### Tags 

#800 #OK #constructive_algorithms #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_892_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial #1 (en)](../blogs/Tutorial_1_(en).md)
