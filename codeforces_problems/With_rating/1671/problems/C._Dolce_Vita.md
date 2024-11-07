<h1 style='text-align: center;'> C. Dolce Vita</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Turbulent times are coming, so you decided to buy sugar in advance. There are $n$ shops around that sell sugar: the $i$-th shop sells one pack of sugar for $a_i$ coins, but only one pack to one customer each day. So in order to buy several packs, you need to visit several shops.

Another problem is that prices are increasing each day: during the first day the cost is $a_i$, during the second day cost is $a_i + 1$, during the third day — $a_i + 2$ and so on for each shop $i$.

On the contrary, your everyday budget is only $x$ coins. In other words, each day you go and buy as many packs as possible with total cost not exceeding $x$. 
## Note

 that if you don't spend some amount of coins during a day, you can't use these coins during the next days.

Eventually, the cost for each pack will exceed $x$, and you won't be able to buy even a single pack. So, how many packs will you be able to buy till that moment in total?

### Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases. Next $t$ cases follow.

The first line of each test case contains two integers $n$ and $x$ ($1 \le n \le 2 \cdot 10^5$; $1 \le x \le 10^9$) — the number of shops and your everyday budget.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the initial cost of one pack in each shop.

It's guaranteed that the total sum of $n$ doesn't exceed $2 \cdot 10^5$.

### Output

For each test case, print one integer — the total number of packs you will be able to buy until prices exceed your everyday budget.

## Example

### Input


```text
43 72 1 25 910 20 30 40 501 112 10001 1
```
### Output

```text

11
0
1
1500

```
## Note

In the first test case, 

* Day 1: prices are $[2, 1, 2]$. You can buy all $3$ packs, since $2 + 1 + 2 \le 7$.
* Day 2: prices are $[3, 2, 3]$. You can't buy all $3$ packs, since $3 + 2 + 3 > 7$, so you buy only $2$ packs.
* Day 3: prices are $[4, 3, 4]$. You can buy $2$ packs with prices $4$ and $3$.
* Day 4: prices are $[5, 4, 5]$. You can't buy $2$ packs anymore, so you buy only $1$ pack.
* Day 5: prices are $[6, 5, 6]$. You can buy $1$ pack.
* Day 6: prices are $[7, 6, 7]$. You can buy $1$ pack.
* Day 7: prices are $[8, 7, 8]$. You still can buy $1$ pack of cost $7$.
* Day 8: prices are $[9, 8, 9]$. Prices are too high, so you can't buy anything.

 In total, you bought $3 + 2 + 2 + 1 + 1 + 1 + 1 = 11$ packs.In the second test case, prices are too high even at the first day, so you can't buy anything.

In the third test case, you can buy only one pack at day one.

In the fourth test case, you can buy $2$ packs first $500$ days. At day $501$ prices are $[501, 501]$, so you can buy only $1$ pack the next $500$ days. At day $1001$ prices are $[1001, 1001]$ so can't buy anymore. In total, you bought $500 \cdot 2 + 500 \cdot 1 = 1500$ packs.



#### Tags 

#1200 #NOT OK #binary_search #brute_force #greedy #math 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_127_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
