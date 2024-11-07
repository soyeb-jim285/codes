![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Salary Queries

  * Task
  * Statistics

CSES - Salary Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A company has $n$ employees with certain salaries. Your task is to keep track
of the salaries and process queries.

# Input

The first input line contains two integers $n$ and $q$: the number of
employees and queries. The employees are numbered $1,2,\ldots,n$.

The next line has $n$ integers $p_1,p_2,\ldots,p_n$: each employee's salary.

After this, there are $q$ lines describing the queries. Each line has one of
the following forms:

  * `!` $k$ $x$: change the salary of employee $k$ to $x$
  * `?` $a$ $b$: count the number of employees whose salary is between $a \ldots b$

# Output

Print the answer to each `?` query.

# Constraints

  * $1 \le n, q \le 2 \cdot 10^5$
  * $1 \le p_i \le 10^9$
  * $1 \le k \le n$
  * $1 \le x \le 10^9$
  * $1 \le a \le b \le 10^9$

# Example

Input:

``` 5 3 3 7 2 2 5 ? 2 3 ! 3 6 ? 2 3 ```

Output:

``` 3 2 ```

#### Range Queries

... Forest QueriesHotel QueriesList RemovalsSalary QueriesPrefix Sum
QueriesPizzeria QueriesSubarray Sum QueriesDistinct Values Queries...

* * *

