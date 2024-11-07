<h1 style='text-align: center;'> E. Nim Shortcuts</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

After your debut mobile game "Nim" blew up, you decided to make a sequel called "Nim 2". This game will expand on the trusted Nim game formula, adding the much awaited second heap! 

In the game, there are two heaps, each containing a non-negative number of stones. Two players make moves in turn. On their turn, a player can take any positive number of stones from either one of the heaps. A player who is unable to move loses the game.

To make the game easier to playtest, you've introduced developer shortcuts. There are $n$ shortcut positions $(x_1, y_1), \ldots, (x_n, y_n)$. These change the game as follows: suppose that before a player's turn the first and second heap contain $x$ and $y$ stones respectively. If the pair $(x, y)$ is equal to one of the pairs $(x_i, y_i)$, then the player about to move loses instantly, otherwise they are able to make moves as normal. Note that in the above explanation the two heaps and all pairs are ordered, that is, $x$ must refer to the size of the first heap, and $y$ must refer to the size of the second heap.

The game release was followed by too much celebration, and next thing you know is developer shortcuts made their way to the next official update of the game! Players now complain that the AI opponent has become unbeatable at certain stages of the game. You now have to write a program to figure out which of the given initial positions can be won by the starting player, assuming both players act optimally.

## Input

The first line contains two integers $n$ and $m$ ($1 \leq n, m \leq 10^5$) — the number of shortcut positions, and the number of initial positions that need to be evaluated.

The following $n$ lines describe shortcut positions. The $i$-th of these lines contains two integers $x_i, y_i$ ($0 \leq x_i, y_i \leq 10^9$). It is guaranteed that all shortcut positions are distinct.

The following $m$ lines describe initial positions. The $i$-th of these lines contains two integers $a_i, b_i$ ($0 \leq a_i, b_i \leq 10^9$) — the number of stones in the first and second heap respectively. It is guaranteed that all initial positions are distinct. However, initial positions are not necessarily distinct from shortcut positions.

## Output

For each initial position, on a separate line print "WIN" if the starting player is able to win from this position, and "LOSE" otherwise.

## Example

## Input


```

3 5
3 0
0 1
2 2
0 0
1 1
2 2
3 3
5 4

```
## Output


```

LOSE
WIN
LOSE
WIN
LOSE

```


#### tags 

#3100 #data_structures #games 