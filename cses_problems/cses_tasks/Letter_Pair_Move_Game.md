![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Letter Pair Move Game

  * Task
  * Statistics

CSES - Letter Pair Move Game

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are $2n$ boxes in a line. Two adjacent boxes are empty, and all other
boxes have a letter "A" or "B". Both letters appear in exactly $n-1$ boxes.

Your task is to move the letters so that all letters "A" appear before any
letter "B". On each turn you can choose any two adjacent boxes that have a
letter and move the letters to the two adjacent empty boxes, preserving their
order.

It can be proven that either there is a solution that consists of at most
$10n$ turns or there are no solutions.

# Input

The first line has an integer $n$: there are $2n$ boxes.

The second line has a string of $2n$ characters which describes the starting
position. Each character is "A", "B" or "." (empty box).

# Output

First print an integer $k$: the number of turns. After this, print $k$ lines
that describe the moves. You can print any solution, as long as $k \le 1000$.

If there are no solutions, print only "-1".

# Constraints

  * $1 \le n \le 100$

# Example 1

Input:

``` 3 AB..BA ```

Output:

``` 2 ABBA.. A..ABB ```

# Example 2

Input:

``` 3 ABAB.. ```

Output:

``` -1 ```

#### Additional Problems

... Xor PyramidWriting NumbersString TransformLetter Pair Move GameMaximum
Building ISorting MethodsCyclic ArrayList of Sums...

* * *

