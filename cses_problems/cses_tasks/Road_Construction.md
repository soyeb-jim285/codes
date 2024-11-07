![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Road Construction

  * Task
  * Statistics

CSES - Road Construction

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are $n$ cities and initially no roads between them. However, every day a
new road will be constructed, and there will be a total of $m$ roads.

A component is a group of cities where there is a route between any two cities
using the roads. After each day, your task is to find the number of components
and the size of the largest component.

# Input

The first input line has two integers $n$ and $m$: the number of cities and
roads. The cities are numbered $1,2,\dots,n$.

Then, there are $m$ lines describing the new roads. Each line has two integers
$a$ and $b$: a new road is constructed between cities $a$ and $b$.

You may assume that every road will be constructed between two different
cities.

# Output

Print $m$ lines: the required information after each day.

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 5 3 1 2 1 3 4 5 ```

Output:

``` 4 2 3 3 2 3 ```

#### Graph Algorithms

... Planets Queries IIPlanets CyclesRoad ReparationRoad ConstructionFlight
Routes CheckPlanets and KingdomsGiant PizzaCoin Collector...

* * *

