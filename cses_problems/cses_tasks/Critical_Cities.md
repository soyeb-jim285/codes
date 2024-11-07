![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Critical Cities

  * Task
  * Statistics

CSES - Critical Cities

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

There are $n$ cities and $m$ flight connections between them. A city is called
a _critical city_ if it appears on every route from a city to another city.

Your task is to find all critical cities from Syrjälä to Lehmälä.

# Input

The first input line has two integers $n$ and $m$: the number of cities and
flights. The cities are numbered $1,2,\dots,n$. City $1$ is Syrjälä, and city
$n$ is Lehmälä.

Then, there are $m$ lines describing the connections. Each line has two
integers $a$ and $b$: there is a flight from city $a$ to city $b$. All flights
are one-way.

You may assume that there is a route from Syrjälä to Lehmälä.

# Output

First print an integer $k$: the number of critical cities. After this, print
$k$ integers: the critical cities in increasing order.

# Constraints

  * $2 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 5 5 1 2 2 3 2 4 3 5 4 5 ```

Output:

``` 3 1 2 5 ```

#### Additional Problems

... Binary SubsequencesTree Isomorphism ICounting SequencesCritical
CitiesSchool ExcursionCoin GridRobot PathProgrammers and Artists...

* * *

