![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Grid Paths

  * Task
  * Statistics

CSES - Grid Paths

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Consider an $n \times n$ grid whose top-left square is $(1,1)$ and bottom-
right square is $(n,n)$.

Your task is to move from the top-left square to the bottom-right square. On
each step you may move one square right or down. In addition, there are $m$
traps in the grid. You cannot move to a square with a trap.

What is the total number of possible paths?

# Input

The first input line contains two integers $n$ and $m$: the size of the grid
and the number of traps.

After this, there are $m$ lines describing the traps. Each such line contains
two integers $y$ and $x$: the location of a trap.

You can assume that there are no traps in the top-left and bottom-right
square.

# Output

Print the number of paths modulo $10^9+7$.

# Constraints

  * $1 \le n \le 10^6$
  * $1 \le m \le 1000$
  * $1 \le y,x \le n$

# Example

Input:

``` 3 1 2 2 ```

Output:

``` 2 ```

#### Additional Problems

... Grid Puzzle IGrid Puzzle IIEmpty StringGrid PathsBit SubstringsReversal
SortingCounting ReordersBook Shop II...

* * *

