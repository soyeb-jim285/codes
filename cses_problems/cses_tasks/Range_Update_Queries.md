![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Range Update Queries

  * Task
  * Statistics

CSES - Range Update Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Given an array of $n$ integers, your task is to process $q$ queries of the
following types:

  1. increase each value in range $[a,b]$ by $u$
  2. what is the value at position $k$?

# Input

The first input line has two integers $n$ and $q$: the number of values and
queries.

The second line has $n$ integers $x_1,x_2,\dots,x_n$: the array values.

Finally, there are $q$ lines describing the queries. Each line has three
integers: either "$1$ $a$ $b$ $u$" or "$2$ $k$".

# Output

Print the result of each query of type 2.

# Constraints

  * $1 \le n,q \le 2 \cdot 10^5$
  * $1 \le x_i, u \le 10^9$
  * $1 \le k \le n$
  * $1 \le a \le b \le n$

# Example

Input:

``` 8 3 3 2 4 5 1 1 5 3 2 4 1 2 5 1 2 4 ```

Output:

``` 5 6 ```

#### Range Queries

... Dynamic Range Sum QueriesDynamic Range Minimum QueriesRange Xor
QueriesRange Update QueriesForest QueriesHotel QueriesList RemovalsSalary
Queries...

* * *

