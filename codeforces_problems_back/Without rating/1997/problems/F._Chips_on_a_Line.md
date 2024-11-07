<h1 style='text-align: center;'> F. Chips on a Line</h1>

<h5 style='text-align: center;'>time limit per test: 5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You have $n$ chips, and you are going to place all of them in one of $x$ points, numbered from $1$ to $x$. There can be multiple chips in each point.

After placing the chips, you can perform the following four operations (in any order, any number of times):

* choose a chip in point $i \ge 3$, remove it and place two chips: one in $i-1$, one in $i-2$;
* choose two chips in adjacent points $i$ and $i+1$, remove them and place a new chip in $i+2$;
* choose a chip in point $1$ and move it to $2$;
* choose a chip in point $2$ and move it to $1$.

## Note

 that the coordinates of the chips you place during the operations cannot be less than $1$, but can be greater than $x$.

Denote the cost of chip placement as the minimum number of chips which can be present on the line after you perform these operations, starting from the placement you've chosen.

For example, the cost of placing two chips in points $3$ and one chip in point $5$ is $2$, because you can reduce the number of chips to $2$ as follows:

* choose a chip in point $3$, remove it, place a chip in $1$ and another chip in $2$;
* choose the chips in points $2$ and $3$, remove them and place a chip in $4$;
* choose the chips in points $4$ and $5$, remove them and place a chip in $6$.

You are given three integers $n$, $x$ and $m$. Calculate the number of placements of exactly $n$ chips in points from $1$ to $x$ having cost equal to $m$, and print it modulo $998244353$. Two placements are considered different if the number of chips in some point differs between these placements.

## Input

The only line contains three integers $n$, $x$ and $m$ ($1 \le m \le n \le 1000$; $2 \le x \le 10$).

## Output

Print one integer — the number of placements with cost equal to $m$, taken modulo $998244353$.

## Examples

## Input


```

2 3 1
```
## Output


```

5

```
## Input


```

42 10 5
```
## Output


```

902673363

```
## Input


```

1000 10 8
```
## Output


```

187821763

```
## Note

In the first example, there are five ways to place $2$ chips in points from $1$ to $3$ so that the cost is $1$:

* $(1, 1)$;
* $(1, 2)$;
* $(1, 3)$;
* $(2, 2)$;
* $(2, 3)$.


#### tags 

#dp #math 