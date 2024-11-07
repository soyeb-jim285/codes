![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Subarray Squares

  * Task
  * Statistics

CSES - Subarray Squares

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Given an array of $n$ elements, your task is to divide into $k$ subarrays. The
cost of each subarray is the square of the sum of the values in the subarray.
What is the minimum total cost if you act optimally?

# Input

The first input line has two integers $n$ and $k$: the array elements and the
number of subarrays. The array elements are numbered $1,2,\dots,n$.

The second line has $n$ integers $x_1,x_2,\dots,x_n$: the contents of the
array.

# Output

Print one integer: the minimum total cost.

# Constraints

  * $1 \le k \le n \le 3000$
  * $1 \le x_i \le 10^5$

# Example

Input:

``` 8 3 2 3 1 2 2 3 4 1 ```

Output:

``` 110 ```

Explanation: An optimal solution is $[2,3,1]$, $[2,2,3]$, $[4,1]$, whose cost
is $(2+3+1)^2+(2+2+3)^2+(4+1)^2=110$.

#### Advanced Techniques

... Eulerian SubgraphsMonster Game IMonster Game IISubarray SquaresHouses and
SchoolsKnuth DivisionApples and BananasOne Bit Positions...

* * *

