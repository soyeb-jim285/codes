<h1 style='text-align: center;'> G. Trader Problem</h1>

<h5 style='text-align: center;'>time limit per test: 4.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Monocarp plays a computer game (yet again!). This game has a unique trading mechanics.

To trade with a character, Monocarp has to choose one of the items he possesses and trade it for some item the other character possesses. Each item has an integer price. If Monocarp's chosen item has price $x$, then he can trade it for any item (exactly one item) with price not greater than $x+k$.

Monocarp initially has $n$ items, the price of the $i$-th item he has is $a_i$. The character Monocarp is trading with has $m$ items, the price of the $i$-th item they have is $b_i$. Monocarp can trade with this character as many times as he wants (possibly even zero times), each time exchanging one of his items with one of the other character's items according to the aforementioned constraints. Note that if Monocarp gets some item during an exchange, he can trade it for another item (since now the item belongs to him), and vice versa: if Monocarp trades one of his items for another item, he can get his item back by trading something for it.

You have to answer $q$ queries. Each query consists of one integer, which is the value of $k$, and asks you to calculate the maximum possible total cost of items Monocarp can have after some sequence of trades, assuming that he can trade an item of cost $x$ for an item of cost not greater than $x+k$ during each trade. Note that the queries are independent: the trades do not actually occur, Monocarp only wants to calculate the maximum total cost he can get.

## Input

The first line contains three integers $n$, $m$ and $q$ ($1 \le n, m, q \le 2 \cdot 10^5$).

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the prices of the items Monocarp has.

The third line contains $m$ integers $b_1, b_2, \dots, b_m$ ($1 \le b_i \le 10^9$) — the prices of the items the other character has.

The fourth line contains $q$ integers, where the $i$-th integer is the value of $k$ for the $i$-th query ($0 \le k \le 10^9$).

## Output

For each query, print one integer — the maximum possible total cost of items Monocarp can have after some sequence of trades, given the value of $k$ from the query.

## Example

## Input


```

3 4 5
10 30 15
12 31 14 18
0 1 2 3 4

```
## Output


```

55
56
60
64
64

```


#### tags 

#2200 #data_structures #dsu #greedy #sortings 