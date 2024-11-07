<h1 style='text-align: center;'> B. New Bakery</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bob decided to open a bakery. On the opening day, he baked $n$ buns that he can sell. The usual price of a bun is $a$ coins, but to attract customers, Bob organized the following promotion:

* Bob chooses some integer $k$ ($0 \le k \le \min(n, b)$).
* Bob sells the first $k$ buns at a modified price. In this case, the price of the $i$-th ($1 \le i \le k$) sold bun is $(b - i + 1)$ coins.
* The remaining $(n - k)$ buns are sold at $a$ coins each.

## Note

 that $k$ can be equal to $0$. In this case, Bob will sell all the buns at $a$ coins each.

Help Bob determine the maximum profit he can obtain by selling all $n$ buns.

### Input

Each test consists of multiple test cases. The first line contains a single integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The only line of each test case contains three integers $n$, $a$, and $b$ ($1 \le n, a, b \le 10^9$) — the number of buns, the usual price of a bun, and the price of the first bun to be sold at a modified price.

### Output

For each test case, output a single integer — the maximum profit that Bob can obtain.

## Example

### Input


```text
74 4 55 5 910 10 55 5 111000000000 1000000000 10000000001000000000 1000000000 11000 1 1000
```
### Output

```text

17
35
100
45
1000000000000000000
1000000000000000000
500500

```
## Note

In the first test case, it is optimal for Bob to choose $k = 1$. Then he will sell one bun for $5$ coins, and three buns at the usual price for $4$ coins each. Then the profit will be $5 + 4 + 4 + 4 = 17$ coins.

In the second test case, it is optimal for Bob to choose $k = 5$. Then he will sell all the buns at the modified price and obtain a profit of $9 + 8 + 7 + 6 + 5 = 35$ coins.

In the third test case, it is optimal for Bob to choose $k = 0$. Then he will sell all the buns at the usual price and obtain a profit of $10 \cdot 10 = 100$ coins.



#### Tags 

#800 #NOT OK #binary_search #greedy #math #ternary_search 

## Blogs
- [All Contest Problems](../Codeforces_Round_953_(Div._2).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
