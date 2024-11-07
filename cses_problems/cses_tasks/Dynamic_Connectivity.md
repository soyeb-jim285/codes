![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Dynamic Connectivity

  * Task
  * Statistics

CSES - Dynamic Connectivity

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Consider an undirected graph that consists of $n$ nodes and $m$ edges. There
are two types of events that can happen:

  1. A new edge is created between nodes $a$ and $b$.
  2. An existing edge between nodes $a$ and $b$ is removed.

Your task is to report the number of components after every event.

# Input

The first input line has three integers $n$, $m$ and $k$: the number of nodes,
edges and events.

After this there are $m$ lines describing the edges. Each line has two
integers $a$ and $b$: there is an edge between nodes $a$ and $b$. There is at
most one edge between any pair of nodes.

Then there are $k$ lines describing the events. Each line has the form "$t$
$a$ $b$" where $t$ is 1 (create a new edge) or 2 (remove an edge). A new edge
is always created between two nodes that do not already have an edge between
them, and only existing edges can get removed.

# Output

Print $k+1$ integers: first the number of components before the first event,
and after this the new number of components after each event.

# Constraints

  * $2 \le n \le 10^5$
  * $1 \le m,k \le 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 5 3 3 1 4 2 3 3 5 1 2 5 2 3 5 1 1 2 ```

Output:

``` 2 2 2 1 ```

#### Advanced Techniques

... Apples and BananasOne Bit PositionsSignal ProcessingNew Roads
QueriesDynamic ConnectivityParcel DeliveryTask AssignmentDistinct Routes II

* * *

