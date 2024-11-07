<h1 style='text-align: center;'> C. Closest Cities</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There are $n$ cities located on the number line, the $i$-th city is in the point $a_i$. The coordinates of the cities are given in ascending order, so $a_1 < a_2 < \dots < a_n$.

The distance between two cities $x$ and $y$ is equal to $|a_x - a_y|$.

For each city $i$, let's define the closest city $j$ as the city such that the distance between $i$ and $j$ is not greater than the distance between $i$ and each other city $k$. For example, if the cities are located in points $[0, 8, 12, 15, 20]$, then:

* the closest city to the city $1$ is the city $2$;
* the closest city to the city $2$ is the city $3$;
* the closest city to the city $3$ is the city $4$;
* the closest city to the city $4$ is the city $3$;
* the closest city to the city $5$ is the city $4$.

The cities are located in such a way that for every city, the closest city is unique. For example, it is impossible for the cities to be situated in points $[1, 2, 3]$, since this would mean that the city $2$ has two closest cities ($1$ and $3$, both having distance $1$).

You can travel between cities. Suppose you are currently in the city $x$. Then you can perform one of the following actions:

* travel to any other city $y$, paying $|a_x - a_y|$ coins;
* travel to the city which is the closest to $x$, paying $1$ coin.

You are given $m$ queries. In each query, you will be given two cities, and you have to calculate the minimum number of coins you have to spend to travel from one city to the other city.

## Input

The first line contains one integer $t$ ($1 \le t \le 10^4$) — the number of test cases.

Each test case is given in the following format:

* the first line contains one integer $n$ ($2 \le n \le 10^5$);
* the second line contains $n$ integers $a_1, a_2, \dots, a_n$ ($0 \le a_1 < a_2 < \dots < a_n \le 10^9$);
* the third line contains one integer $m$ ($1 \le m \le 10^5$);
* then $m$ lines follow; the $i$-th of them contains two integers $x_i$ and $y_i$ ($1 \le x_i, y_i \le n$; $x_i \ne y_i$), denoting that in the $i$-th query, you have to calculate the minimum number of coins you have to spend to travel from the city $x_i$ to the city $y_i$.

Additional constraints on the input:

* in every test case, for each city, the closest city is determined uniquely;
* the sum of $n$ over all test cases does not exceed $10^5$;
* the sum of $m$ over all test cases does not exceed $10^5$.
## Output

For each query, print one integer — the minimum number of coins you have to spend.

## Example

## Input


```

150 8 12 15 2051 41 53 43 25 1
```
## Output


```

3
8
1
4
14

```
## Note

Let's consider the first two queries in the example from the statement:

* in the first query, you are initially in the city $1$. You can travel to the closest city (which is the city $2$), paying $1$ coin. Then you travel to the closest city (which is the city $3$) again, paying $1$ coin. Then you travel to the closest city (which is the city $4$) again, paying $1$ coin. In total, you spend $3$ coins to get from the city $1$ to the city $4$;
* in the second query, you can use the same way to get from the city $1$ to the city $4$, and then spend $5$ coins to travel from the city $4$ to the city $5$.


#### tags 

#1300 #greedy #implementation #math 