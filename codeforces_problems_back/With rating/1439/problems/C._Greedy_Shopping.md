<h1 style='text-align: center;'> C. Greedy Shopping</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given an array $a_1, a_2, \ldots, a_n$ of integers. This array is non-increasing.

Let's consider a line with $n$ shops. The shops are numbered with integers from $1$ to $n$ from left to right. The cost of a meal in the $i$-th shop is equal to $a_i$.

You should process $q$ queries of two types:

* 1 x y: for each shop $1 \leq i \leq x$ set $a_{i} = max(a_{i}, y)$.
* 2 x y: let's consider a hungry man with $y$ money. He visits the shops from $x$-th shop to $n$-th and if he can buy a meal in the current shop he buys one item of it. Find how many meals he will purchase. The man can buy a meal in the shop $i$ if he has at least $a_i$ money, and after it his money decreases by $a_i$.
## Input

The first line contains two integers $n$, $q$ ($1 \leq n, q \leq 2 \cdot 10^5$).

The second line contains $n$ integers $a_{1},a_{2}, \ldots, a_{n}$ $(1 \leq a_{i} \leq 10^9)$ — the costs of the meals. It is guaranteed, that $a_1 \geq a_2 \geq \ldots \geq a_n$.

Each of the next $q$ lines contains three integers $t$, $x$, $y$ ($1 \leq t \leq 2$, $1\leq x \leq n$, $1 \leq y \leq 10^9$), each describing the next query.

It is guaranteed that there exists at least one query of type $2$.

## Output

For each query of type $2$ output the answer on the new line.

## Example

## Input


```

10 6
10 10 10 6 6 5 5 5 3 1
2 3 50
2 4 10
1 3 10
2 2 36
1 4 7
2 2 17

```
## Output


```

8
3
6
2

```
## Note

In the first query a hungry man will buy meals in all shops from $3$ to $10$.

In the second query a hungry man will buy meals in shops $4$, $9$, and $10$.

After the third query the array $a_1, a_2, \ldots, a_n$ of costs won't change and will be $\{10, 10, 10, 6, 6, 5, 5, 5, 3, 1\}$.

In the fourth query a hungry man will buy meals in shops $2$, $3$, $4$, $5$, $9$, and $10$.

After the fifth query the array $a$ of costs will be $\{10, 10, 10, 7, 6, 5, 5, 5, 3, 1\}$.

In the sixth query a hungry man will buy meals in shops $2$ and $4$.



#### tags 

#2600 #binary_search #data_structures #divide_and_conquer #greedy #implementation 