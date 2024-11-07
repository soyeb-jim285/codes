![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Shortest Routes II

  * Task
  * Statistics

CSES - Shortest Routes II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are $n$ cities and $m$ roads between them. Your task is to process $q$
queries where you have to determine the length of the shortest route between
two given cities.

# Input

The first input line has three integers $n$, $m$ and $q$: the number of
cities, roads, and queries.

Then, there are $m$ lines describing the roads. Each line has three integers
$a$, $b$ and $c$: there is a road between cities $a$ and $b$ whose length is
$c$. All roads are two-way roads.

Finally, there are $q$ lines describing the queries. Each line has two
integers $a$ and $b$: determine the length of the shortest route between
cities $a$ and $b$.

# Output

Print the length of the shortest route for each query. If there is no route,
print $-1$ instead.

# Constraints

  * $1 \le n \le 500$
  * $1 \le m \le n^2$
  * $1 \le q \le 10^5$
  * $1 \le a,b \le n$
  * $1 \le c \le 10^9$

# Example

Input:

``` 4 3 5 1 2 5 1 3 9 2 3 3 1 2 2 1 1 3 1 4 3 2 ```

Output:

``` 5 5 8 -1 3 ```

#### Graph Algorithms

... Round TripMonstersShortest Routes IShortest Routes IIHigh ScoreFlight
DiscountCycle FindingFlight Routes...

* * *

