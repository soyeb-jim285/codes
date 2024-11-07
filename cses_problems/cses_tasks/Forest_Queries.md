![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Forest Queries

  * Task
  * Statistics

CSES - Forest Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given an $n \times n$ grid representing the map of a forest. Each
square is either empty or contains a tree. The upper-left square has
coordinates $(1,1)$, and the lower-right square has coordinates $(n,n)$.

Your task is to process $q$ queries of the form: how many trees are inside a
given rectangle in the forest?

# Input

The first input line has two integers $n$ and $q$: the size of the forest and
the number of queries.

Then, there are $n$ lines describing the forest. Each line has $n$ characters:
`.` is an empty square and `*` is a tree.

Finally, there are $q$ lines describing the queries. Each line has four
integers $y_1$, $x_1$, $y_2$, $x_2$ corresponding to the corners of a
rectangle.

# Output

Print the number of trees inside each rectangle.

# Constraints

  * $1 \le n \le 1000$
  * $1 \le q \le 2 \cdot 10^5$
  * $1 \le y_1 \le y_2 \le n$
  * $1 \le x_1 \le x_2 \le n$

# Example

Input:

``` 4 3 .*.. *.** **.. **** 2 2 3 4 3 1 3 1 1 1 2 2 ```

Output:

``` 3 1 2 ```

#### Range Queries

... Dynamic Range Minimum QueriesRange Xor QueriesRange Update QueriesForest
QueriesHotel QueriesList RemovalsSalary QueriesPrefix Sum Queries...

* * *

