<h1 style='text-align: center;'> A. Halloumi Boxes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Theofanis is busy after his [last contest](https://codeforces.com/contest/1594/problem/A), as now, he has to deliver many halloumis all over the world. He stored them inside $n$ boxes and each of which has some number $a_i$ written on it. 

He wants to sort them in non-decreasing order based on their number, however, his machine works in a strange way. It can only reverse any subarray$^{\dagger}$ of boxes with length at most $k$.

Find if it's possible to sort the boxes using any number of reverses.

$^{\dagger}$ Reversing a subarray means choosing two indices $i$ and $j$ (where $1 \le i \le j \le n$) and changing the array $a_1, a_2, \ldots, a_n$ to $a_1, a_2, \ldots, a_{i-1}, \; a_j, a_{j-1}, \ldots, a_i, \; a_{j+1}, \ldots, a_{n-1}, a_n$. The length of the subarray is then $j - i + 1$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases.

Each test case consists of two lines. 

The first line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 100$) — the number of boxes and the length of the maximum reverse that Theofanis can make. 

The second line contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^{9}$) — the number written on each box.

### Output

For each test case, print YES (case-insensitive), if the array can be sorted in non-decreasing order, or NO (case-insensitive) otherwise.

## Example

### Input


```text
53 21 2 33 19 9 94 46 4 2 14 310 3 830 142 13 1
```
### Output

```text

YES
YES
YES
YES
NO

```
## Note

In the first two test cases, the boxes are already sorted in non-decreasing order.

In the third test case, we can reverse the whole array.

In the fourth test case, we can reverse the first two boxes and the last two boxes.

In the fifth test case, it can be shown that it's impossible to sort the boxes.



#### Tags 

#800 #NOT OK #brute_force #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_912_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
