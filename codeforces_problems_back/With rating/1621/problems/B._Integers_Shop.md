<h1 style='text-align: center;'> B. Integers Shop</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The integers shop sells $n$ segments. The $i$-th of them contains all integers from $l_i$ to $r_i$ and costs $c_i$ coins.

Tomorrow Vasya will go to this shop and will buy some segments there. He will get all integers that appear in at least one of bought segments. The total cost of the purchase is the sum of costs of all segments in it.

After shopping, Vasya will get some more integers as a gift. He will get integer $x$ as a gift if and only if all of the following conditions are satisfied: 

* Vasya hasn't bought $x$.
* Vasya has bought integer $l$ that is less than $x$.
* Vasya has bought integer $r$ that is greater than $x$.

Vasya can get integer $x$ as a gift only once so he won't have the same integers after receiving a gift.

For example, if Vasya buys segment $[2, 4]$ for $20$ coins and segment $[7, 8]$ for $22$ coins, he spends $42$ coins and receives integers $2, 3, 4, 7, 8$ from these segments. He also gets integers $5$ and $6$ as a gift.

Due to the technical issues only the first $s$ segments (that is, segments $[l_1, r_1], [l_2, r_2], \ldots, [l_s, r_s]$) will be available tomorrow in the shop.

Vasya wants to get (to buy or to get as a gift) as many integers as possible. If he can do this in differents ways, he selects the cheapest of them.

For each $s$ from $1$ to $n$, find how many coins will Vasya spend if only the first $s$ segments will be available.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 1000$) — the number of test cases.

The first line of each test case contains the single integer $n$ ($1 \leq n \leq 10^5$) — the number of segments in the shop.

Each of next $n$ lines contains three integers $l_i$, $r_i$, $c_i$ ($1 \leq l_i \leq r_i \leq 10^9, 1 \leq c_i \leq 10^9$) — the ends of the $i$-th segments and its cost.

It is guaranteed that the total sum of $n$ over all test cases doesn't exceed $2 \cdot 10^5$.

## Output

For each test case output $n$ integers: the $s$-th ($1 \leq s \leq n$) of them should be the number of coins Vasia will spend in the shop if only the first $s$ segments will be available.

## Example

## Input


```

322 4 207 8 2225 11 425 11 4261 4 45 8 97 8 72 10 2521 11 2711 10 1
```
## Output


```

20
42
42
42
4
13
11
256
271
271

```
## Note

In the first test case if $s = 1$ then Vasya can buy only the segment $[2, 4]$ for $20$ coins and get $3$ integers.

The way to get $7$ integers for $42$ coins in case $s = 2$ is described in the statement.

In the second test case note, that there can be the same segments in the shop.



#### tags 

#1500 #data_structures #greedy #implementation 