![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Dynamic Range Minimum Queries

  * Task
  * Statistics

CSES - Dynamic Range Minimum Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Given an array of $n$ integers, your task is to process $q$ queries of the
following types:

  1. update the value at position $k$ to $u$
  2. what is the minimum value in range $[a,b]$?

# Input

The first input line has two integers $n$ and $q$: the number of values and
queries.

The second line has $n$ integers $x_1,x_2,\dots,x_n$: the array values.

Finally, there are $q$ lines describing the queries. Each line has three
integers: either "$1$ $k$ $u$" or "$2$ $a$ $b$".

# Output

Print the result of each query of type 2.

# Constraints

  * $1 \le n,q \le 2 \cdot 10^5$
  * $1 \le x_i, u \le 10^9$
  * $1 \le k \le n$
  * $1 \le a \le b \le n$

# Example

Input:

``` 8 4 3 2 4 5 1 1 5 3 2 1 4 2 5 6 1 2 3 2 1 4 ```

Output:

``` 2 1 3 ```

#### Range Queries

Static Range Sum QueriesStatic Range Minimum QueriesDynamic Range Sum
QueriesDynamic Range Minimum QueriesRange Xor QueriesRange Update
QueriesForest QueriesHotel Queries...

* * *

