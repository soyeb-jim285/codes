<h1 style='text-align: center;'> D. Full Binary Tree Queries</h1>

<h5 style='text-align: center;'>time limit per test: 4 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a full binary tree having infinite levels.

Each node has an initial value. If a node has value *x*, then its left child has value 2·*x* and its right child has value 2·*x* + 1. 

The value of the root is 1. 

You need to answer *Q* queries. 

There are 3 types of queries: 

1. Cyclically shift the values of all nodes on the same level as node with value *X* by *K* units. (The values/nodes of any other level are not affected).
2. Cyclically shift the nodes on the same level as node with value *X* by *K* units. (The subtrees of these nodes will move along with them).
3. Print the value of every node encountered on the simple path from the node with value *X* to the root.

Positive *K* implies right cyclic shift and negative *K* implies left cyclic shift. 

It is guaranteed that atleast one type 3 query is present.

## Input

The first line contains a single integer *Q* (1 ≤ *Q* ≤ 105).

Then *Q* queries follow, one per line: 

* Queries of type 1 and 2 have the following format: *T* *X* *K* (1 ≤ *T* ≤ 2; 1 ≤ *X* ≤ 1018; 0 ≤ |*K*| ≤ 1018), where *T* is type of the query.
* Queries of type 3 have the following format: 3 *X* (1 ≤ *X* ≤ 1018).
## Output

For each query of type 3, print the values of all nodes encountered in descending order.

## Examples

## Input


```
5  
3 12  
1 2 1  
3 12  
2 4 -1  
3 8  

```
## Output


```
12 6 3 1   
12 6 2 1   
8 4 2 1   

```
## Input


```
5  
3 14  
1 5 -3  
3 14  
1 3 1  
3 14  

```
## Output


```
14 7 3 1   
14 6 3 1   
14 6 2 1   

```
## Note

Following are the images of the first 4 levels of the tree in the first test case:

Original: 

 ![](images/9bc9b00a4be0824f3ab3a052f7c55ae5ad4a1bae.png)  After query 1 2 1: 

 ![](images/c525b5916b994c6630d3d0abf7d051fdd9421292.png)  After query 2 4 -1: 

 ![](images/5954801d203dc3c0c4bf27e9bf96656f9946792b.png) 

#### tags 

#2100 #brute_force #implementation #trees 