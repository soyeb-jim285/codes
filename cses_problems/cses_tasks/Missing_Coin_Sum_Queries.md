![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Missing Coin Sum Queries

  * Task
  * Statistics

CSES - Missing Coin Sum Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You have $n$ coins with positive integer values. The coins are numbered
$1,2,\dots,n$.

Your task is to process $q$ queries of the form: "if you can use coins $a
\dots b$, what is the smallest sum you cannot produce?"

# Input

The first input line has two integers $n$ and $q$: the number of coins and
queries.

The second line has $n$ integers $x_1,x_2,\dots,x_n$: the value of each coin.

Finally, there are $q$ lines that describe the queries. Each line has two
values $a$ and $b$: you can use coins $a \dots b$.

# Output

Print the answer for each query.

# Constraints

  * $1 \le n, q \le 2 \cdot 10^5$
  * $1 \le x_i \le 10^9$
  * $1 \le a \le b \le n$

# Example

Input:

``` 5 3 2 9 1 2 7 2 4 4 4 1 5 ```

Output:

``` 4 1 6 ```

Explanation: First you can use coins $[9,1,2]$, then coins $[2]$ and finally
coins $[2,9,1,2,7]$.

#### Additional Problems

... Book Shop IINetwork BreakdownVisiting CitiesMissing Coin Sum QueriesNumber
GridMaximum Building IIFilling TrominosStick Divisions...

* * *

