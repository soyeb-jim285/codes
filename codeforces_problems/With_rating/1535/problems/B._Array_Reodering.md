<h1 style='text-align: center;'> B. Array Reodering</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a$ consisting of $n$ integers.

Let's call a pair of indices $i$, $j$ good if $1 \le i < j \le n$ and $\gcd(a_i, 2a_j) > 1$ (where $\gcd(x, y)$ is the greatest common divisor of $x$ and $y$).

Find the maximum number of good index pairs if you can reorder the array $a$ in an arbitrary way.

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first line of the test case contains a single integer $n$ ($2 \le n \le 2000$) — the number of elements in the array.

The second line of the test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^5$).

It is guaranteed that the sum of $n$ over all test cases does not exceed $2000$.

### Output

For each test case, output a single integer — the maximum number of good index pairs if you can reorder the array $a$ in an arbitrary way.

## Example

### Input


```text
3
4
3 6 5 3
2
1 7
5
1 4 2 4 1
```
### Output


```text
4
0
9
```
## Note

In the first example, the array elements can be rearranged as follows: $[6, 3, 5, 3]$.

In the third example, the array elements can be rearranged as follows: $[4, 4, 2, 1, 1]$.



#### Tags 

#900 #NOT OK #brute_force #greedy #math #number_theory #sortings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_110_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
