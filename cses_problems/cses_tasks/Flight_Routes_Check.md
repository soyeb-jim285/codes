![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Flight Routes Check

  * Task
  * Statistics

CSES - Flight Routes Check

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are $n$ cities and $m$ flight connections. Your task is to check if you
can travel from any city to any other city using the available flights.

# Input

The first input line has two integers $n$ and $m$: the number of cities and
flights. The cities are numbered $1,2,\dots,n$.

After this, there are $m$ lines describing the flights. Each line has two
integers $a$ and $b$: there is a flight from city $a$ to city $b$. All flights
are one-way flights.

# Output

Print "YES" if all routes are possible, and "NO" otherwise. In the latter case
also print two cities $a$ and $b$ such that you cannot travel from city $a$ to
city $b$. If there are several possible solutions, you can print any of them.

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 4 5 1 2 2 3 3 1 1 4 3 4 ```

Output:

``` NO 4 2 ```

#### Graph Algorithms

... Planets CyclesRoad ReparationRoad ConstructionFlight Routes CheckPlanets
and KingdomsGiant PizzaCoin CollectorMail Delivery...

* * *

