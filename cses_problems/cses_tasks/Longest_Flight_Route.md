![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Longest Flight Route

  * Task
  * Statistics

CSES - Longest Flight Route

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Uolevi has won a contest, and the prize is a free flight trip that can consist
of one or more flights through cities. Of course, Uolevi wants to choose a
trip that has as many cities as possible.

Uolevi wants to fly from Syrjälä to Lehmälä so that he visits the maximum
number of cities. You are given the list of possible flights, and you know
that there are no directed cycles in the flight network.

# Input

The first input line has two integers $n$ and $m$: the number of cities and
flights. The cities are numbered $1,2,\dots,n$. City $1$ is Syrjälä, and city
$n$ is Lehmälä.

After this, there are $m$ lines describing the flights. Each line has two
integers $a$ and $b$: there is a flight from city $a$ to city $b$. Each flight
is a one-way flight.

# Output

First print the maximum number of cities on the route. After this, print the
cities in the order they will be visited. You can print any valid solution.

If there are no solutions, print "IMPOSSIBLE".

# Constraints

  * $2 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 5 5 1 2 2 5 1 3 3 4 4 5 ```

Output:

``` 4 1 3 4 5 ```

#### Graph Algorithms

... Flight RoutesRound Trip IICourse ScheduleLongest Flight RouteGame
RoutesInvestigationPlanets Queries IPlanets Queries II...

* * *

