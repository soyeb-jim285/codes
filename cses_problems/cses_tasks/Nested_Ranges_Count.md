![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Nested Ranges Count

  * Task
  * Statistics

CSES - Nested Ranges Count

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Given $n$ ranges, your task is to count for each range how many other ranges
it contains and how many other ranges contain it.

Range $[a,b]$ contains range $[c,d]$ if $a \le c$ and $d \le b$.

# Input

The first input line has an integer $n$: the number of ranges.

After this, there are $n$ lines that describe the ranges. Each line has two
integers $x$ and $y$: the range is $[x,y]$.

You may assume that no range appears more than once in the input.

# Output

First print a line that describes for each range (in the input order) how many
other ranges it contains.

Then print a line that describes for each range (in the input order) how many
other ranges contain it.

# Constraints

  * $1 \le n \le 2 \cdot 10^5$
  * $1 \le x < y \le 10^9$

# Example

Input:

``` 4 1 6 2 4 4 8 3 6 ```

Output:

``` 2 0 0 0 0 1 0 1 ```

#### Sorting and Searching

... Josephus Problem IJosephus Problem IINested Ranges CheckNested Ranges
CountRoom AllocationFactory MachinesTasks and DeadlinesReading Books...

* * *

