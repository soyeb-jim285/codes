<h1 style='text-align: center;'> F. Timber</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

There is a beautiful alley with trees in front of a shopping mall. Unfortunately, it has to go to make space for the parking lot.

The trees on the alley all grow in a single line. There are $n$ spots for trees, index $0$ is the shopping mall, index $n+1$ is the road and indices from $1$ to $n$ are the spots for trees. Some of them are taken — there grow trees of the same height $k$. No more than one tree grows in each spot.

When you chop down a tree in the spot $x$, you can make it fall either left or right. If it falls to the left, it takes up spots from $x-k$ to $x$, inclusive. If it falls to the right, it takes up spots from $x$ to $x+k$, inclusive.

Let $m$ trees on the alley grow in some spots $x_1, x_2, \dots, x_m$. Let an alley be called unfortunate if all $m$ trees can be chopped down in such a way that: 

* no tree falls on the shopping mall or the road;
* each spot is taken up by no more than one fallen tree.

Calculate the number of different unfortunate alleys with $m$ trees of height $k$. Two alleys are considered different if there is a spot $y$ such that a tree grows in $y$ on the first alley and doesn't grow in $y$ on the second alley.

## Output

 the number modulo $998\,244\,353$.

## Input

The only line contains three integers $n, m$ and $k$ ($1 \le m, k \le n \le 3 \cdot 10^5$) — the number of spots for the trees, the number of trees and the height of each tree.

## Output

Print a single integer — the number of different unfortunate alleys with $m$ trees of height $k$, modulo $998\,244\,353$. 

## Examples

## Input


```

6 1 4

```
## Output


```

4

```
## Input


```

5 2 2

```
## Output


```

0

```
## Input


```

6 2 2

```
## Output


```

4

```
## Input


```

15 3 2

```
## Output


```

311

```


#### tags 

#2600 #combinatorics #dp #fft #math 