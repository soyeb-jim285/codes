<h1 style='text-align: center;'> C. Dušan's Railway</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

As you may already know, Dušan is keen on playing with railway models. He has a big map with cities that are connected with railways. His map can be seen as a graph where vertices are cities and the railways connecting them are the edges. So far, the graph corresponding to his map is a tree. As you already know, a tree is a connected acyclic undirected graph.

He is curious to find out whether his railway can be optimized somehow. He wants to add so-called shortcuts, which are also railways connecting pairs of cities. This shortcut will represent the railways in the unique path in the tree between the pair of cities it connects. Since Dušan doesn't like repeating the railways, he has also defined good paths in his newly obtained network (notice that after adding the shortcuts, his graph is no more a tree). He calls a path good, if no edge appears more than once, either as a regular railway edge or as an edge represented by some shortcut (Every shortcut in a good path has length 1, but uses up all the edges it represents - they can't appear again in that path). Having defined good paths, he defines good distance between two cities to be the length of the shortest good path between them. Finally, the shortcutting diameter of his network is the largest good distance between any two cities.

Now he is curious to find out whether it is possible to achieve shortcutting diameter less or equal than $k$, while adding as few shortcuts as possible.

Your solution should add no more than $\mathbf{10 \cdot n}$ shortcuts.

### Input

The first line in the standard input contains an integer $n$ ($1 \le n \le 10^4$), representing the number of the cities in Dušan's railway map, and an integer k ($3 \le k \le n$) representing the shortcutting diameter that he wants to achieve.

Each of the following $n - 1$ lines will contain two integers $u_i$ and $v_i$ ($1 \le u_i, v_i \le n, u_i \neq v_i$), meaning that there is a railway between cities $u_i$ and $v_i$.

### Output

The first line of the output should contain a number $t$ representing the number of the shortcuts that were added.

Each of the following $t$ lines should contain two integers $u_i$ and $v_i$, signifying that a shortcut is added between cities $u_i$ and $v_i$.

## Example

### Input


```text
10 3
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
```
### Output


```text
8
3 7
3 5
3 6
3 1
7 9
7 10
7 4
7 5
```
## Note

Notice that adding a shortcut between all cities and city 1 will make a graph theoretic diameter become 2. On the other hand, the paths obtained that way might not be good, since some of the edges might get duplicated. In the example, adding a shortcut between all cities and city 1 doesn't create a valid solution, because for cities 5 and 10 the path that uses shortcuts 5-1 and 1-10 is not valid because it uses edges 1-2, 2-3, 3-4, 4-5 twice.



#### Tags 

#3500 #NOT OK #divide_and_conquer #graphs #trees 

## Blogs
- [All Contest Problems](../Bubble_Cup_13_-_Finals_[Online_Mirror,_unrated,_Div._1].md)
- [Announcement (en)](../blogs/Announcement_(en).md)
