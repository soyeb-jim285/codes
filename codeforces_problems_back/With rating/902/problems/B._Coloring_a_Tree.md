<h1 style='text-align: center;'> B. Coloring a Tree</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You are given a rooted tree with *n* vertices. The vertices are numbered from 1 to *n*, the root is the vertex number 1.

Each vertex has a color, let's denote the color of vertex *v* by *c**v*. Initially *c**v* = 0.

You have to color the tree into the given colors using the smallest possible number of steps. On each step you can choose a vertex *v* and a color *x*, and then color all vectices in the subtree of *v* (including *v* itself) in color *x*. In other words, for every vertex *u*, such that the path from root to *u* passes through *v*, set *c**u* = *x*.

It is guaranteed that you have to color each vertex in a color different from 0.

You can learn what a rooted tree is using the link: <https://en.wikipedia.org/wiki/Tree_(graph_theory)>.

## Input

The first line contains a single integer *n* (2 ≤ *n* ≤ 104) — the number of vertices in the tree.

The second line contains *n* - 1 integers *p*2, *p*3, ..., *p**n* (1 ≤ *p**i* < *i*), where *p**i* means that there is an edge between vertices *i* and *p**i*.

The third line contains *n* integers *c*1, *c*2, ..., *c**n* (1 ≤ *c**i* ≤ *n*), where *c**i* is the color you should color the *i*-th vertex into.

It is guaranteed that the given graph is a tree. 

## Output

Print a single integer — the minimum number of steps you have to perform to color the tree into given colors.

## Examples

## Input


```
6  
1 2 2 1 5  
2 1 1 1 1 1  

```
## Output


```
3  

```
## Input


```
7  
1 1 2 3 1 4  
3 3 1 1 1 2 3  

```
## Output


```
5  

```
## Note

The tree from the first sample is shown on the picture (numbers are vetices' indices):

![](images/10324ccdc37f95343acc4f3c6050d8c334334ffa.png)

On first step we color all vertices in the subtree of vertex 1 into color 2 (numbers are colors):

![](images/1c7bb267e2c1a006132248a43121400189309e2f.png)

On seond step we color all vertices in the subtree of vertex 5 into color 1:

![](images/2201a6d49b89ba850ff0d0bdcbb3f8e9dd3871a8.png)

On third step we color all vertices in the subtree of vertex 2 into color 1:

![](images/6fa977fcdebdde94c47695151e0427b33d0102c5.png)

The tree from the second sample is shown on the picture (numbers are vetices' indices):

![](images/d70f9ae72a2ed429dd6531cac757e375dd3c953d.png)

On first step we color all vertices in the subtree of vertex 1 into color 3 (numbers are colors):

![](images/7289e8895d0dd56c47b6b17969b9cf77b36786b5.png)

On second step we color all vertices in the subtree of vertex 3 into color 1:

![](images/819001df7229138db3a407713744d1e3be88b64e.png)

On third step we color all vertices in the subtree of vertex 6 into color 2:

![](images/80ebbd870a0a339636a21b9acdaf9de046458b43.png)

On fourth step we color all vertices in the subtree of vertex 4 into color 1:

![](images/ed836aa723ac0176abde4e32988e3ac205014e93.png)

On fith step we color all vertices in the subtree of vertex 7 into color 3:

![](images/8132909e11b41c27b8df2f0b0c10bc841f35e58a.png)



#### tags 

#1200 #dfs_and_similar #dsu #greedy 