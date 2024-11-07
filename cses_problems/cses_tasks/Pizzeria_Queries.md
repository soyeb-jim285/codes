![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Pizzeria Queries

  * Task
  * Statistics

CSES - Pizzeria Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are $n$ buildings on a street, numbered $1,2,\dots,n$. Each building has
a pizzeria and an apartment.

The pizza price in building $k$ is $p_k$. If you order a pizza from building
$a$ to building $b$, its price (with delivery) is $p_a+|a-b|$.

Your task is to process two types of queries:

  1. The pizza price $p_k$ in building $k$ becomes $x$.
  2. You are in building $k$ and want to order a pizza. What is the minimum price?

# Input

The first input line has two integers $n$ and $q$: the number of buildings and
queries.

The second line has $n$ integers $p_1,p_2,\dots,p_n$: the initial pizza price
in each building.

Finally, there are $q$ lines that describe the queries. Each line is either "1
$k$ $x$" or "2 $k$".

# Output

Print the answer for each query of type 2.

# Constraints

  * $1 \le n,q \le 2 \cdot 10^5$
  * $1 \le p_i, x \le 10^9$
  * $1 \le k \le n$

# Example

Input:

``` 6 3 8 6 4 5 7 5 2 2 1 5 1 2 2 ```

Output:

``` 5 4 ```

#### Range Queries

... List RemovalsSalary QueriesPrefix Sum QueriesPizzeria QueriesSubarray Sum
QueriesDistinct Values QueriesIncreasing Array QueriesForest Queries II...

* * *

