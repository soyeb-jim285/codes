<h1 style='text-align: center;'> D. Inaccurate Subsequence Search</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Maxim has an array $a$ of $n$ integers and an array $b$ of $m$ integers ($m \le n$).

Maxim considers an array $c$ of length $m$ to be good if the elements of array $c$ can be rearranged in such a way that at least $k$ of them match the elements of array $b$. 

For example, if $b = [1, 2, 3, 4]$ and $k = 3$, then the arrays $[4, 1, 2, 3]$ and $[2, 3, 4, 5]$ are good (they can be reordered as follows: $[1, 2, 3, 4]$ and $[5, 2, 3, 4]$), while the arrays $[3, 4, 5, 6]$ and $[3, 4, 3, 4]$ are not good.

Maxim wants to choose every subsegment of array $a$ of length $m$ as the elements of array $c$. Help Maxim count how many selected arrays will be good.

In other words, find the number of positions $1 \le l \le n - m + 1$ such that the elements $a_l, a_{l+1}, \dots, a_{l + m - 1}$ form a good array.

### Input

The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The first line of each test case contains three integers $n$, $m$, and $k$ ($1 \le k \le m \le n \le 2 \cdot 10^5$) — the number of elements in arrays $a$ and $b$, the required number of matching elements.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^6$) — the elements of array $a$. Elements of the array $a$ are not necessarily unique.

The third line of each test case contains $m$ integers $b_1, b_2, \dots, b_m$ ($1 \le b_i \le 10^6$) — the elements of array $b$. Elements of the array $b$ are not necessarily unique.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$. Similarly, it is guaranteed that the sum of $m$ over all test cases does not exceed $2 \cdot 10^5$.

### Output

For each test case, output the number of good subsegments of array $a$ on a separate line.

## Example

### Input


```text
57 4 24 1 2 3 4 5 61 2 3 47 4 34 1 2 3 4 5 61 2 3 47 4 44 1 2 3 4 5 61 2 3 411 5 39 9 2 2 10 9 7 6 3 6 36 9 7 8 104 1 14 1 5 66
```
### Output

```text

4
3
2
4
1

```
## Note

In the first example, all subsegments are good.

In the second example, good subsegments start at positions $1$, $2$, and $3$.

In the third example, good subsegments start at positions $1$ and $2$.



#### Tags 

#1400 #NOT OK #data_structures #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_938_(Div._3).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
