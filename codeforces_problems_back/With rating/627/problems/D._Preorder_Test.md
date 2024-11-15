<h1 style='text-align: center;'> D. Preorder Test</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

For his computer science class, Jacob builds a model tree with sticks and balls containing *n* nodes in the shape of a tree. Jacob has spent *a**i* minutes building the *i*-th ball in the tree.

Jacob's teacher will evaluate his model and grade Jacob based on the effort he has put in. However, she does not have enough time to search his whole tree to determine this; Jacob knows that she will examine the first *k* nodes in a DFS-order traversal of the tree. She will then assign Jacob a grade equal to the minimum *a**i* she finds among those *k* nodes.

Though Jacob does not have enough time to rebuild his model, he can choose the root node that his teacher starts from. Furthermore, he can rearrange the list of neighbors of each node in any order he likes. Help Jacob find the best grade he can get on this assignment.

A DFS-order traversal is an ordering of the nodes of a rooted tree, built by a recursive DFS-procedure initially called on the root of the tree. When called on a given node *v*, the procedure does the following: 

1. Print *v*.
2. Traverse the list of neighbors of the node *v* in order and iteratively call DFS-procedure on each one. Do not call DFS-procedure on node *u* if you came to node *v* directly from *u*.
## Input

The first line of the input contains two positive integers, *n* and *k* (2 ≤ *n* ≤ 200 000, 1 ≤ *k* ≤ *n*) — the number of balls in Jacob's tree and the number of balls the teacher will inspect.

The second line contains *n* integers, *a**i* (1 ≤ *a**i* ≤ 1 000 000), the time Jacob used to build the *i*-th ball.

Each of the next *n* - 1 lines contains two integers *u**i*, *v**i* (1 ≤ *u**i*, *v**i* ≤ *n*, *u**i* ≠ *v**i*) representing a connection in Jacob's tree between balls *u**i* and *v**i*.

## Output

Print a single integer — the maximum grade Jacob can get by picking the right root of the tree and rearranging the list of neighbors.

## Examples

## Input


```
5 3  
3 6 1 4 2  
1 2  
2 4  
2 5  
1 3  

```
## Output


```
3  

```
## Input


```
4 2  
1 5 5 5  
1 2  
1 3  
1 4  

```
## Output


```
1  

```
## Note

In the first sample, Jacob can root the tree at node 2 and order 2's neighbors in the order 4, 1, 5 (all other nodes have at most two neighbors). The resulting preorder traversal is 2, 4, 1, 3, 5, and the minimum *a**i* of the first 3 nodes is 3.

In the second sample, it is clear that any preorder traversal will contain node 1 as either its first or second node, so Jacob cannot do better than a grade of 1.



#### tags 

#2600 #binary_search #dfs_and_similar #dp #graphs #greedy #trees 