<h1 style='text-align: center;'> E. Red-Black Pepper</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is going to host a party for his friends. He prepared $n$ dishes and is about to serve them. First, he has to add some powdered pepper to each of them — otherwise, the dishes will be pretty tasteless.

The $i$-th dish has two values $a_i$ and $b_i$ — its tastiness with red pepper added or black pepper added, respectively. Monocarp won't add both peppers to any dish, won't add any pepper multiple times, and won't leave any dish without the pepper added.

Before adding the pepper, Monocarp should first purchase the said pepper in some shop. There are $m$ shops in his local area. The $j$-th of them has packages of red pepper sufficient for $x_j$ servings and packages of black pepper sufficient for $y_j$ servings.

Monocarp goes to exactly one shop, purchases multiple (possibly, zero) packages of each pepper in such a way that each dish will get the pepper added once, and no pepper is left. More formally, if he purchases $x$ red pepper packages and $y$ black pepper packages, then $x$ and $y$ should be non-negative and $x \cdot x_j + y \cdot y_j$ should be equal to $n$.

For each shop, determine the maximum total tastiness of the dishes after Monocarp buys pepper packages only in this shop and adds the pepper to the dishes. If it's impossible to purchase the packages in the said way, print -1.

## Input

The first line contains a single integer $n$ ($1 \le n \le 3 \cdot 10^5$) — the number of dishes.

The $i$-th of the next $n$ lines contains two integers $a_i$ and $b_i$ ($1 \le a_i, b_i \le 10^9$) — the tastiness of the $i$-th dish with red pepper added or black pepper added, respectively.

The next line contains a single integer $m$ ($1 \le m \le 3 \cdot 10^5$) — the number of shops.

The $j$-th of the next $m$ lines contains two integers $x_j$ and $y_j$ ($1 \le x_j, y_j \le n$) — the number of servings the red and the black pepper packages are sufficient for in the $j$-th shop, respectively.

## Output

Print $m$ integers. For each shop, print the maximum total tastiness of the dishes after Monocarp buys pepper packages only in this shop and adds the pepper to the dishes. If it's impossible to purchase the packages so that each dish will get the pepper added once and no pepper is left, print -1.

## Examples

## Input


```

3
5 10
100 50
2 2
4
2 3
1 1
3 2
2 2

```
## Output


```

62
112
107
-1

```
## Input


```

10
3 1
2 3
1 1
2 1
6 3
1 4
4 3
1 3
5 3
5 4
10
8 10
9 3
1 4
2 5
8 3
3 5
1 6
7 2
6 7
3 1

```
## Output


```

26
-1
36
30
-1
26
34
26
-1
36

```
## Note

Consider the first example.

In the first shop, Monocarp can only buy $0$ red pepper packages and $1$ black pepper package. Black pepper added to all dishes will sum up to $10 + 50 + 2 = 62$.

In the second shop, Monocarp can buy any number of red and black pepper packages: $0$ and $3$, $1$ and $2$, $2$ and $1$ or $3$ and $0$. The optimal choice turns out to be either $1$ and $2$ or $2$ and $1$. Monocarp can add black pepper to the first dish, red pepper to the second dish and any pepper to the third dish, the total is $10 + 100 + 2 = 112$.

In the third shop, Monocarp can only buy $1$ red pepper package and $0$ black pepper packages. Red pepper added to all dishes will sum up to $5 + 100 + 2 = 107$.

In the fourth shop, Monocarp can only buy an even total number of packages. Since $n$ is odd, it's impossible to get exactly $n$ packages. Thus, the answer is $-1$.



#### tags 

#2300 #brute_force #data_structures #greedy #math #number_theory 