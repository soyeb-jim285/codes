![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Game Routes

  * Task
  * Statistics

CSES - Game Routes

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A game has $n$ levels, connected by $m$ teleporters, and your task is to get
from level $1$ to level $n$. The game has been designed so that there are no
directed cycles in the underlying graph. In how many ways can you complete the
game?

# Input

The first input line has two integers $n$ and $m$: the number of levels and
teleporters. The levels are numbered $1,2,\dots,n$.

After this, there are $m$ lines describing the teleporters. Each line has two
integers $a$ and $b$: there is a teleporter from level $a$ to level $b$.

# Output

Print one integer: the number of ways you can complete the game. Since the
result may be large, print it modulo $10^9+7$.

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 4 5 1 2 2 4 1 3 3 4 1 4 ```

Output:

``` 3 ```

#### Graph Algorithms

... Round Trip IICourse ScheduleLongest Flight RouteGame
RoutesInvestigationPlanets Queries IPlanets Queries IIPlanets Cycles...

* * *

