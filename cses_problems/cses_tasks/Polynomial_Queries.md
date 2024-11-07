![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Polynomial Queries

  * Task
  * Statistics

CSES - Polynomial Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Your task is to maintain an array of $n$ values and efficiently process the
following types of queries:

  1. Increase the first value in range $[a,b]$ by $1$, the second value by $2$, the third value by $3$, and so on.
  2. Calculate the sum of values in range $[a,b]$.

# Input

The first input line has two integers $n$ and $q$: the size of the array and
the number of queries.

The next line has $n$ values $t_1,t_2,\dots,t_n$: the initial contents of the
array.

Finally, there are $q$ lines describing the queries. The format of each line
is either "1 $a$ $b$" or "2 $a$ $b$".

# Output

Print the answer to each sum query.

# Constraints

  * $1 \le n, q \le 2 \cdot 10^5$
  * $1 \le t_i \le 10^6$
  * $1 \le a \le b \le n$

# Example

Input:

``` 5 3 4 2 3 1 7 2 1 5 1 1 5 2 1 5 ```

Output:

``` 17 32 ```

#### Range Queries

... Pizzeria QueriesSubarray Sum QueriesDistinct Values QueriesIncreasing
Array QueriesForest Queries IIRange Updates and SumsPolynomial QueriesRange
Queries and Copies

* * *

