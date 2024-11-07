![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Planets Queries I

  * Task
  * Statistics

CSES - Planets Queries I

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are playing a game consisting of $n$ planets. Each planet has a teleporter
to another planet (or the planet itself).

Your task is to process $q$ queries of the form: when you begin on planet $x$
and travel through $k$ teleporters, which planet will you reach?

# Input

The first input line has two integers $n$ and $q$: the number of planets and
queries. The planets are numbered $1,2,\dots,n$.

The second line has $n$ integers $t_1,t_2,\dots,t_n$: for each planet, the
destination of the teleporter. It is possible that $t_i=i$.

Finally, there are $q$ lines describing the queries. Each line has two
integers $x$ and $k$: you start on planet $x$ and travel through $k$
teleporters.

# Output

Print the answer to each query.

# Constraints

  * $1 \le n, q \le 2 \cdot 10^5$
  * $1 \le t_i \le n$
  * $1 \le x \le n$
  * $0 \le k \le 10^9$

# Example

Input:

``` 4 3 2 1 1 4 1 2 3 4 4 1 ```

Output:

``` 1 2 4 ```

#### Graph Algorithms

... Longest Flight RouteGame RoutesInvestigationPlanets Queries IPlanets
Queries IIPlanets CyclesRoad ReparationRoad Construction...

* * *

