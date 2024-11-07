<h1 style='text-align: center;'> C. Johnny Solving</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Today is tuesday, that means there is a dispute in JOHNNY SOLVING team again: they try to understand who is Johnny and who is Solving. That's why guys asked Umnik to help them. Umnik gave guys a connected graph with $n$ vertices without loops and multiedges, such that a degree of any vertex is at least $3$, and also he gave a number $1 \leq k \leq n$. Because Johnny is not too smart, he promised to find a simple path with length at least $\frac{n}{k}$ in the graph. In reply, Solving promised to find $k$ simple by vertices cycles with representatives, such that: 

* Length of each cycle is at least $3$.
* Length of each cycle is not divisible by $3$.
* In each cycle must be a representative - vertex, which belongs only to this cycle among all printed cycles.

You need to help guys resolve the dispute, for that you need to find a solution for Johnny: a simple path with length at least $\frac{n}{k}$ ($n$ is not necessarily divided by $k$), or solution for Solving: $k$ cycles that satisfy all the conditions above. If there is no any solution - print $-1$. 

#### Input

The first line contains three integers $n$, $m$ and $k$ ($1 \leq k \leq n \leq 2.5 \cdot 10^5, 1 \leq m \leq 5 \cdot 10^5$)

Next $m$ lines describe edges of the graph in format $v$, $u$ ($1 \leq v, u \leq n$). It's guaranteed that $v \neq u$ and all $m$ pairs are distinct.

It's guaranteed that a degree of each vertex is at least $3$.

#### Output

Print PATH in the first line, if you solve problem for Johnny. In the second line print the number of vertices in the path $c$ ($c \geq \frac{n}{k}$). And in the third line print vertices describing the path in route order.

Print CYCLES in the first line, if you solve problem for Solving. In the following lines describe exactly $k$ cycles in the following format: in the first line print the size of the cycle $c$ ($c \geq 3$). In the second line print the cycle in route order. Also, the first vertex in the cycle must be a representative.

Print $-1$ if there is no any solution. The total amount of printed numbers in the output must be at most $10^6$. It's guaranteed, that if exists any solution then there is a correct output satisfies this restriction.

## Examples

#### Input


```text
4 6 2
1 2
1 3
1 4
2 3
2 4
3 4
```
#### Output


```text
PATH
4
1 2 3 4 
```
#### Input

```text

10 18 2
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
2 3
3 4
2 4
5 6
6 7
5 7
8 9
9 10
8 10

```
#### Output


```text
CYCLES
4
4 1 2 3 
4
7 1 5 6 
```


#### Tags 

#2700 #NOT OK #constructive_algorithms #dfs_and_similar #graphs #math 

## Blogs
- [All Contest Problems](../Codeforces_Round_534_(Div._1).md)
- [Codeforces Round #534](../blogs/Codeforces_Round_534.md)
- [Tutorial](../blogs/Tutorial.md)
