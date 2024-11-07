<h1 style='text-align: center;'> H. The Most Reckless Defense</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are playing a very popular Tower Defense game called "Runnerfield 2". In this game, the player sets up defensive towers that attack enemies moving from a certain starting point to the player's base.

You are given a grid of size $n \times m$, on which $k$ towers are already placed and a path is laid out through which enemies will move. The cell at the intersection of the $x$-th row and the $y$-th column is denoted as $(x, y)$.

Each second, a tower deals $p_i$ units of damage to all enemies within its range. For example, if an enemy is located at cell $(x, y)$ and a tower is at $(x_i, y_i)$ with a range of $r$, then the enemy will take damage of $p_i$ if $(x - x_i) ^ 2 + (y - y_i) ^ 2 \le r ^ 2$.

Enemies move from cell $(1, 1)$ to cell $(n, m)$, visiting each cell of the path exactly once. An enemy instantly moves to an adjacent cell horizontally or vertically, but before doing so, it spends one second in the current cell. If its health becomes zero or less during this second, the enemy can no longer move. The player loses if an enemy reaches cell $(n, m)$ and can make one more move.

By default, all towers have a zero range, but the player can set a tower's range to an integer $r$ ($r > 0$), in which case the health of all enemies will increase by $3^r$. However, each $r$ can only be used for at most one tower.

Suppose an enemy has a base health of $h$ units. If the tower ranges are $2$, $4$, and $5$, then the enemy's health at the start of the path will be $h + 3 ^ 2 + 3 ^ 4 + 3 ^ 5 = h + 9 + 81 + 243 = h + 333$. The choice of ranges is made once before the appearance of enemies and cannot be changed after the game starts.

Find the maximum amount of base health $h$ for which it is possible to set the ranges so that the player does not lose when an enemy with health $h$ passes through (without considering the additions for tower ranges).

## Input

The first line contains an integer $t$ ($1 \le t \le 100$) — the number of test cases.

The first line of each test case contains three integers $n$, $m$, and $k$ ($2 \le n, m \le 50, 1 \le k < n \cdot m$) — the dimensions of the field and the number of towers on it.

The next $n$ lines each contain $m$ characters — the description of each row of the field, where the character "." denotes an empty cell, and the character "#" denotes a path cell that the enemies will pass through.

Then follow $k$ lines — the description of the towers. Each line of description contains three integers $x_i$, $y_i$, and $p_i$ ($1 \le x_i \le n, 1 \le y_i \le m, 1 \le p_i \le 500$) — the coordinates of the tower and its attack parameter. All coordinates correspond to empty cells on the game field, and all pairs $(x_i, y_i)$ are pairwise distinct.

It is guaranteed that the sum of $n \cdot m$ does not exceed $2500$ for all test cases.

## Output

For each test case, output the maximum amount of base health $h$ on a separate line, for which it is possible to set the ranges so that the player does not lose when an enemy with health $h$ passes through (without considering the additions for tower ranges).

If it is impossible to choose ranges even for an enemy with $1$ unit of base health, output "0".

## Example

## Input


```

62 2 1#.##1 2 12 2 1#.##1 2 22 2 1#.##1 2 5003 3 2#..##..##1 2 43 1 33 5 2#.####.#.####.#2 2 22 4 25 5 4#....#....#....#....#####3 2 1424 5 92 5 791 3 50
```
## Output


```

0
1
1491
11
8
1797

```
## Note

In the first example, there is no point in increasing the tower range, as it will not be able to deal enough damage to the monster even with $1$ unit of health.

In the second example, the tower has a range of $1$, and it deals damage to the monster in cells $(1, 1)$ and $(2, 2)$.

In the third example, the tower has a range of $2$, and it deals damage to the monster in all path cells. If the enemy's base health is $1491$, then after the addition for the tower range, its health will be $1491 + 3 ^ 2 = 1500$, which exactly equals the damage the tower will deal to it in three seconds.

In the fourth example, the tower at $(1, 2)$ has a range of $1$, and the tower at $(3, 1)$ has a range of $2$.



#### tags 

#2300 #bitmasks #brute_force #constructive_algorithms #dp #flows #graph_matchings #shortest_paths 