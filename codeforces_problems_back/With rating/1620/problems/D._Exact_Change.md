<h1 style='text-align: center;'> D. Exact Change</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day, early in the morning, you decided to buy yourself a bag of chips in the nearby store. The store has chips of $n$ different flavors. A bag of the $i$-th flavor costs $a_i$ burles.

The store may run out of some flavors, so you'll decide which one to buy after arriving there. But there are two major flaws in this plan: 

1. you have only coins of $1$, $2$ and $3$ burles;
2. since it's morning, the store will ask you to pay in exact change, i. e. if you choose the $i$-th flavor, you'll have to pay exactly $a_i$ burles.

Coins are heavy, so you'd like to take the least possible number of coins in total. That's why you are wondering: what is the minimum total number of coins you should take with you, so you can buy a bag of chips of any flavor in exact change?

## Input

The first line contains a single integer $t$ ($1 \le t \le 1000$) — the number of test cases.

The first line of each test case contains the single integer $n$ ($1 \le n \le 100$) — the number of flavors in the store.

The second line of each test case contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \le a_i \le 10^9$) — the cost of one bag of each flavor.

## Output

For each test case, print one integer — the minimum number of coins you need to buy one bag of any flavor you'll choose in exact change.

## Example

## Input


```

4
1
1337
3
10 8 10
5
1 2 3 4 5
3
7 77 777

```
## Output


```

446
4
3
260

```
## Note

In the first test case, you should, for example, take with you $445$ coins of value $3$ and $1$ coin of value $2$. So, $1337 = 445 \cdot 3 + 1 \cdot 2$.

In the second test case, you should, for example, take $2$ coins of value $3$ and $2$ coins of value $2$. So you can pay either exactly $8 = 2 \cdot 3 + 1 \cdot 2$ or $10 = 2 \cdot 3 + 2 \cdot 2$.

In the third test case, it's enough to take $1$ coin of value $3$ and $2$ coins of value $1$.



#### tags 

#2000 #brute_force #constructive_algorithms #greedy 