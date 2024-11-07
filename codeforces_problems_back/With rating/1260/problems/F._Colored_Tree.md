<h1 style='text-align: center;'> F. Colored Tree</h1>

<h5 style='text-align: center;'>time limit per test: 2.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You're given a tree with $n$ vertices. The color of the $i$-th vertex is $h_{i}$.

The value of the tree is defined as $\sum\limits_{h_{i} = h_{j}, 1 \le i < j \le n}{dis(i,j)}$, where $dis(i,j)$ is the number of edges on the shortest path between $i$ and $j$. 

The color of each vertex is lost, you only remember that $h_{i}$ can be any integer from $[l_{i}, r_{i}]$(inclusive). You want to calculate the sum of values of all trees meeting these conditions modulo $10^9 + 7$ (the set of edges is fixed, but each color is unknown, so there are $\prod\limits_{i = 1}^{n} (r_{i} - l_{i} + 1)$ different trees).

## Input

The first line contains one integer $n$ ($2 \le n \le 10^5$) — the number of vertices.

Then $n$ lines follow, each line contains two integers $l_i$ and $r_i$ ($1 \le l_i \le r_i \le 10^5$) denoting the range of possible colors of vertex $i$.

Then $n - 1$ lines follow, each containing two integers $u$ and $v$ ($1 \le u, v \le n$, $u \ne v$) denoting an edge of the tree. It is guaranteed that these edges form a tree.

## Output

Print one integer — the sum of values of all possible trees, taken modulo $10^9 + 7$.

## Example

## Input


```

4
1 1
1 2
1 1
1 2
1 2
1 3
3 4

```
## Output


```

22

```
## Note

In the first example there are four different ways to color the tree (so, there are four different trees):

* a tree with vertices colored as follows: $\lbrace 1,1,1,1 \rbrace$. The value of this tree is $dis(1,2)+dis(1,3)+dis(1,4)+dis(2,3)+dis(2,4)+dis(3,4) = 10$;
* a tree with vertices colored as follows: $\lbrace 1,2,1,1 \rbrace$. The value of this tree is $dis(1,3)+dis(1,4)+dis(3,4)=4$;
* a tree with vertices colored as follows: $\lbrace 1,1,1,2 \rbrace$. The value of this tree is $dis(1,2)+dis(1,3)+dis(2,3)=4$;
* a tree with vertices colored as follows: $\lbrace 1,2,1,2 \rbrace$. The value of this tree is $dis(1,3)+dis(2,4)=4$.

Overall the sum of all values is $10+4+4+4=22$.



#### tags 

#2700 #data_structures #trees 