![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# List Removals

  * Task
  * Statistics

CSES - List Removals

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a list consisting of $n$ integers. Your task is to remove
elements from the list at given positions, and report the removed elements.

# Input

The first input line has an integer $n$: the initial size of the list. During
the process, the elements are numbered $1,2,\dots,k$ where $k$ is the current
size of the list.

The second line has $n$ integers $x_1,x_2,\dots,x_n$: the contents of the
list.

The last line has $n$ integers $p_1,p_2,\dots,p_n$: the positions of the
elements to be removed.

# Output

Print the elements in the order they are removed.

# Constraints

  * $1 \le n \le 2 \cdot 10^5$
  * $1 \le x_i \le 10^9$
  * $1 \le p_i \le n-i+1$

# Example

Input:

``` 5 2 6 1 4 2 3 1 3 1 1 ```

Output:

``` 1 2 2 6 4 ```

Explanation: The contents of the list are $[2,6,1,4,2]$, $[2,6,4,2]$,
$[6,4,2]$, $[6,4]$, $[4]$ and $[]$.

#### Range Queries

... Range Update QueriesForest QueriesHotel QueriesList RemovalsSalary
QueriesPrefix Sum QueriesPizzeria QueriesSubarray Sum Queries...

* * *

