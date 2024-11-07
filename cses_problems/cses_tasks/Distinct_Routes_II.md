![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Distinct Routes II

  * Task
  * Statistics

CSES - Distinct Routes II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A game consists of $n$ rooms and $m$ teleporters. At the beginning of each
day, you start in room $1$ and you have to reach room $n$.

You can use each teleporter at most once during the game. You want to play the
game for exactly $k$ days. Every time you use any teleporter you have to pay
one coin. What is the minimum number of coins you have to pay during $k$ days
if you play optimally?

# Input

The first input line has three integers $n$, $m$ and $k$: the number of rooms,
the number of teleporters and the number of days you play the game. The rooms
are numbered $1,2,\dots,n$.

After this, there are $m$ lines describing the teleporters. Each line has two
integers $a$ and $b$: there is a teleporter from room $a$ to room $b$.

There are no two teleporters whose starting and ending room are the same.

# Output

First print one integer: the minimum number of coins you have to pay if you
play optimally. Then, print $k$ route descriptions according to the example.
You can print any valid solution.

If it is not possible to play the game for $k$ days, print only -1.

# Constraints

  * $2 \le n \le 500$
  * $1 \le m \le 1000$
  * $1 \le k \le n-1$
  * $1 \le a,b \le n$

# Example

Input:

``` 8 10 2 1 2 1 3 2 5 2 4 3 5 3 6 4 8 5 8 6 7 7 8 ```

Output:

``` 6 4 1 2 4 8 4 1 3 5 8 ```

#### Advanced Techniques

... Apples and BananasOne Bit PositionsSignal ProcessingNew Roads
QueriesDynamic ConnectivityParcel DeliveryTask AssignmentDistinct Routes II

* * *

