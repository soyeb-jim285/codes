<h1 style='text-align: center;'> B. Cobb</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given $n$ integers $a_1, a_2, \ldots, a_n$ and an integer $k$. Find the maximum value of $i \cdot j - k \cdot (a_i | a_j)$ over all pairs $(i, j)$ of integers with $1 \le i < j \le n$. Here, $|$ is the [bitwise OR operator](https://en.wikipedia.org/wiki/Bitwise_operation#OR).

### Input

The first line contains a single integer $t$ ($1 \le t \le 10\,000$)  — the number of test cases.

The first line of each test case contains two integers $n$ ($2 \le n \le 10^5$) and $k$ ($1 \le k \le \min(n, 100)$).

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le n$).

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $3 \cdot 10^5$.

### Output

For each test case, print a single integer  — the maximum possible value of $i \cdot j - k \cdot (a_i | a_j)$.

## Example

### Input


```text
4
3 3
1 1 3
2 2
1 2
4 3
0 1 2 3
6 6
3 2 0 0 5 6
```
### Output


```text
-1
-4
3
12
```
## Note

Let $f(i, j) = i \cdot j - k \cdot (a_i | a_j)$.

In the first test case, 

* $f(1, 2) = 1 \cdot 2 - k \cdot (a_1 | a_2) = 2 - 3 \cdot (1 | 1) = -1$.
* $f(1, 3) = 1 \cdot 3 - k \cdot (a_1 | a_3) = 3 - 3 \cdot (1 | 3) = -6$.
* $f(2, 3) = 2 \cdot 3 - k \cdot (a_2 | a_3) = 6 - 3 \cdot (1 | 3) = -3$.

So the maximum is $f(1, 2) = -1$.

In the fourth test case, the maximum is $f(3, 4) = 12$.



#### Tags 

#1700 #NOT OK #bitmasks #brute_force #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_735_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
