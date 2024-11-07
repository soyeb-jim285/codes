![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Round Trip II

  * Task
  * Statistics

CSES - Round Trip II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Byteland has $n$ cities and $m$ flight connections. Your task is to design a
round trip that begins in a city, goes through one or more other cities, and
finally returns to the starting city. Every intermediate city on the route has
to be distinct.

# Input

The first input line has two integers $n$ and $m$: the number of cities and
flights. The cities are numbered $1,2,\dots,n$.

Then, there are $m$ lines describing the flights. Each line has two integers
$a$ and $b$: there is a flight connection from city $a$ to city $b$. All
connections are one-way flights from a city to another city.

# Output

First print an integer $k$: the number of cities on the route. Then print $k$
cities in the order they will be visited. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 4 5 1 3 2 1 2 4 3 2 3 4 ```

Output:

``` 4 2 1 3 2 ```

#### Graph Algorithms

... Flight DiscountCycle FindingFlight RoutesRound Trip IICourse
ScheduleLongest Flight RouteGame RoutesInvestigation...

* * *

