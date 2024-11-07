<h1 style='text-align: center;'> A. Make A Equal to B</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given two arrays $a$ and $b$ of $n$ elements, each element is either $0$ or $1$.

You can make operations of $2$ kinds. 

* Pick an index $i$ and change $a_i$ to $1-a_i$.
* Rearrange the array $a$ however you want.

Find the minimum number of operations required to make $a$ equal to $b$.

### Input

Each test contains multiple test cases. The first line contains a single integer $t$ ($1 \leq t \leq 400$) — the number of test cases. Description of the test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 100$) — the length of the arrays $a$ and $b$.

The second line of each test case contains $n$ space-separated integers $a_1,a_2,\ldots,a_n$ ($a_i$ is $0$ or $1$), representing the array $a$.

The third line of each test case contains $n$ space-separated integers $b_1,b_2,\ldots,b_n$ ($b_i$ is $0$ or $1$), representing the array $b$.

### Output

For each test case, print the minimum number of operations required to make $a$ equal to $b$.

## Example

### Input


```text
531 0 10 0 141 1 0 00 1 1 121 11 141 0 0 10 1 1 0101
```
### Output

```text

1
2
0
1
1

```
## Note

In the first case, we need only one operation: change $a_1$ to $1-a_i$. Now $a = [0, 0]$ which is equal to $b$.

In the second case, the optimal way is to rearrange $a$ to get the array $[0, 1, 11$. Now $a = [0, 0, 1]$ which is equal to $b$.

In the second case, one of optimal ways would be to first change $a_3$ to $1 - a_3$, then rearrange $a$.

In the third case, no operation is needed.

In the fourth case, the optimal way is to rearrange $a$ to get the array $[0, 1, 1, 0]$.



#### Tags 

#800 #OK #brute_force #greedy #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_825_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
