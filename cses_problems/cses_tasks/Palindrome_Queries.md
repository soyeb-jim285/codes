![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Palindrome Queries

  * Task
  * Statistics

CSES - Palindrome Queries

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You are given a string that consists of $n$ characters between a–z. The
positions of the string are indexed $1,2,\dots,n$.

Your task is to process $m$ operations of the following types:

  1. Change the character at position $k$ to $x$
  2. Check if the substring from position $a$ to position $b$ is a palindrome

# Input

The first input line has two integers $n$ and $m$: the length of the string
and the number of operations.

The next line has a string that consists of $n$ characters.

Finally, there are $m$ lines that describe the operations. Each line is of the
form "1 $k$ $x$" or "2 $a$ $b$".

# Output

For each operation 2, print YES if the substring is a palindrome and NO
otherwise.

# Constraints

  * $1 \le n, m \le 2 \cdot 10^5$
  * $1 \le k \le n$
  * $1 \le a \le b \le n$

# Example

Input:

``` 7 5 aybabtu 2 3 5 1 3 x 2 3 5 1 5 x 2 3 5 ```

Output:

``` YES NO YES ```

#### String Algorithms

... Minimal RotationLongest PalindromeRequired SubstringPalindrome
QueriesFinding PatternsCounting PatternsPattern PositionsDistinct
Substrings...

* * *

