<h1 style='text-align: center;'> E. Hemose on the Tree</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

After the last regional contest, Hemose and his teammates finally qualified to the ICPC World Finals, so for this great achievement and his love of trees, he gave you this problem as the name of his team "Hemose 3al shagra" (Hemose on the tree).

You are given a tree of $n$ vertices where $n$ is a power of $2$. You have to give each node and edge an integer value in the range $[1,2n -1]$ (inclusive), where all the values are distinct.

After giving each node and edge a value, you should select some root for the tree such that the maximum cost of any simple path starting from the root and ending at any node or edge is minimized.

The cost of the path between two nodes $u$ and $v$ or any node $u$ and edge $e$ is defined as the [bitwise XOR](https://en.wikipedia.org/wiki/Bitwise_operation#XOR) of all the node's and edge's values between them, including the endpoints (note that in a tree there is only one simple path between two nodes or between a node and an edge).

## Input

The first line contains a single integer $t$ ($1 \le t \le 5\cdot 10^4$) — the number of test cases. Then $t$ test cases follow.

The first line of each test case contains a single integer $p$ ($1 \le p \le 17$), where $n$ (the number of vertices in the tree) is equal to $2^p$.

Each of the next $n−1$ lines contains two integers $u$ and $v$ ($1 \le u,v \le n$) meaning that there is an edge between the vertices $u$ and $v$ in the tree.

It is guaranteed that the given graph is a tree.

It is guaranteed that the sum of $n$ over all test cases doesn't exceed $3\cdot 10^5$.

## Output

For each test case on the first line print the chosen root.

On the second line, print $n$ integers separated by spaces, where the $i$-th integer represents the chosen value for the $i$-th node.

On the third line, print $n-1$ integers separated by spaces, where the $i$-th integer represents the chosen value for the $i$-th edge. The edges are numerated in the order of their appearance in the input data.

If there are multiple solutions, you may output any.

## Example

## Input


```

221 22 33 431 22 33 41 51 65 75 8
```
## Output


```

3
5 1 3 6
4 2 7
5
1 2 8 11 4 13 9 15
6 14 3 7 10 5 12

```
## Note

The tree in the first test case with the weights of all nodes and edges is shown in the picture.

 ![](images/397067bb31787102edaa0c3d95a3fa355c59df22.png) The costs of all paths are: 

* $3$;
* $3\oplus 7=4$;
* $3\oplus 7\oplus 6=2$;
* $3\oplus 2=1$;
* $3\oplus 2\oplus 1=0$;
* $3\oplus 2\oplus 1\oplus 4=4$;
* $3\oplus 2\oplus 1\oplus 4\oplus 5=1$.

The maximum cost of all these paths is $4$. We can show that it is impossible to assign the values and choose the root differently to achieve a smaller maximum cost of all paths.

The tree in the second test case: 

 ![](images/07f4a798c9592ab6057a13e8b5829d7d045fd531.png) 

#### tags 

#2200 #bitmasks #constructive_algorithms #dfs_and_similar #trees 