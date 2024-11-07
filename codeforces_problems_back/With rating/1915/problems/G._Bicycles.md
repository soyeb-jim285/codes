<h1 style='text-align: center;'> G. Bicycles</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

All of Slavic's friends are planning to travel from the place where they live to a party using their bikes. And they all have a bike except Slavic. There are $n$ cities through which they can travel. They all live in the city $1$ and want to go to the party located in the city $n$. The map of cities can be seen as an undirected graph with $n$ nodes and $m$ edges. Edge $i$ connects cities $u_i$ and $v_i$ and has a length of $w_i$.

Slavic doesn't have a bike, but what he has is money. Every city has exactly one bike for sale. The bike in the $i$-th city has a slowness factor of $s_{i}$. Once Slavic buys a bike, he can use it whenever to travel from the city he is currently in to any neighboring city, by taking $w_i \cdot s_j$ time, considering he is traversing edge $i$ using a bike $j$ he owns.

Slavic can buy as many bikes as he wants as money isn't a problem for him. Since Slavic hates traveling by bike, he wants to get from his place to the party in the shortest amount of time possible. And, since his informatics skills are quite rusty, he asks you for help.

What's the shortest amount of time required for Slavic to travel from city $1$ to city $n$? Slavic can't travel without a bike. It is guaranteed that it is possible for Slavic to travel from city $1$ to any other city.

## Input

The first line contains a single integer $t$ ($1 \leq t \leq 100$) — the number of test cases. The description of the test cases follows.

The first line of each test case contains two space-separated integers $n$ and $m$ ($2 \leq n \leq 1000$; $n - 1 \leq m \leq 1000$) — the number of cities and the number of roads, respectively.

The $i$-th of the following $m$ lines each contain three integers $u_i$, $v_i$, $w_i$ ($1 \le u_i, v_i \le n$, $u_i \neq v_i$; $1 \leq w_i \leq 10^5$), denoting that there is a road between cities $u_i$ and $v_i$ of length $w_i$. The same pair of cities can be connected by more than one road.

The next line contains $n$ integers $s_1, \ldots, s_n$ ($1 \leq s_i \leq 1000$) — the slowness factor of each bike.

The sum of $n$ over all test cases does not exceed $1000$, and the sum of $m$ over all test cases does not exceed $1000$.

Additional constraint on the input: it is possible to travel from city $1$ to any other city.

## Output

For each test case, output a single integer denoting the shortest amount of time Slavic can reach city $n$ starting from city $1$.

## Example

## Input


```

35 51 2 23 2 12 4 52 5 74 5 15 2 1 3 35 101 2 51 3 51 4 41 5 82 3 62 4 32 5 23 4 13 5 84 5 27 2 8 4 17 103 2 82 1 42 5 72 6 47 1 24 3 56 4 26 7 16 7 44 5 97 6 5 4 3 2 1
```
## Output


```

19
36
14

```


#### tags 

#1800 #graphs #greedy #implementation #shortest_paths #sortings 