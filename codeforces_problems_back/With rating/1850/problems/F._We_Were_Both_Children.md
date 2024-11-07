<h1 style='text-align: center;'> F. We Were Both Children</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mihai and Slavic were looking at a group of $n$ frogs, numbered from $1$ to $n$, all initially located at point $0$. Frog $i$ has a hop length of $a_i$. 

Each second, frog $i$ hops $a_i$ units forward. Before any frogs start hopping, Slavic and Mihai can place exactly one trap in a coordinate in order to catch all frogs that will ever pass through the corresponding coordinate.

However, the children can't go far away from their home so they can only place a trap in the first $n$ points (that is, in a point with a coordinate between $1$ and $n$) and the children can't place a trap in point $0$ since they are scared of frogs.

Can you help Slavic and Mihai find out what is the maximum number of frogs they can catch using a trap?

## Input

The first line of the input contains a single integer $t$ ($1 \le t \le 100$) — the number of test cases. The description of test cases follows.

The first line of each test case contains a single integer $n$ ($1 \leq n \leq 2 \cdot 10^5$) — the number of frogs, which equals the distance Slavic and Mihai can travel to place a trap.

The second line of each test case contains $n$ integers $a_1, \ldots, a_n$ ($1 \leq a_i \leq 10^9$) — the lengths of the hops of the corresponding frogs.

It is guaranteed that the sum of $n$ over all test cases does not exceed $2 \cdot 10^5$.

## Output

For each test case output a single integer — the maximum number of frogs Slavic and Mihai can catch using a trap.

## Example

## Input


```

751 2 3 4 532 2 263 1 3 4 9 1091 3 2 4 2 3 7 8 511087 11 6 8 12 4 4 8109 11 9 12 1 7 2 5 8 10
```
## Output


```

3
3
3
5
0
4
4

```
## Note

In the first test case, the frogs will hop as follows: 

* Frog 1: $0 \to 1 \to 2 \to 3 \to \mathbf{\color{red}{4}} \to \cdots$
* Frog 2: $0 \to 2 \to \mathbf{\color{red}{4}} \to 6 \to 8 \to \cdots$
* Frog 3: $0 \to 3 \to 6 \to 9 \to 12 \to \cdots$
* Frog 4: $0 \to \mathbf{\color{red}{4}} \to 8 \to 12 \to 16 \to \cdots$
* Frog 5: $0 \to 5 \to 10 \to 15 \to 20 \to \cdots$

 Therefore, if Slavic and Mihai put a trap at coordinate $4$, they can catch three frogs: frogs 1, 2, and 4. It can be proven that they can't catch any more frogs.In the second test case, Slavic and Mihai can put a trap at coordinate $2$ and catch all three frogs instantly.



#### tags 

#1300 #brute_force #implementation #math #number_theory 