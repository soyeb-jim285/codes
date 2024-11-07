![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Planets Queries II

  * Task
  * Statistics

CSES - Planets Queries II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are playing a game consisting of n planets. Each planet has a teleporter
to another planet (or the planet itself).

You have to process $q$ queries of the form: You are now on planet $a$ and
want to reach planet $b$. What is the minimum number of teleportations?

# Input

The first input line contains two integers $n$ and $q$: the number of planets
and queries. The planets are numbered $1,2,\ldots,n$.

The second line contains $n$ integers $t_1,t_2,\ldots,t_n$: for each planet,
the destination of the teleporter.

Finally, there are $q$ lines describing the queries. Each line has two
integers $a$ and $b$: you are now on planet $a$ and want to reach planet $b$.

# Output

For each query, print the minimum number of teleportations. If it is not
possible to reach the destination, print $-1$.

# Constraints

  * $1 \le n, q \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 5 3 2 3 2 3 2 1 2 1 3 1 4 ```

Output:

``` 1 2 -1 ```

#### Graph Algorithms

... Game RoutesInvestigationPlanets Queries IPlanets Queries IIPlanets
CyclesRoad ReparationRoad ConstructionFlight Routes Check...

* * *

