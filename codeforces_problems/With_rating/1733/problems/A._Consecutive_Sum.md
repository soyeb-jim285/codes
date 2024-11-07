<h1 style='text-align: center;'> A. Consecutive Sum</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ with $n$ integers. You can perform the following operation at most $k$ times:

* Choose two indices $i$ and $j$, in which $i \,\bmod\, k = j \,\bmod\, k$ ($1 \le i < j \le n$).
* Swap $a_i$ and $a_j$.

After performing all operations, you have to select $k$ consecutive elements, and the sum of the $k$ elements becomes your score. Find the maximum score you can get.

Here $x \bmod y$ denotes the remainder from dividing $x$ by $y$.

### Input

The first line contains one integer $t$ ($1 \le t \le 600$) — the number of test cases.

Each test case consists of two lines. 

The first line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 100$) — the length of the array and the number in the statement above.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \le a_i \le 10^9$)  — the array itself.

### Output

For each test case, print the maximum score you can get, one per line.

## Example

### Input


```text
53 25 6 01 175 37 0 4 0 44 22 7 3 43 31000000000 1000000000 999999997
```
### Output

```text

11
7
15
10
2999999997

```
## Note

In the first test case, we can get a score of $11$ if we select $a_1, a_2$ without performing any operations.

In the third test case, we can get a score of $15$ if we first swap $a_1$ with $a_4$ and then select $a_3, a_4, a_5$. 



#### Tags 

#800 #OK #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_821_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
