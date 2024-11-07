![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Increasing Array Queries

  * Task
  * Statistics

CSES - Increasing Array Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given an array that consists of $n$ integers. The array elements are
indexed $1,2,\dots,n$.

You can modify the array using the following operation: choose an array
element and increase its value by one.

Your task is to process $q$ queries of the form: when we consider a subarray
from position $a$ to position $b$, what is the minimum number of operations
after which the subarray is increasing?

An array is increasing if each element is greater than or equal with the
previous element.

# Input

The first input line has two integers $n$ and $q$: the size of the array and
the number of queries.

The next line has $n$ integers $x_1,x_2,\dots,x_n$: the contents of the array.

Finally, there are $q$ lines that describe the queries. Each line has two
integers $a$ and $b$: the starting and ending position of a subarray.

# Output

For each query, print the minimum number of operations.

# Constraints

  * $1 \le n,q \le 2\cdot10^5$
  * $1 \le x_i \le 10^9$
  * $1 \le a \le b \le n$

# Example

Input:

``` 5 3 2 10 4 2 5 3 5 2 2 1 4 ```

Output:

``` 2 0 14 ```

#### Range Queries

... Pizzeria QueriesSubarray Sum QueriesDistinct Values QueriesIncreasing
Array QueriesForest Queries IIRange Updates and SumsPolynomial QueriesRange
Queries and Copies

* * *

