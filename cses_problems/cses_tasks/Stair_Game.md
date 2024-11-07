![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Stair Game

  * Task
  * Statistics

CSES - Stair Game

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There is a staircase consisting of $n$ stairs, numbered $1,2,\ldots,n$.
Initially, each stair has some number of balls.

There are two players who move alternately. On each move, a player chooses a
stair $k$ where $k \neq 1$ and it has at least one ball. Then, the player
moves any number of balls from stair $k$ to stair $k-1$. The player who moves
last wins the game.

Your task is to find out who wins the game when both players play optimally.

Note that if there are no possible moves at all, the second player wins.

# Input

The first input line has an integer $t$: the number of tests. After this, $t$
test cases are described:

The first line contains an integer $n$: the number of stairs.

The next line has $n$ integers $p_1,p_2,\ldots,p_n$: the initial number of
balls on each stair.

# Output

For each test, print "first" if the first player wins the game and "second" if
the second player wins the game.

# Constraints

  * $1 \le t \le 2 \cdot 10^5$
  * $1 \le n \le 2 \cdot 10^5$
  * $0 \le p_i \le 10^9$
  * the sum of all $n$ is at most $2 \cdot 10^5$

# Example

Input:

``` 3 3 0 2 1 4 1 1 1 1 2 5 3 ```

Output:

``` first second first ```

#### Mathematics

... Candy LotteryInversion ProbabilityStick GameNim Game INim Game IIStair
GameGrundy's GameAnother Game

* * *

