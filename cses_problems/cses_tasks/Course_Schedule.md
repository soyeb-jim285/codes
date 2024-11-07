![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Course Schedule

  * Task
  * Statistics

CSES - Course Schedule

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

You have to complete $n$ courses. There are $m$ requirements of the form
"course $a$ has to be completed before course $b$". Your task is to find an
order in which you can complete the courses.

# Input

The first input line has two integers $n$ and $m$: the number of courses and
requirements. The courses are numbered $1,2,\dots,n$.

After this, there are $m$ lines describing the requirements. Each line has two
integers $a$ and $b$: course $a$ has to be completed before course $b$.

# Output

Print an order in which you can complete the courses. You can print any valid
order that includes all the courses.

If there are no solutions, print "IMPOSSIBLE".

# Constraints

  * $1 \le n \le 10^5$
  * $1 \le m \le 2 \cdot 10^5$
  * $1 \le a,b \le n$

# Example

Input:

``` 5 3 1 2 3 1 4 5 ```

Output:

``` 3 4 1 5 2 ```

#### Graph Algorithms

... Cycle FindingFlight RoutesRound Trip IICourse ScheduleLongest Flight
RouteGame RoutesInvestigationPlanets Queries I...

* * *

