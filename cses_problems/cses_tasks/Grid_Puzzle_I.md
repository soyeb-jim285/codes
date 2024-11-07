![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Grid Puzzle I

  * Task
  * Statistics

CSES - Grid Puzzle I

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There is an $n \times n$ grid, and your task is to choose from each row and
column some number of squares. How can you do that?

# Input

The first input line has an integer $n$: the size of the grid. The rows and
columns are numbered $1,2,\dots,n$.

The next line has $n$ integers $a_1,a_2,\ldots,a_n$: You must choose exactly
$a_i$ squares from the $i$th row.

The las line has $n$ integers $b_1,b_2,\ldots,b_n$: You must choose exactly
$b_j$ squares from the $j$th column.

# Output

Print $n$ lines describing which squares you choose (`X` means that you choose
a square, `.` means that you don't choose it). You can print any valid
solution.

If it is not possible to satisfy the conditions print only $-1$.

# Constraints

  * $1 \le n \le 50$
  * $0 \le a_i \le n$
  * $0 \le b_j \le n$

# Example

Input:

``` 5 0 1 3 2 0 1 2 2 0 1 ```

Output:

``` ..... ..X.. .XX.X XX... ..... ```

#### Additional Problems

... Removing Digits IICoin ArrangementCounting BishopsGrid Puzzle IGrid Puzzle
IIEmpty StringGrid PathsBit Substrings...

* * *

