<h1 style='text-align: center;'> A. Coins</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In Berland, there are two types of coins, having denominations of $2$ and $k$ burles.

Your task is to determine whether it is possible to represent $n$ burles in coins, i. e. whether there exist non-negative integers $x$ and $y$ such that $2 \cdot x + k \cdot y = n$.

### Input

The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

The only line of each test case contains two integers $n$ and $k$ ($1 \le k \le n \le 10^{18}$; $k \ne 2$).

### Output

For each test case, print YES if it is possible to represent $n$ burles in coins; otherwise, print NO. You may print each letter in any case (YES, yes, Yes will all be recognized as positive answer, NO, no and nO will all be recognized as negative answer).

## Example

### Input


```text
45 36 17 48 8
```
### Output

```text

YES
YES
NO
YES

```
## Note

In the first test case, you can take one coin with denomination $2$ and one coin with denomination $k = 3$.

In the second test case, you can take three coins with denomination $2$. Alternatively, you can take six coins with denomination $k = 1$.

In the third test case, there is no way to represent $7$ burles.

In the fourth test case, you can take one coin with denomination $k = 8$.



#### Tags 

#800 #OK #implementation #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_146_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
