<h1 style='text-align: center;'> D. Jellyfish and Miku</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

There are $n + 1$ cities with numbers from $0$ to $n$, connected by $n$ roads. The $i$-th $(1 \leq i \leq n)$ road connects city $i-1$ and city $i$ bi-directionally. After Jellyfish flew back to city $0$, she found out that she had left her Miku fufu in city $n$.

Each road has a positive integer level of beauty. Denote the beauty of the $i$-th road as $a_i$.

Jellyfish is trying to find her fufu. Because of her poor sense of direction, she doesn't know which way to go. Every day, she randomly chooses a road connected to the city she currently is in and traverses it. Let $s$ be the sum of the beauty of the roads connected to the current city. For each road connected to the current city, Jellyfish will traverse the road with a probability of $\frac x s$, where $x$ is the beauty of the road, reaching the city on the other side of the road.

Jellyfish will start at city $0$, and she will get only her fufu back when she reaches city $n$.

You want to choose the beauty of the roads such that the expected number of days Jellyfish takes to find her fufu will be the minimum possible. However, due to limited funding, the sum of beauties of all roads must be less than or equal to $m$. 

Find the minimum expected number of days Jellyfish needs to get her fufu back if the beauty of the roads is chosen optimally.

## Input

The first and only line of the input contains two integers $n$ and $m$ ($1 \leq n \leq m \leq 3000$) — the number of the roads and the maximum sum of beauty of the roads.

## Output

## Output

 the minimum expected number of days Jellyfish needs to get her fufu back if the beauty of the roads is chosen optimally.

Your answer will be accepted if the absolute or relative error does not exceed $10^{-9}$. Formally, let your answer be $a$, and the jury's answer be $b$. Your answer is considered correct if $\frac{|a-b|}{\max(1,|b|)} \leq 10^{-9}$.

## Examples

## Input


```

3 8

```
## Output


```

5.200000000000
```
## Input


```

10 98

```
## Output


```

37.721155173329
```
## Note

In the first example, the optimal assignment of beauty is $a=[1, 2, 5]$. The expected number of days Jellyfish needs to get her fufu back is $5.2$.



#### tags 

#2800 #divide_and_conquer #dp #math #probabilities 