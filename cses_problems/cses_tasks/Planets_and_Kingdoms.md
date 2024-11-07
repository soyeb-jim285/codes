![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Planets and Kingdoms

  * Task
  * Statistics

CSES - Planets and Kingdoms

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A game has $n$ planets, connected by $m$ teleporters. Two planets $a$ and $b$
belong to the same kingdom exactly when there is a route both from $a$ to $b$
and from $b$ to $a$. Your task is to determine for each planet its kingdom.

# Input

The first input line has two integers $n$ and $m$: the number of planets and
teleporters. The planets are numbered $1,2,\dots,n$.

After this, there are $m$ lines describing the teleporters. Each line has two
integers $a$ and $b$: you can travel from planet $a$ to planet $b$ through a
teleporter.

# Output

First print an integer $k$: the number of kingdoms. After this, print for each
planet a kingdom label between $1$ and $k$. You can print any valid solution.

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 5 6 1 2 2 3 3 1 3 4 4 5 5 4 ```

Output:

``` 2 1 1 1 2 2 ```

#### Graph Algorithms

... Road ReparationRoad ConstructionFlight Routes CheckPlanets and
KingdomsGiant PizzaCoin CollectorMail DeliveryDe Bruijn Sequence...

* * *

