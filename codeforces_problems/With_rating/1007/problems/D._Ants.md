<h1 style='text-align: center;'> D. Ants</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 768 megabytes</h5>

There is a tree with $n$ vertices. There are also $m$ ants living on it. Each ant has its own color. The $i$-th ant has two favorite pairs of vertices: ($a_i, b_i$) and ($c_i, d_i$). You need to tell if it is possible to paint the edges of the tree in $m$ colors so that every ant will be able to walk between vertices from one of its favorite pairs using only edges of his color; if it is possible, you need to print which pair every ant should use.

#### Input

The first line contains a single integer $n$ ($2 \leq n \leq 10^5$) — the number of vertices.

Each of the next $n-1$ lines contains two integers $u_i$ and $v_i$ ($1 \leq u_i, v_i \leq n$), meaning that there is an edge between vertices $u_i$ and $v_i$.

The next line contains a single integer $m$ ($1 \leq m \leq 10^4$) — the number of ants.

Each of the next $m$ lines contains four integers $a_i$, $b_i$, $c_i$, and $d_i$ ($1 \leq a_i, b_i, c_i, d_i \leq n$, $a_i \neq b_i, c_i \neq d_i$), meaning that pairs ($a_i$, $b_i$) and ($c_i$, $d_i$) are favorite for the $i$-th ant.

#### Output

Print "NO" (without quotes) if the wanted painting is impossible.

Otherwise, print "YES" (without quotes). Print $m$ lines. On the $i$-th line, print $1$ if the $i$-th ant will use the first pair and $2$ otherwise. If there are multiple answers, print any.

## Examples

#### Input


```text
6  
1 2  
3 1  
4 1  
5 2  
6 2  
3  
2 6 3 4  
1 6 6 5  
1 4 5 2  

```
#### Output


```text
YES  
2  
1  
2  

```
#### Input


```text
5  
1 2  
1 3  
1 4  
1 5  
2  
2 3 4 5  
3 4 5 2  

```
#### Output


```text
NO  

```
## Note

In the sample, the second and the third edge should be painted in the first color, the first and the fifth should be painted in the second color, and the fourth should be painted in the third color.



#### Tags 

#3200 #NOT OK #2-sat #data_structures #trees 

## Blogs
- [All Contest Problems](../Codeforces_Round_497_(Div._1).md)
- [Announcement](../blogs/Announcement.md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
