![CSES](/logo.png?1) __

Login — __Dark mode

### CSES Problem Set

# Download Speed

  * Task
  * Statistics

CSES - Download Speed

  * **Time limit:** 1.00 s
  * **Memory limit:** 512 MB

Consider a network consisting of $n$ computers and $m$ connections. Each
connection specifies how fast a computer can send data to another computer.

Kotivalo wants to download some data from a server. What is the maximum speed
he can do this, using the connections in the network?

# Input

The first input line has two integers $n$ and $m$: the number of computers and
connections. The computers are numbered $1,2,\dots,n$. Computer $1$ is the
server and computer $n$ is Kotivalo's computer.

After this, there are $m$ lines describing the connections. Each line has
three integers $a$, $b$ and $c$: computer $a$ can send data to computer $b$ at
speed $c$.

# Output

Print one integer: the maximum speed Kotivalo can download data.

# Constraints

  * $1 \le n \le 500$
  * $1 \le m \le 1000$
  * $1 \le a,b \le n$
  * $1 \le c \le 10^9$

# Example

Input:

``` 4 5 1 2 3 2 4 2 1 3 4 3 4 5 4 1 3 ```

Output:

``` 6 ```

#### Graph Algorithms

... De Bruijn SequenceTeleporters PathHamiltonian FlightsKnight's TourDownload
SpeedPolice ChaseSchool DanceDistinct Routes

* * *

