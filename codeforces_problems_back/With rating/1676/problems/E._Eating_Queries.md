<h1 style='text-align: center;'> E. Eating Queries</h1>

<h5 style='text-align: center;'>time limit per test: 3.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Timur has $n$ candies. The $i$-th candy has a quantity of sugar equal to $a_i$. So, by eating the $i$-th candy, Timur consumes a quantity of sugar equal to $a_i$.

Timur will ask you $q$ queries regarding his candies. For the $j$-th query you have to answer what is the minimum number of candies he needs to eat in order to reach a quantity of sugar greater than or equal to $x_j$ or print -1 if it's not possible to obtain such a quantity. In other words, you should print the minimum possible $k$ such that after eating $k$ candies, Timur consumes a quantity of sugar of at least $x_j$ or say that no possible $k$ exists.

## Note

 that he can't eat the same candy twice and queries are independent of each other (Timur can use the same candy in different queries).

## Input

The first line of input contains a single integer $t$ ($1 \leq t \leq 1000$)  — the number of test cases. The description of test cases follows.

The first line contains $2$ integers $n$ and $q$ ($1 \leq n, q \leq 1.5\cdot10^5$) — the number of candies Timur has and the number of queries you have to print an answer for respectively.

The second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($1 \leq a_i \leq 10^4$) — the quantity of sugar in each of the candies respectively.

Then $q$ lines follow. 

Each of the next $q$ lines contains a single integer $x_j$ ($1 \leq x_j \leq 2 \cdot 10^9$) – the quantity Timur wants to reach for the given query.

It is guaranteed that the sum of $n$ and the sum of $q$ over all test cases do not exceed $1.5 \cdot 10^5$.

## Output

For each test case output $q$ lines. For the $j$-th line output the number of candies Timur needs to eat in order to reach a quantity of sugar greater than or equal to $x_j$ or print -1 if it's not possible to obtain such a quantity.

## Example

## Input


```

38 74 3 3 1 1 4 5 911050141522304 11 2 3 431 2546
```
## Output


```

1
2
-1
2
3
4
8
1
1
-1

```
## Note

For the first test case:

For the first query, Timur can eat any candy, and he will reach the desired quantity.

For the second query, Timur can reach a quantity of at least $10$ by eating the $7$-th and the $8$-th candies, thus consuming a quantity of sugar equal to $14$.

For the third query, there is no possible answer.

For the fourth query, Timur can reach a quantity of at least $14$ by eating the $7$-th and the $8$-th candies, thus consuming a quantity of sugar equal to $14$.

For the second test case:

For the only query of the second test case, we can choose the third candy from which Timur receives exactly $3$ sugar. It's also possible to obtain the same answer by choosing the fourth candy.



#### tags 

#1100 #binary_search #greedy #sortings 