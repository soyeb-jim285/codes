![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Parcel Delivery

  * Task
  * Statistics

CSES - Parcel Delivery

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are $n$ cities and $m$ routes through which parcels can be carried from
one city to another city. For each route, you know the maximum number of
parcels and the cost of a single parcel.

You want to send $k$ parcels from Syrjälä to Lehmälä. What is the cheapest way
to do that?

# Input

The first input line has three integers $n$, $m$ and $k$: the number of
cities, routes and parcels. The cities are numbered $1,2,\dots,n$. City $1$ is
Syrjälä and city $n$ is Lehmälä.

After this, there are $m$ lines that describe the routes. Each line has four
integers $a$, $b$, $r$ and $c$: there is a route from city $a$ to city $b$, at
most $r$ parcels can be carried through the route, and the cost of each parcel
is $c$.

# Output

Print one integer: the minimum total cost or $-1$ if there are no solutions.

# Constraints

  * $2 \le n \le 500$
  * $1 \le m \le 1000$
  * $1 \le k \le 100$
  * $1 \le a,b \le n$
  * $1 \le r,c \le 1000$

# Example

Input:

``` 4 5 3 1 2 5 100 1 3 10 50 1 4 7 500 2 4 8 350 3 4 2 100 ```

Output:

``` 750 ```

Explanation: One parcel is delivered through route $1 \rightarrow 2
\rightarrow 4$ (cost $1 \cdot 450=450$) and two parcels are delivered through
route $1 \rightarrow 3 \rightarrow 4$ (cost $2 \cdot 150=300$).

#### Advanced Techniques

... Apples and BananasOne Bit PositionsSignal ProcessingNew Roads
QueriesDynamic ConnectivityParcel DeliveryTask AssignmentDistinct Routes II

* * *

