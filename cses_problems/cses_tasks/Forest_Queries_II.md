![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Forest Queries II

  * Task
  * Statistics

CSES - Forest Queries II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given an $n \times n$ grid representing the map of a forest. Each
square is either empty or has a tree. Your task is to process $q$ queries of
the following types:

  1. Change the state (empty/tree) of a square.
  2. How many trees are inside a rectangle in the forest?

# Input

The first input line has two integers $n$ and $q$: the size of the forest and
the number of queries.

Then, there are $n$ lines describing the forest. Each line has $n$ characters:
`.` is an empty square and `*` is a tree.

Finally, there are $q$ lines describing the queries. The format of each line
is either "$1$ $y$ $x$" or "2 $y_1$ $x_1$ $y_2$ $x_2$".

# Output

Print the answer to each query of the second type.

# Constraints

  * $1 \le n \le 1000$
  * $1 \le q \le 2 \cdot 10^5$
  * $1 \le y,x \le n$
  * $1 \le y_1 \le y_2 \le n$
  * $1 \le x_1 \le x_2 \le n$

# Example

Input:

``` 4 3 .*.. *.** **.. **** 2 2 2 3 4 1 3 3 2 2 2 3 4 ```

Output:

``` 3 4 ```

#### Range Queries

... Pizzeria QueriesSubarray Sum QueriesDistinct Values QueriesIncreasing
Array QueriesForest Queries IIRange Updates and SumsPolynomial QueriesRange
Queries and Copies

* * *

