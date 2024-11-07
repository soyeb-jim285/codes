![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# String Functions

  * Task
  * Statistics

CSES - String Functions

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

We consider a string of $n$ characters, indexed $1,2,\dots,n$. Your task is to
calculate all values of the following functions:

  * $z(i)$ denotes the maximum length of a substring that begins at position $i$ and is a prefix of the string. In addition, $z(1)=0$.
  * $\pi(i)$ denotes the maximum length of a substring that ends at position $i$, is a prefix of the string, and whose length is at most $i-1$.

Note that the function $z$ is used in the Z-algorithm, and the function $\pi$
is used in the KMP algorithm.

# Input

The only input line has a string of length $n$. Each character is between a–z.

# Output

Print two lines: first the values of the $z$ function, and then the values of
the $\pi$ function.

# Constraints

  * $1 \le n \le 10^6$

# Example

Input:

``` abaabca ```

Output:

``` 0 0 1 2 0 0 1 0 0 1 1 2 0 1 ```

#### String Algorithms

... Counting PatternsPattern PositionsDistinct SubstringsRepeating
SubstringString FunctionsSubstring Order ISubstring Order IISubstring
Distribution

* * *

