![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Road Reparation

  * Task
  * Statistics

CSES - Road Reparation

  * **Time limit:** 1.00 s
  * **Memory limit:** 128 MB

There are $n$ cities and $m$ roads between them. Unfortunately, the condition
of the roads is so poor that they cannot be used. Your task is to repair some
of the roads so that there will be a decent route between any two cities.

For each road, you know its reparation cost, and you should find a solution
where the total cost is as small as possible.

# Input

The first input line has two integers $n$ and $m$: the number of cities and
roads. The cities are numbered $1,2,\dots,n$.

Then, there are $m$ lines describing the roads. Each line has three integers
$a$, $b$ and $c$: there is a road between cities $a$ and $b$, and its
reparation cost is $c$. All roads are two-way roads.

Every road is between two different cities, and there is at most one road
between two cities.

# Output

Print one integer: the minimum total reparation cost. However, if there are no
solutions, print "IMPOSSIBLE".

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$
  * $1 \le c \le 10^9$

# Example

Input:

``` 5 6 1 2 3 2 3 5 2 4 2 3 4 8 5 1 7 5 4 4 ```

Output:

``` 14 ```

#### Graph Algorithms

... Planets Queries IPlanets Queries IIPlanets CyclesRoad ReparationRoad
ConstructionFlight Routes CheckPlanets and KingdomsGiant Pizza...

* * *

