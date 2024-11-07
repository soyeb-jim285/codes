<h1 style='text-align: center;'> F. Connectivity Addicts</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

This is an interactive problem.

Given a simple undirected graph with $n$ vertices numbered from $1$ to $n$, your task is to color all the vertices such that for every color $c$, the following conditions hold: 

1. The set of vertices with color $c$ is connected;
2. $s_c \leq n_c^2$, where $n_c$ is the number of vertices with color $c$, and $s_c$ is the sum of degrees of vertices with color $c$.

 It can be shown that there always exists a way to color all the vertices such that the above conditions hold. Initially, you are only given the number $n$ of vertices and the degree of each vertex. 

In each query, you can choose a vertex $u$. As a response, you will be given the $k$-th edge incident to $u$, if this is the $k$-th query on vertex $u$. 

You are allowed to make at most $n$ queries.

An undirected graph is simple if it does not contain multiple edges or self-loops.

The degree of a vertex is the number of edges incident to it. 

A set $S$ of vertices is connected if for every two different vertices $u, v \in S$, there is a path, which only passes through vertices in $S$, that connects $u$ and $v$. That is, there is a sequence of edges $(u_1, v_1), (u_2, v_2), \dots, (u_k, v_k)$ with $k \geq 1$ such that 

1. $u_1 = u$, $v_k = v$, and $v_i = u_{i+1}$ for every $1 \leq i < k$; and
2. $u_k \in S$ and $v_k \in S$ for every $1 \leq i \leq k$.

 Especially, a set containing only one vertex is connected. 
## Interaction

Each test contains multiple test cases. The first line contains an integer $t$ ($1 \leq t \leq 1000$) — the number of test cases. The following lines contain the description and the interactive section of each test case.

For each test case, you begin the interaction by reading an integer $n$ ($1\le n \le 1000$) in the first line, indicating the number of vertices in the graph.

The second line contains $n$ integers $d_1, d_2, \dots, d_n$ ($0 \leq d_i \leq n - 1$), where $d_i$ is the degree of vertex $i$. 

To make a query on vertex $u$ ($1 \leq u \leq n$), you should output 

* "? $u$"

 in a separate line. If this is the $k$-th query on vertex $u$, vertex $e_{u, k}$ will be given in the next separate line, where $\left(u, e_{u, k}\right)$ is the $k$-th edge incident to vertex $u$. In case of $k > d_u$, define $e_{u, k} = -1$. You should make no more than $n$ "?" queries.To give the answer, you should output 

* "! $c_1$ $c_2$ $\dots$ $c_n$"

 in a separate line, where $c_i$ ($1 \leq c_i \leq n$) is the color of vertex $i$. After that, your program should continue to the next test case, or terminate if this is the last test case. It is guaranteed that the graph is a simple undirected graph.

It is guaranteed that the sum of $n$ over all test cases does not exceed $1000$.

In case your query format is invalid, or you have made more than $n$ "?" queries, you will receive Wrong Answer verdict. 

After printing a query, do not forget to output end of line and flush the output. Otherwise, you will get Idleness limit exceeded. To do this, use:

* fflush(stdout) or cout.flush() in C++;
* System.out.flush() in Java;
* flush(output) in Pascal;
* stdout.flush() in Python;
* see documentation for other languages.

Hack Format

The first line of the hack contains an integer $t$ ($1 \leq t \leq 1000$), indicating the number of test cases. The following lines contain the description of each test case.

The first line of each test case contains an integer $n$ ($1 \leq n \leq 1000$), indicating the number of vertices in the graph. 

Then $n$ lines follow. The $i$-th line contains an integer $d_i$ ($0 \leq d_i \leq n - 1$), indicating the degree of vertex $i$, and then $d_i$ distinct integers $e_{i,1}, e_{i,2}, \dots, e_{i,d_i}$ ($1 \leq e_{i, j} \leq n$ and $e_{i,j} \neq i$), where $\left(i, e_{i,j}\right)$ is the $j$-th edge incident to vertex $i$.

It should be guaranteed that the graph is a simple undirected graph.

It should be guaranteed that the sum of $n$ over all test cases does not exceed $1000$.

## Example

#Input
```text
1
5
2 2 2 2 0

2

4

2

4
```
#Output
```text



? 1

? 1

? 3

? 3

! 1 1 2 2 3
```
## Note

In the example, there is only one test case. 

In the test case, there are $n = 5$ vertices with vertices $1, 2, 3, 4$ of degree $2$ and vertex $5$ of degree $0$. It is obvious that vertex $5$ is isolated, i.e., it does not connect to any other vertices. 

A possible interaction is shown in the sample input and output, where $4$ "?" queries are made on vertex $1$ twice and vertex $3$ twice. According to the responses to these queries, we know that each of vertex $1$ and vertex $3$ connects to two vertices $2$ and $4$. 

A possible solution is shown in the sample output, where vertex $1$ and vertex $2$ are colored by $1$, vertex $3$ and vertex $4$ are colored by $2$, and vertex $5$ is colored by $3$. It can be seen that this solution satisfies the required conditions as follows. 

* For color $c = 1$, vertex $1$ and vertex $2$ are connected. Moreover, $n_1 = 2$ and $s_1 = d_1 + d_2 = 2 + 2 = 4 \leq n_1^2 = 2^2 = 4$;
* For color $c = 2$, vertex $3$ and vertex $4$ are connected. Moreover, $n_2 = 2$ and $s_2 = d_3 + d_4 = 2 + 2 = 4 \leq n_2^2 = 2^2 = 4$;
* For color $c = 3$, there is only one vertex (vertex $5$) colored by $3$. Moreover, $n_3 = 1$ and $s_3 = d_5 = 0 \leq n_3^2 = 1^2 = 1$.


#### Tags 

#2400 #NOT OK #constructive_algorithms #dsu #graphs #greedy #interactive #shortest_paths #trees 

## Blogs
- [All Contest Problems](../Codeforces_Global_Round_22.md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
