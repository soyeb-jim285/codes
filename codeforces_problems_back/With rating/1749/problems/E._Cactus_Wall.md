<h1 style='text-align: center;'> E. Cactus Wall</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Monocarp is playing Minecraft and wants to build a wall of cacti. He wants to build it on a field of sand of the size of $n \times m$ cells. Initially, there are cacti in some cells of the field. Note that, in Minecraft, cacti cannot grow on cells adjacent to each other by side — and the initial field meets this restriction. Monocarp can plant new cacti (they must also fulfil the aforementioned condition). He can't chop down any of the cacti that are already growing on the field — he doesn't have an axe, and the cacti are too prickly for his hands.

Monocarp believes that the wall is complete if there is no path from the top row of the field to the bottom row, such that: 

* each two consecutive cells in the path are adjacent by side;
* no cell belonging to the path contains a cactus.

Your task is to plant the minimum number of cacti to build a wall (or to report that this is impossible).

## Input

The first line contains a single integer $t$ ($1 \le t \le 10^3$) — number of test cases.

The first line of each test case contains two integers $n$ and $m$ ($2 \le n, m \le 2 \cdot 10^5$; $n \times m \le 4 \cdot 10^5$) — the number of rows and columns, respectively.

Then $n$ rows follow, $i$-th row contains a string $s_i$ of length $m$, where $s_{i, j}$ is '#', if a cactus grows at the intersection of the $i$-th row and the $j$-th column. Otherwise, $s_{i, j}$ is '.'.

The sum of $n \times m$ over all test cases does not exceed $4 \cdot 10^5$.

## Output

For each test case, print NO in the first line if it is impossible to build a cactus wall without breaking the rules. Otherwise, print YES in the first line, then print $n$ lines of $m$ characters each — the field itself, where the $j$-th character of the $i$-th line is equal to '#', if there is a cactus on the intersection of the $i$-th row and the $j$-th column, otherwise it is '.'. If there are multiple optimal answers, print any of them.

## Example

## Input


```

42 4.#....#.3 3#.#....#.5 5.........................4 3#...#.#.#...
```
## Output


```

YES
.#.#
#.#.
NO
YES
....#
...#.
..#..
.#...
#....
YES
#..
.#.
#.#
...

```


#### tags 

#2400 #constructive_algorithms #dfs_and_similar #graphs #shortest_paths 