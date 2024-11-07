![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Subarray Sum Queries

  * Task
  * Statistics

CSES - Subarray Sum Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There is an array consisting of $n$ integers. Some values of the array will be
updated, and after each update, your task is to report the maximum subarray
sum in the array.

# Input

The first input line contains integers $n$ and $m$: the size of the array and
the number of updates. The array is indexed $1,2,\ldots,n$.

The next line has $n$ integers: $x_1,x_2,\ldots,x_n$: the initial contents of
the array.

Then there are $m$ lines describing the changes. Each line has two integers
$k$ and $x$: the value at position $k$ becomes $x$.

# Output

After each update, print the maximum subarray sum. Empty subarrays (with sum
$0$) are allowed.

# Constraints

  * $1 \le n, m \le 2 \cdot 10^5$
  * $-10^9 \le x_i \le 10^9$
  * $1 \le k \le n$
  * $-10^9 \le x \le 10^9$

# Example

Input:

``` 5 3 1 2 -3 5 -1 2 6 3 1 2 -2 ```

Output:

``` 9 13 6 ```

#### Range Queries

... Salary QueriesPrefix Sum QueriesPizzeria QueriesSubarray Sum
QueriesDistinct Values QueriesIncreasing Array QueriesForest Queries IIRange
Updates and Sums...

* * *

