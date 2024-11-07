![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Company Queries II

  * Task
  * Statistics

CSES - Company Queries II

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A company has $n$ employees, who form a tree hierarchy where each employee has
a boss, except for the general director.

Your task is to process $q$ queries of the form: who is the lowest common boss
of employees $a$ and $b$ in the hierarchy?

# Input

The first input line has two integers $n$ and $q$: the number of employees and
queries. The employees are numbered $1,2,\dots,n$, and employee $1$ is the
general director.

The next line has $n-1$ integers $e_2,e_3,\dots,e_n$: for each employee
$2,3,\dots,n$ their boss.

Finally, there are $q$ lines describing the queries. Each line has two
integers $a$ and $b$: who is the lowest common boss of employees $a$ and $b$?

# Output

Print the answer for each query.

# Constraints

  * $1 \le n,q \le 2 \cdot 10^5$
  * $1 \le e_i \le i-1$
  * $1 \le a,b \le n$

# Example

Input:

``` 5 3 1 1 3 3 4 5 2 5 1 4 ```

Output:

``` 3 1 1 ```

#### Tree Algorithms

... Tree Distances ITree Distances IICompany Queries ICompany Queries
IIDistance QueriesCounting PathsSubtree QueriesPath Queries...

* * *

