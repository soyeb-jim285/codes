<h1 style='text-align: center;'> C. Ticket Hoarding</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

[Maître Gims - Est-ce que tu m'aimes ?](https://youtu.be/6TpyRE_juyA)ඞAs the CEO of a startup company, you want to reward each of your $k$ employees with a ticket to the upcoming concert. The tickets will be on sale for $n$ days, and by some time travelling, you have predicted that the price per ticket at day $i$ will be $a_i$. However, to prevent ticket hoarding, the concert organizers have implemented the following measures:

* A person may purchase no more than $m$ tickets per day.
* If a person purchases $x$ tickets on day $i$, all subsequent days (i.e. from day $i+1$ onwards) will have their prices per ticket increased by $x$.

For example, if $a = [1, 3, 8, 4, 5]$ and you purchase $2$ tickets on day $1$, they will cost $2$ in total, and the prices from day $2$ onwards will become $[5, 10, 6, 7]$. If you then purchase $3$ more tickets on day $2$, they will cost in total an additional $15$, and the prices from day $3$ onwards will become $[13, 9, 10]$.

Find the minimum spending to purchase $k$ tickets.

### Input

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \le t \le 10^4$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains three integers $n$, $m$, and $k$ ($1 \le n \le 3 \cdot 10^5, 1 \le m \le 10^9, 1 \le k \le \min(nm, 10^9)$) — the number of sale days, the maximum amount of ticket purchasable each day, and the number of tickets to be bought at the end.

The second line of each test case contains $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_i \le 10^9$) — the price per ticket for each of the upcoming $n$ days.

It is guaranteed that the sum of $n$ over all test cases does not exceed $3 \cdot 10^5$.

### Output

For each test case, print one integer: the minimum amount of money needed to purchase exactly $k$ tickets.

## Example

### Input


```text
44 2 38 6 4 24 2 88 6 4 25 100 110000 1 100 10 10006 3 95 5 5 5 5 5
```
### Output

```text

10
64
1
72

```
## Note

In the first test case, one optimal way to buy $3$ tickets is as follows: 

* Buy $0$ tickets on the first day. The prices per ticket for the remaining days are $[6, 4, 2]$.
* Buy $0$ tickets on the second day. The prices per ticket for the remaining days are $[4, 2]$.
* Buy $1$ ticket on the third day with cost $4$. The price per ticket for the remaining day is $[3]$.
* Buy $2$ tickets on the fourth day with cost $6$.

In the second test case, there is only one way to buy $8$ tickets: 

* Buy $2$ tickets on the first day with cost $16$. The prices per ticket for the remaining days are $[8, 6, 4]$.
* Buy $2$ tickets on the second day with cost $16$. The prices per ticket for the remaining days are $[8, 6]$.
* Buy $2$ tickets on the third day with cost $16$. The price per ticket for the remaining day is $[8]$.
* Buy $2$ tickets on the fourth day with cost $16$.


#### Tags 

#1400 #OK #greedy #math #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_25.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
