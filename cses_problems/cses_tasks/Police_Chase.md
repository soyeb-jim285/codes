![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Police Chase

  * Task
  * Statistics

CSES - Police Chase

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Kaaleppi has just robbed a bank and is now heading to the harbor. However, the
police wants to stop him by closing some streets of the city.

What is the minimum number of streets that should be closed so that there is
no route between the bank and the harbor?

# Input

The first input line has two integers $n$ and $m$: the number of crossings and
streets. The crossings are numbered $1,2,\dots,n$. The bank is located at
crossing $1$, and the harbor is located at crossing $n$.

After this, there are $m$ lines that describing the streets. Each line has two
integers $a$ and $b$: there is a street between crossings $a$ and $b$. All
streets are two-way streets, and there is at most one street between two
crossings.

# Output

First print an integer $k$: the minimum number of streets that should be
closed. After this, print $k$ lines describing the streets. You can print any
valid solution.

# Constraints

  * $2 \le n \le 500$
  * $1 \le m \le 1000$
  * $1 \le a,b \le n$

# Example

Input:

``` 4 5 1 2 1 3 2 3 3 4 1 4 ```

Output:

``` 2 3 4 1 4 ```

#### Graph Algorithms

... De Bruijn SequenceTeleporters PathHamiltonian FlightsKnight's TourDownload
SpeedPolice ChaseSchool DanceDistinct Routes

* * *

