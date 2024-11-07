<h1 style='text-align: center;'> C. Gorilla and Permutation</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gorilla and Noobish_Monk found three numbers $n$, $m$, and $k$ ($m < k$). They decided to construct a permutation$^{\dagger}$ of length $n$.

For the permutation, Noobish_Monk came up with the following function: $g(i)$ is the sum of all the numbers in the permutation on a prefix of length $i$ that are not greater than $m$. Similarly, Gorilla came up with the function $f$, where $f(i)$ is the sum of all the numbers in the permutation on a prefix of length $i$ that are not less than $k$. A prefix of length $i$ is a subarray consisting of the first $i$ elements of the original array.

For example, if $n = 5$, $m = 2$, $k = 5$, and the permutation is $[5, 3, 4, 1, 2]$, then:

* $f(1) = 5$, because $5 \ge 5$; $g(1) = 0$, because $5 > 2$;
* $f(2) = 5$, because $3 < 5$; $g(2) = 0$, because $3 > 2$;
* $f(3) = 5$, because $4 < 5$; $g(3) = 0$, because $4 > 2$;
* $f(4) = 5$, because $1 < 5$; $g(4) = 1$, because $1 \le 2$;
* $f(5) = 5$, because $2 < 5$; $g(5) = 1 + 2 = 3$, because $2 \le 2$.

Help them find a permutation for which the value of $\left(\sum_{i=1}^n f(i) - \sum_{i=1}^n g(i)\right)$ is maximized.

$^{\dagger}$A permutation of length $n$ is an array consisting of $n$ distinct integers from $1$ to $n$ in any order. For example, $[2,3,1,5,4]$ is a permutation, but $[1,2,2]$ is not a permutation (as $2$ appears twice in the array) and $[1,3,4]$ is also not a permutation (as $n=3$, but $4$ appears in the array).

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$)  — the number of test cases.

The only line of each case contains three integers $n$, $m$, $k$ ($2\le n \le 10^5$; $1 \le m < k \le n$) — the size of the permutation to be constructed and two integers.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output the permutation  — a set of numbers that satisfies the conditions of the problem. If there are multiple solutions, output any of them.

## Example

### Input


```text
35 2 53 1 310 3 8
```
### Output

```text

5 3 4 1 2
3 2 1
10 9 8 4 7 5 6 1 2 3
```
## Note

In the first example, $\left(\sum_{i=1}^n f(i) - \sum_{i=1}^n g(i)\right) = 5 \cdot 5 - (0 \cdot 3 + 1 + 3) = 25 - 4 = 21$



#### Tags 

#900 #OK #constructive_algorithms #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_957_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial #1](../blogs/Tutorial_1.md)
- [Shayan's Video Tutorial (en)](../blogs/Shayan's_Video_Tutorial_(en).md)
