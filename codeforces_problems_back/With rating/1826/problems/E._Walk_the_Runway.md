<h1 style='text-align: center;'> E. Walk the Runway</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A fashion tour consists of $m$ identical runway shows in different cities. There are $n$ models willing to participate in the tour, numbered from $1$ to $n$. People in different cities have different views on the fashion industry, so they rate each model differently. In particular, people in city $i$ rate model $j$ with rating $r_{i, j}$.

You are to choose some number of $k$ models, and their order, let the chosen models have indices $j_1, j_2, \dots, j_k$ in the chosen order. In each city, these $k$ models will walk the runway one after another in this order. To make the show exciting, in each city, the ratings of models should be strictly increasing in the order of their performance. More formally, for any city $i$ and index $t$ ($2 \leq t \leq k$), the ratings must satisfy $r_{i,j_{t - 1}} < r_{i,j_t}$. 

After all, the fashion industry is all about money, so choosing model $j$ to participate in the tour profits you $p_j$ money. Compute the maximum total profit you can make by choosing the models and their order while satisfying all the requirements.

## Input

The first line contains two integers $m$ and $n$ ($1 \leq m \leq 500$, $1 \leq n \leq 5000$) — the number of shows and the number of models willing to participate respectively.

The second line contains $n$ integers $p_j$ ($1 \leq p_j \leq 10^9$) — the profit you get inviting the $j$-th model to the tour.

The next $m$ lines each contain $n$ integers. Line number $i$ contains $n$ integers $r_{i, j}$ ($1 \leq r_{i, j} \leq n$) — the ratings of models in city $i$.

## Output

## Output

 a single integer — the largest total amount of money you can get.

## Examples

## Input


```

3 5
10 10 10 10 10
1 2 3 4 5
1 5 2 3 4
2 3 4 5 1

```
## Output


```

30

```
## Input


```

3 5
10 10 10 10 50
1 2 3 4 5
1 5 2 3 4
2 3 4 5 1

```
## Output


```

50

```
## Input


```

1 1
1000000000
1

```
## Output


```

1000000000

```
## Input


```

5 5
1000000000 1000000000 1000000000 1000000000 1000000000
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1
5 4 3 2 1

```
## Output


```

5000000000

```
## Input


```

1 3
1 2 3
3 3 3

```
## Output


```

3

```
## Note

In the first example, there are $3$ invited models. The show consists of models in the order $[1, 3, 4]$.

Then, the corresponding ratings in the cities are as follows: 

* City $1$ — $[ 1, 3, 4 ]$.
* City $2$ — $[ 1, 2, 3 ]$.
* City $3$ — $[ 2, 4, 5 ]$.

You can see that the ratings are increasing. So the total profit is $10 + 10 + 10 = 30$. It can be proven that we can't achieve a bigger profit.

In the second example, we can invite the fifth model to the tour, which would result in a total profit of $50$. It can be proven that we can't achieve a bigger profit.

In the third example, we invite the single model to the tour, which results in a total profit of $1\,000\,000\,000$.

In the fourth test case, we can invite all the models and make the show in the order $[ 5, 4, 3, 2, 1 ]$. The total profit is $5 \cdot 1\,000\,000\,000 = 5\,000\,000\,000$.



#### tags 

#2400 #bitmasks #brute_force #data_structures #dp #graphs #implementation #sortings 