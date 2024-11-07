<h1 style='text-align: center;'> A. Divan and a Store</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Businessman Divan loves chocolate! Today he came to a store to buy some chocolate. Like all businessmen, Divan knows the value of money, so he will not buy too expensive chocolate. At the same time, too cheap chocolate tastes bad, so he will not buy it as well.

The store he came to has $n$ different chocolate bars, and the price of the $i$-th chocolate bar is $a_i$ dollars. Divan considers a chocolate bar too expensive if it costs strictly more than $r$ dollars. Similarly, he considers a bar of chocolate to be too cheap if it costs strictly less than $l$ dollars. Divan will not buy too cheap or too expensive bars.

Divan is not going to spend all his money on chocolate bars, so he will spend at most $k$ dollars on chocolates.

Please determine the maximum number of chocolate bars Divan can buy.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 100$). Description of the test cases follows.

The description of each test case consists of two lines. The first line contains integers $n$, $l$, $r$, $k$ ($1 \le n \le 100$, $1 \le l \le r \le 10^9$, $1 \le k \le 10^9$) — the lowest acceptable price of a chocolate, the highest acceptable price of a chocolate and Divan's total budget, respectively.

The second line contains a sequence $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) integers — the prices of chocolate bars in the store.

### Output

For each test case print a single integer — the maximum number of chocolate bars Divan can buy.

## Example

### Input


```text
8
3 1 100 100
50 100 50
6 3 5 10
1 2 3 4 5 6
6 3 5 21
1 2 3 4 5 6
10 50 69 100
20 30 40 77 1 1 12 4 70 10000
3 50 80 30
20 60 70
10 2 7 100
2 2 2 2 2 7 7 7 7 7
4 1000000000 1000000000 1000000000
1000000000 1000000000 1000000000 1000000000
1 1 1 1
1
```
### Output


```text
2
2
3
0
0
10
1
1
```
## Note

In the first example Divan can buy chocolate bars $1$ and $3$ and spend $100$ dollars on them.

In the second example Divan can buy chocolate bars $3$ and $4$ and spend $7$ dollars on them.

In the third example Divan can buy chocolate bars $3$, $4$, and $5$ for $12$ dollars.

In the fourth example Divan cannot buy any chocolate bar because each of them is either too cheap or too expensive.

In the fifth example Divan cannot buy any chocolate bar because he considers the first bar too cheap, and has no budget for the second or third.

In the sixth example Divan can buy all the chocolate bars in the shop.



#### Tags 

#800 #NOT OK #brute_force #constructive_algorithms #greedy 

## Blogs
- [All Contest Problems](../Codeforces_Round_757_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
