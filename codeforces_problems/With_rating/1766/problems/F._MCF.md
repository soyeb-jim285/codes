<h1 style='text-align: center;'> F. MCF</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You are given a graph consisting of $n$ vertices and $m$ directed arcs. The $i$-th arc goes from the vertex $x_i$ to the vertex $y_i$, has capacity $c_i$ and weight $w_i$. No arc goes into the vertex $1$, and no arc goes from the vertex $n$. There are no cycles of negative weight in the graph (it is impossible to travel from any vertex to itself in such a way that the total weight of all arcs you go through is negative).

You have to assign each arc a flow (an integer between $0$ and its capacity, inclusive). For every vertex except $1$ and $n$, the total flow on the arcs going to this vertex must be equal to the total flow on the arcs going from that vertex. Let the flow on the $i$-th arc be $f_i$, then the cost of the flow is equal to $\sum \limits_{i = 1}^{m} f_i w_i$. You have to find a flow which minimizes the cost.

Sounds classical, right? Well, we have some additional constraints on the flow on every edge:

* if $c_i$ is even, $f_i$ must be even;
* if $c_i$ is odd, $f_i$ must be odd.

Can you solve this problem?

###### Input

The first line contains two integers $n$ and $m$ ($2 \le n \le 100$; $1 \le m \le 200$).

Then $m$ lines follow. The $i$-th of them contains four integers $x_i$, $y_i$, $c_i$, and $w_i$ ($1 \le x_i \le n - 1$; $2 \le y_i \le n$; $x_i \ne y_i$; $1 \le c_i \le 100$; $-100 \le w_i \le 100$). These integers describe the $i$-th arc.

Additional constraints on the input:

* there are no negative cycles in the graph.
###### Output

If a flow satisfying all of the constraints does not exist, print Impossible.

Otherwise, print two lines:

* the first line should contain one word Possible;
* the second line should contain $m$ integers $f_1, f_2, \dots, f_m$.

If there are multiple answers, print any of them. Note that the cost of the flow should be minimized.

## Examples

###### Input


```text
3 3
1 2 3 -10
1 2 3 -15
2 3 2 0
```
###### Output


```text
Possible
1 1 2
```
###### Input


```text
3 3
1 2 3 -10
1 2 3 -15
2 3 3 0
```
###### Output


```text
Impossible
```
###### Input


```text
3 3
1 2 3 -10
1 2 3 -15
2 3 4 0
```
###### Output


```text
Possible
1 3 4
```
###### Input


```text
6 7
5 6 9 -40
1 2 3 -10
1 4 5 20
4 5 7 30
2 5 1 -15
1 3 3 5
3 5 3 0
```
###### Output


```text
Possible
5 1 1 1 1 3 3
```


#### Tags 

#2800 #NOT OK #flows 

## Blogs
- [All Contest Problems](../Educational_Codeforces_Round_139_(Rated_for_Div._2).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial](../blogs/Tutorial.md)
