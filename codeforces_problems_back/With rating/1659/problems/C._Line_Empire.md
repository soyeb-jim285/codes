<h1 style='text-align: center;'> C. Line Empire</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are an ambitious king who wants to be the Emperor of The Reals. But to do that, you must first become Emperor of The Integers.

Consider a number axis. The capital of your empire is initially at $0$. There are $n$ unconquered kingdoms at positions $0<x_1<x_2<\ldots<x_n$. You want to conquer all other kingdoms.

There are two actions available to you: 

* You can change the location of your capital (let its current position be $c_1$) to any other conquered kingdom (let its position be $c_2$) at a cost of $a\cdot |c_1-c_2|$.
* From the current capital (let its current position be $c_1$) you can conquer an unconquered kingdom (let its position be $c_2$) at a cost of $b\cdot |c_1-c_2|$. You cannot conquer a kingdom if there is an unconquered kingdom between the target and your capital.

## Note

 that you cannot place the capital at a point without a kingdom. In other words, at any point, your capital can only be at $0$ or one of $x_1,x_2,\ldots,x_n$. Also note that conquering a kingdom does not change the position of your capital.

Find the minimum total cost to conquer all kingdoms. Your capital can be anywhere at the end.

## Input

The first line contains a single integer $t$ ($1 \le t \le 1000$)  — the number of test cases. The description of each test case follows.

The first line of each test case contains $3$ integers $n$, $a$, and $b$ ($1 \leq n \leq 2 \cdot 10^5$; $1 \leq a,b \leq 10^5$).

The second line of each test case contains $n$ integers $x_1, x_2, \ldots, x_n$ ($1 \leq x_1 < x_2 < \ldots < x_n \leq 10^8$).

The sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case, output a single integer  — the minimum cost to conquer all kingdoms.

## Example

## Input


```

45 2 73 5 12 13 215 6 31 5 6 21 302 9 310 1511 27182 3141516 18 33 98 874 989 4848 20458 34365 38117 72030
```
## Output


```

173
171
75
3298918744

```
## Note

Here is an optimal sequence of moves for the second test case:

1. Conquer the kingdom at position $1$ with cost $3\cdot(1-0)=3$.
2. Move the capital to the kingdom at position $1$ with cost $6\cdot(1-0)=6$.
3. Conquer the kingdom at position $5$ with cost $3\cdot(5-1)=12$.
4. Move the capital to the kingdom at position $5$ with cost $6\cdot(5-1)=24$.
5. Conquer the kingdom at position $6$ with cost $3\cdot(6-5)=3$.
6. Conquer the kingdom at position $21$ with cost $3\cdot(21-5)=48$.
7. Conquer the kingdom at position $30$ with cost $3\cdot(30-5)=75$.

The total cost is $3+6+12+24+3+48+75=171$. You cannot get a lower cost than this.



#### tags 

#1500 #binary_search #brute_force #dp #greedy #implementation #math 