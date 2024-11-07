<h1 style='text-align: center;'> I. Impressive Harvesting of The Orchard</h1>

<h5 style='text-align: center;'>time limit per test: 7 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mr. Chanek has an orchard structured as a rooted ternary tree with $N$ vertices numbered from $1$ to $N$. The root of the tree is vertex $1$. $P_i$ denotes the parent of vertex $i$, for $(2 \le i \le N)$. Interestingly, the height of the tree is not greater than $10$. Height of a tree is defined to be the largest distance from the root to a vertex in the tree.

There exist a bush on each vertex of the tree. Initially, all bushes have fruits. Fruits will not grow on bushes that currently already have fruits. The bush at vertex $i$ will grow fruits after $A_i$ days since its last harvest.

Mr. Chanek will visit his orchard for $Q$ days. In day $i$, he will harvest all bushes that have fruits on the subtree of vertex $X_i$. For each day, determine the sum of distances from every harvested bush to $X_i$, and the number of harvested bush that day. Harvesting a bush means collecting all fruits on the bush.

For example, if Mr. Chanek harvests all fruits on subtree of vertex $X$, and harvested bushes $[Y_1, Y_2, \dots, Y_M]$, the sum of distances is $\sum_{i = 1}^M \text{distance}(X, Y_i)$

$\text{distance}(U, V)$ in a tree is defined to be the number of edges on the simple path from $U$ to $V$.

#### Input

The first line contains two integers $N$ and $Q$ $(1 \le N,\ Q,\le 5 \cdot 10^4)$, which denotes the number of vertices and the number of days Mr. Chanek visits the orchard.

The second line contains $N$ integers $A_i$ $(1 \le A_i \le 5 \cdot 10^4)$, which denotes the fruits growth speed on the bush at vertex $i$, for $(1 \le i \le N)$.

The third line contains $N-1$ integers $P_i$ $(1 \le P_i \le N, P_i \ne i)$, which denotes the parent of vertex $i$ in the tree, for $(2 \le i \le N)$. It is guaranteed that each vertex can be the parent of at most $3$ other vertices. It is also guaranteed that the height of the tree is not greater than $10$.

The next $Q$ lines contain a single integer $X_i$ $(1 \le X_i \le N)$, which denotes the start of Mr. Chanek's visit on day $i$, for $(1 \le i \le Q)$.

#### Output

#### Output

 $Q$ lines, line $i$ gives the sum of distances from the harvested bushes to $X_i$, and the number of harvested bushes.

## Examples

#### Input


```text
2 3
1 2
1
2
1
1
```
#### Output


```text
0 1
0 1
1 2
```
#### Input


```text
5 3
2 1 1 3 2
1 2 2 1
1
1
1
```
#### Output


```text
6 5
3 2
4 4
```
## Note

For the first example:

* On day 1, Mr. Chanek starts at vertex $2$ and can harvest the bush at vertex 2.
* On day 2, Mr. Chanek starts at vertex $1$ and only harvest from bush $1$ (bush 2's fruit still has not grown yet).
* On day 3, Mr. Chanek starts at vertex $1$ and harvests the fruits on bush $1$ and $2$. The sum of distances from every harvested bush to $1$ is $1$.

For the second example, Mr. Chanek always starts at vertex $1$. The bushes which Mr. Chanek harvests on day one, two, and three are $[1, 2, 3, 4, 5], [2, 3], [1, 2, 3, 5]$, respectively.



#### Tags 

#2800 #NOT OK #data_structures 

## Blogs
- [All Contest Problems](../2020_ICPC,_COMPFEST_12,_Indonesia_Multi-Provincial_Contest_(Unrated,_Online_Mirror,_ICPC_Rules,_Teams_Preferred).md)
- [Announcement (en)](../blogs/Announcement_(en).md)
- [Tutorial (en)](../blogs/Tutorial_(en).md)
