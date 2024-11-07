![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# School Excursion

  * Task
  * Statistics

CSES - School Excursion

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

A group of $n$ children are coming to Helsinki. There are two possible
attractions: a child can visit either Korkeasaari (zoo) or Linnanmäki
(amusement park).

There are $m$ pairs of children who want to visit the same attraction. Your
task is to find all possible alternatives for the number of children that will
visit Korkeasaari. The children's wishes have to be taken into account.

# Input

The first input line has two integers $n$ and $m$: the number of children and
their wishes. The children are numbered $1,2,\dots,n$.

After this, there are $m$ lines describing the children's wishes. Each line
has two integers $a$ and $b$: children $a$ and $b$ want to visit the same
attraction.

# Output

Print a bit string of length $n$ where a one-bit at index $i$ indicates that
it is possible that exactly $i$ children visit Korkeasaari (the bit string is
to be considered one-indexed).

# Constraints

  * $1 \le n \le 10^5$
  * $0 \le m \le 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 5 3 1 2 2 3 1 5 ```

Output:

``` 10011 ```

Explanation: The number of children visiting Korkeasaari can be $1$, $4$ or
$5$.

#### Additional Problems

... Tree Isomorphism ICounting SequencesCritical CitiesSchool ExcursionCoin
GridRobot PathProgrammers and ArtistsCourse Schedule II...

* * *

