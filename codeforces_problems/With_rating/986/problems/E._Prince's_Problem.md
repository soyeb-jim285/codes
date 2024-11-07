<h1 style='text-align: center;'> E. Prince's Problem</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Let the main characters of this problem be personages from some recent movie. New Avengers seem to make a lot of buzz. I didn't watch any part of the franchise and don't know its heroes well, but it won't stop me from using them in this problem statement. So, Thanos and Dr. Strange are doing their superhero and supervillain stuff, but then suddenly they stumble across a regular competitive programming problem.

You are given a tree with $n$ vertices.

In each vertex $v$ there is positive integer $a_{v}$.

You have to answer $q$ queries.

Each query has a from $u$ $v$ $x$.

You have to calculate $\prod_{w \in P} gcd(x, a_{w}) \mod (10^{9} + 7)$, where $P$ is a set of vertices on path from $u$ to $v$. In other words, you are to calculate the product of $gcd(x, a_{w})$ for all vertices $w$ on the path from $u$ to $v$. As it might be large, compute it modulo $10^9+7$. Here $gcd(s, t)$ denotes the greatest common divisor of $s$ and $t$.

Note that the numbers in vertices do not change after queries.

I suppose that you are more interested in superhero business of Thanos and Dr. Strange than in them solving the problem. So you are invited to solve this problem instead of them.

#### Input

In the first line of input there is one integer $n$ ($1 \le n \le 10^{5}$) — the size of the tree.

In the next $n-1$ lines the edges of the tree are described. The $i$-th edge is described with two integers $u_{i}$ and $v_{i}$ ($1 \le u_{i}, v_{i} \le n$) and it connects the vertices $u_{i}$ and $v_{i}$. It is guaranteed that graph with these edges is a tree.

In the next line there are $n$ integers $a_1, a_2, \ldots, a_n$ ($1 \le a_{v} \le 10^{7}$).

In the next line there is one integer $q$ ($1 \le q \le 10^{5}$) — the number of queries.

And in the next $q$ lines the queries are described. Each query is described with three integers $u_{i}$, $v_{i}$ and $x_{i}$ ($1 \le u_{i}, v_{i} \le n$, $1 \le x_{i} \le 10^{7}$).

#### Output

Print $q$ numbers — the answers to the queries in the order they are given in the input. Print each answer modulo $10^9+7 = 1000000007$. Print each number on a separate line.

## Examples

#### Input


```text
4  
1 2  
1 3  
1 4  
6 4 9 5  
3  
2 3 6  
2 3 2  
3 4 7  

```
#### Output


```text
36  
4  
1  

```
#### Input


```text
6  
1 2  
2 3  
2 4  
1 5  
5 6  
100000 200000 500000 40000 800000 250000  
3  
3 5 10000000  
6 2 3500000  
4 1 64000  

```
#### Output


```text
196000  
12250  
999998215  

```


#### Tags 

#2800 #NOT OK #brute_force #data_structures #math #number_theory #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_485_(Div._1).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial](../blogs/Tutorial.md)
