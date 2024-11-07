<h1 style='text-align: center;'> F. Money Trees</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Luca is in front of a row of $n$ trees. The $i$-th tree has $a_i$ fruit and height $h_i$.

He wants to choose a contiguous subarray of the array $[h_l, h_{l+1}, \dots, h_r]$ such that for each $i$ ($l \leq i < r$), $h_i$ is divisible$^{\dagger}$ by $h_{i+1}$. He will collect all the fruit from each of the trees in the subarray (that is, he will collect $a_l + a_{l+1} + \dots + a_r$ fruits). However, if he collects more than $k$ fruits in total, he will get caught. 

What is the maximum length of a subarray Luca can choose so he doesn't get caught?

$^{\dagger}$ $x$ is divisible by $y$ if the ratio $\frac{x}{y}$ is an integer.

### Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first of each test case line contains two space-separated integers $n$ and $k$ ($1 \leq n \leq 2 \cdot 10^5$; $1 \leq k \leq 10^9$) — the number of trees and the maximum amount of fruits Luca can collect without getting caught.

The second line of each test case contains $n$ space-separated integers $a_i$ ($1 \leq a_i \leq 10^4$) — the number of fruits in the $i$-th tree.

The third line of each test case contains $n$ space-separated integers $h_i$ ($1 \leq h_i \leq 10^9$) — the height of the $i$-th tree.

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$. 

### Output

For each test case output a single integer, the length of the maximum length contiguous subarray satisfying the conditions, or $0$ if there is no such subarray.

## Example

### Input


```text
55 123 2 4 1 84 4 2 4 14 85 4 1 26 2 3 13 127 9 102 2 41 101117 102 6 3 1 5 10 672 24 24 12 4 4 2
```
### Output

```text

3
2
1
0
3

```
## Note

In the first test case, Luca can select the subarray with $l=1$ and $r=3$.

In the second test case, Luca can select the subarray with $l=3$ and $r=4$.

In the third test case, Luca can select the subarray with $l=2$ and $r=2$.



#### Tags 

#1300 #NOT OK #binary_search #greedy #math #two_pointers 

## Blogs
- [All Contest Problems](../Codeforces_Round_898_(Div._4).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
