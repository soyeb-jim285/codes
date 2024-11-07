<h1 style='text-align: center;'> B. Promo</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The store sells $n$ items, the price of the $i$-th item is $p_i$. The store's management is going to hold a promotion: if a customer purchases at least $x$ items, $y$ cheapest of them are free.

The management has not yet decided on the exact values of $x$ and $y$. Therefore, they ask you to process $q$ queries: for the given values of $x$ and $y$, determine the maximum total value of items received for free, if a customer makes one purchase.

## Note

 that all queries are independent; they don't affect the store's stock.

### Input

The first line contains two integers $n$ and $q$ ($1 \le n, q \le 2 \cdot 10^5$) — the number of items in the store and the number of queries, respectively.

The second line contains $n$ integers $p_1, p_2, \dots, p_n$ ($1 \le p_i \le 10^6$), where $p_i$ — the price of the $i$-th item.

The following $q$ lines contain two integers $x_i$ and $y_i$ each ($1 \le y_i \le x_i \le n$) — the values of the parameters $x$ and $y$ in the $i$-th query.

### Output

For each query, print a single integer — the maximum total value of items received for free for one purchase.

## Example

### Input


```text
5 3
5 3 1 5 2
3 2
1 1
5 3
```
### Output


```text
8
5
6
```
## Note

In the first query, a customer can buy three items worth $5, 3, 5$, the two cheapest of them are $3 + 5 = 8$.

In the second query, a customer can buy two items worth $5$ and $5$, the cheapest of them is $5$.

In the third query, a customer has to buy all the items to receive the three cheapest of them for free; their total price is $1 + 2 + 3 = 6$.



#### Tags 

#900 #OK #greedy #sortings 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_130_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
