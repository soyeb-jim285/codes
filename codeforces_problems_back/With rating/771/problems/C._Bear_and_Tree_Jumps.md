<h1 style='text-align: center;'> C. Bear and Tree Jumps</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

A tree is an undirected connected graph without cycles. The distance between two vertices is the number of edges in a simple path between them.

Limak is a little polar bear. He lives in a tree that consists of *n* vertices, numbered 1 through *n*.

Limak recently learned how to jump. He can jump from a vertex to any vertex within distance at most *k*.

For a pair of vertices (*s*, *t*) we define *f*(*s*, *t*) as the minimum number of jumps Limak needs to get from *s* to *t*. Your task is to find the sum of *f*(*s*, *t*) over all pairs of vertices (*s*, *t*) such that *s* < *t*.

## Input

The first line of the input contains two integers *n* and *k* (2 ≤ *n* ≤ 200 000, 1 ≤ *k* ≤ 5) — the number of vertices in the tree and the maximum allowed jump distance respectively.

The next *n* - 1 lines describe edges in the tree. The *i*-th of those lines contains two integers *a**i* and *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*) — the indices on vertices connected with *i*-th edge.

It's guaranteed that the given edges form a tree.

## Output

Print one integer, denoting the sum of *f*(*s*, *t*) over all pairs of vertices (*s*, *t*) such that *s* < *t*.

## Examples

## Input


```
6 2  
1 2  
1 3  
2 4  
2 5  
4 6  

```
## Output


```
20  

```
## Input


```
13 3  
1 2  
3 2  
4 2  
5 2  
3 6  
10 6  
6 7  
6 13  
5 8  
5 9  
9 11  
11 12  

```
## Output


```
114  

```
## Input


```
3 5  
2 1  
3 1  

```
## Output


```
3  

```
## Note

In the first sample, the given tree has 6 vertices and it's displayed on the drawing below. Limak can jump to any vertex within distance at most 2. For example, from the vertex 5 he can jump to any of vertices: 1, 2 and 4 (well, he can also jump to the vertex 5 itself).

 ![](images/2f64f096f9b26ecb178744d255b0b317185ae82b.png) There are ![](images/c0295201207e28a36e641d8cf599f45986059e71.png) pairs of vertices (*s*, *t*) such that *s* < *t*. For 5 of those pairs Limak would need two jumps: (1, 6), (3, 4), (3, 5), (3, 6), (5, 6). For other 10 pairs one jump is enough. So, the answer is 5·2 + 10·1 = 20.

In the third sample, Limak can jump between every two vertices directly. There are 3 pairs of vertices (*s* < *t*), so the answer is 3·1 = 3.



#### tags 

#2100 #dfs_and_similar #dp #trees 