![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Forbidden Cities

  * Task
  * Statistics

CSES - Forbidden Cities

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are $n$ cities and $m$ roads between them. Kaaleppi is currently in city
$a$ and wants to travel to city $b$.

However, there is a problem: Kaaleppi has recently robbed a bank in city $c$
and can't enter the city, because the local police would catch him. Your task
is to find out if there is a route from city $a$ to city $b$ that does not
visit city $c$.

As an additional challenge, you have to process $q$ queries where $a$, $b$ and
$c$ vary.

# Input

The first input line has three integers $n$, $m$ and $q$: the number of
cities, roads and queries. The cities are numbered $1,2,\dots,n$.

Then, there are $m$ lines describing the roads. Each line has two integers $a$
and $b$: there is a road between cities $a$ and $b$. Each road is
bidirectional.

Finally, there are $q$ lines describing the queries. Each line has three
integers $a$, $b$ and $c$: is there a route from city $a$ to city $b$ that
does not visit city $c$?

You can assume that there is a route between any two cities.

# Output

For each query, print "YES", if there is such a route, and "NO" otherwise.

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le q \le 10^5$
  * $1 \le a,b,c \le n$

# Example

Input:

``` 5 6 3 1 2 1 3 2 3 2 4 3 4 4 5 1 4 2 3 5 4 3 5 2 ```

Output:

``` YES NO YES ```

#### Additional Problems

... Flight Route RequestsTwo Stacks SortingTree Isomorphism IIForbidden
CitiesArea of RectanglesGrid CompletionCreating OfficesPermutations II...

* * *

