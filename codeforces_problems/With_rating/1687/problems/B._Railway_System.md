<h1 style='text-align: center;'> B. Railway System</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

As for the technology in the outside world, it is really too advanced for Gensokyo to even look up to.—Yasaka Kanako, Symposium of Post-mysticismThis is an interactive problem.

Under the direct supervision of Kanako and the Moriya Shrine, the railway system of Gensokyo is finally finished. GSKR (Gensokyo Railways) consists of $n$ stations with $m$ bidirectional tracks connecting them. The $i$-th track has length $l_i$ ($1\le l_i\le 10^6$). Due to budget limits, the railway system may not be connected, though there may be more than one track between two stations.

The value of a railway system is defined as the total length of its all tracks. The maximum (or minimum) capacity of a railway system is defined as the maximum (or minimum) value among all of the currently functional system's [full spanning forest](https://en.wikipedia.org/wiki/Spanning_tree#Spanning_forests).

In brief, full spanning forest of a graph is a spanning forest with the same connectivity as the given graph.

Kanako has a simulator only able to process no more than $2m$ queries. The input of the simulator is a string $s$ of length $m$, consisting of characters 0 and/or 1. The simulator will assume the $i$-th track functional if $s_i=$ 1. The device will then tell Kanako the maximum capacity of the system in the simulated state.

Kanako wants to know the the minimum capacity of the system with all tracks functional with the help of the simulator.

The structure of the railway system is fixed in advance. In other words, the interactor is not adaptive.

### Input

The first and only line of input contains two integers $n,m$ ($2 \leq n \leq 200$, $1\le m \le 500$) — the number of stations and tracks.

## Interaction

Begin the interaction by reading $n,m$.

To make a query, print "? $s$" (without quotes, $s$ is a string of length $m$, consisting of characters 0 and/or 1). Then you should read our response from standard input — the maximum capacity of the system in the simulated state.

If your program has made an invalid query or has run out of tries, the interactor will terminate immediately and your program will get a verdict Wrong answer. 

To give the final answer, print "! $L$" (without the quotes, $L$ is the minimum capacity of the system with all tracks functional). 
## Note

 that giving this answer is not counted towards the limit of $2m$ queries.

After printing a query do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

 Hacks

The first line of input must contain two integers $n,m$ ($2 \leq n \leq 200$, $1\le m \le 500$) — the number of stations and tracks.

The next $m$ lines of input must contain exactly $3$ space-separated integers $u_i$, $v_i$, $l_i$ ($1\le u_i,v_i \le n$, $u_i\ne v_i$, $1 \leq l_i \leq 10^6$) — the endpoints and the length of the $i$-th track.

## Example

### Input


```text
5 4

0

5

9

7
```
#Output
```text
? 0000

? 1110

? 1111

? 1101

! 7
```
## Note

Here is the graph of the example, satisfying $l_i=i$.

 ![](images/e46a3a362b99c009e9208db663714f706d07696c.png) 

#### Tags 

#1700 #NOT OK #constructive_algorithms #graphs #greedy #interactive #sortings 

## Blogs
- [All Contest Problems](../Codeforces_Round_796_(Div._1).md)
- [Codeforces Round #796 (en)](../blogs/Codeforces_Round_796_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
