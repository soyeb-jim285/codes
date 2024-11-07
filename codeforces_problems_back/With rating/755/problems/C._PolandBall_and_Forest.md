<h1 style='text-align: center;'> C. PolandBall and Forest</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

PolandBall lives in a forest with his family. There are some trees in the forest. Trees are undirected acyclic graphs with *k* vertices and *k* - 1 edges, where *k* is some integer. ## Note

 that one vertex is a valid tree.

There is exactly one relative living in each vertex of each tree, they have unique ids from 1 to *n*. For each Ball *i* we know the id of its most distant relative living on the same tree. If there are several such vertices, we only know the value of the one with smallest id among those.

How many trees are there in the forest?

## Input

The first line contains single integer *n* (1 ≤ *n* ≤ 104) — the number of Balls living in the forest.

The second line contains a sequence *p*1, *p*2, ..., *p**n* of length *n*, where (1 ≤ *p**i* ≤ *n*) holds and *p**i* denotes the most distant from Ball *i* relative living on the same tree. If there are several most distant relatives living on the same tree, *p**i* is the id of one with the smallest id.

It's guaranteed that the sequence *p* corresponds to some valid forest.

Hacking: To hack someone, you should provide a correct forest as a test. The sequence *p* will be calculated according to the forest and given to the solution you try to hack as input. Use the following format:

In the first line, output the integer *n* (1 ≤ *n* ≤ 104) — the number of Balls and the integer *m* (0 ≤ *m* < *n*) — the total number of edges in the forest. Then *m* lines should follow. The *i*-th of them should contain two integers *a**i* and *b**i* and represent an edge between vertices in which relatives *a**i* and *b**i* live. For example, the first sample is written as follows:


```
  
5 3  
1 2  
3 4  
4 5  

```
## Output

You should output the number of trees in the forest where PolandBall lives.

## Interaction

From the technical side, this problem is interactive. However, it should not affect you (except hacking) since there is no interaction.

## Examples

## Input


```
5  
2 1 5 3 3
```
## Output


```
2
```
## Input


```
1  
1  

```
## Output


```
1
```
## Note

In the first sample testcase, possible forest is: 1-2 3-4-5. 

There are 2 trees overall.

In the second sample testcase, the only possible graph is one vertex and no edges. Therefore, there is only one tree.



#### tags 

#1300 #dfs_and_similar #dsu #graphs #interactive #trees 