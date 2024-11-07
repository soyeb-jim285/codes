<h1 style='text-align: center;'> A. Yet Another Promotion</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The famous store "Second Food" sells groceries only two days a month. And the prices in each of days differ. You wanted to buy $n$ kilos of potatoes for a month. You know that on the first day of the month $1$ kilo of potatoes costs $a$ coins, and on the second day $b$ coins. In "Second Food" you can buy any integer kilograms of potatoes.

Fortunately, "Second Food" has announced a promotion for potatoes, which is valid only on the first day of the month — for each $m$ kilos of potatoes you buy, you get $1$ kilo as a gift! In other words, you can get $m + 1$ kilograms by paying for $m$ kilograms.

Find the minimum number of coins that you have to spend to buy at least $n$ kilos of potatoes.

### Input

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10\,000$). Description of the test cases follows.

The first line of each test case contains two integers $a$ and $b$ $(1 \leq a, b \leq 10^9)$ — the prices of $1$ kilo of potatoes on the first and second days, respectively.

The second line contains two integers $n$ and $m$ $(1 \leq n, m \leq 10^9)$ — the required amount of potatoes to buy and the amount of potatoes to use the promotion.

### Output

For each test case print one integer — the minimum number of coins that you have to pay to buy at least $n$ kilos of potatoes.

## Example

### Input


```text
55 43 15 43 23 43 520 1510 21000000000 9000000001000000000 8
```
### Output

```text

9
10
9
135
888888888900000000

```
## Note

In the first test case, on the first day you buy $1$ kilo and get $1$ more for a promotion. On the second day, you can buy $1$ kilo of potatoes. Thus, you will spend $5+4=9$ coins in total.

In the second test case, on the first day you buy $2$ kilo and get another $1$ more for a promotion. This way you will spend $2 \cdot 5 = 10$ coins.



#### Tags 

#800 #NOT OK #greedy #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_852_(Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
