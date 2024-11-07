![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Network Renovation

  * Task
  * Statistics

CSES - Network Renovation

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Syrjälä's network consists of $n$ computers and $n-1$ connections between
them. It is possible to send data between any two computers.

However, if any connection breaks down, it will no longer be possible to send
data between some computers. Your task is to add the minimum number of new
connections in such a way that you can still send data between any two
computers even if any single connection breaks down.

# Input

The first input line has an integer $n$: the number of computers. The
computers are numbered $1,2,\dots,n$.

After this, there are $n-1$ lines describing the connections. Each line has
two integers $a$ and $b$: there is a connection between computers $a$ and $b$.

# Output

First print an integer $k$: the minimum number of new connections. After this,
print $k$ lines describing the connections. You can print any valid solution.

# Constraints

  * $3 \le n \le 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 5 1 2 1 3 3 4 3 5 ```

Output:

``` 2 2 4 4 5 ```

#### Additional Problems

... Movie Festival QueriesChess TournamentTree TraversalsNetwork
RenovationGraph GirthIntersection PointsInverse InversionsMonotone
Subsequences...

* * *

