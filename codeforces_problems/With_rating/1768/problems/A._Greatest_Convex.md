<h1 style='text-align: center;'> A. Greatest Convex</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an integer $k$. Find the largest integer $x$, where $1 \le x < k$, such that $x! + (x - 1)!^\dagger$ is a multiple of $^\ddagger$ $k$, or determine that no such $x$ exists.

$^\dagger$ $y!$ denotes the factorial of $y$, which is defined recursively as $y! = y \cdot (y-1)!$ for $y \geq 1$ with the base case of $0! = 1$. For example, $5! = 5 \cdot 4 \cdot 3 \cdot 2 \cdot 1 \cdot 0! = 120$.

$^\ddagger$ If $a$ and $b$ are integers, then $a$ is a multiple of $b$ if there exists an integer $c$ such that $a = b \cdot c$. For example, $10$ is a multiple of $5$ but $9$ is not a multiple of $6$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of test cases follows.

The only line of each test case contains a single integer $k$ ($2 \le k \le 10^9$).

### Output

For each test case output a single integer — the largest possible integer $x$ that satisfies the conditions above. 

If no such $x$ exists, output $-1$.

## Example

### Input


```text
436810
```
### Output

```text

2
5
7
9

```
## Note

In the first test case, $2! + 1! = 2 + 1 = 3$, which is a multiple of $3$.

In the third test case, $7! + 6! = 5040 + 720 = 5760$, which is a multiple of $8$.



#### Tags 

#800 #OK #greedy #math #number_theory 

## Blogs
- [All Contest Problems](../Codeforces_Round_842_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
