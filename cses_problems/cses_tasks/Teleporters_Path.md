![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Teleporters Path

  * Task
  * Statistics

CSES - Teleporters Path

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A game has $n$ levels and $m$ teleportes between them. You win the game if you
move from level $1$ to level $n$ using every teleporter exactly once.

Can you win the game, and what is a possible way to do it?

# Input

The first input line has two integers $n$ and $m$: the number of levels and
teleporters. The levels are numbered $1,2,\dots,n$.

Then, there are $m$ lines describing the teleporters. Each line has two
integers $a$ and $b$: there is a teleporter from level $a$ to level $b$.

You can assume that each pair $(a,b)$ in the input is distinct.

# Output

Print $m+1$ integers: the sequence in which you visit the levels during the
game. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

# Constraints

  * $2 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 5 6 1 2 1 3 2 4 2 5 3 1 4 2 ```

Output:

``` 1 3 1 2 4 2 5 ```

#### Graph Algorithms

... Coin CollectorMail DeliveryDe Bruijn SequenceTeleporters PathHamiltonian
FlightsKnight's TourDownload SpeedPolice Chase...

* * *

