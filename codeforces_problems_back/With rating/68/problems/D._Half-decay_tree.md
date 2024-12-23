<h1 style='text-align: center;'> D. Half-decay tree</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Recently Petya has become keen on physics. Anna V., his teacher noticed Petya's interest and gave him a fascinating physical puzzle — a half-decay tree. 

A half-decay tree is a complete binary tree with the height *h*. The height of a tree is the length of the path (in edges) from the root to a leaf in the tree. While studying the tree Petya can add electrons to vertices or induce random decay with synchrophasotron. Random decay is a process during which the edges of some path from the root to the random leaf of the tree are deleted. All the leaves are equiprobable. As the half-decay tree is the school property, Petya will return back the deleted edges into the tree after each decay.

After being desintegrated, the tree decomposes into connected components. Charge of each component is the total quantity of electrons placed in vertices of the component. Potential of desintegerated tree is the maximum from the charges of its connected components. Each time before inducing random decay Petya is curious about the mathematical expectation of potential of the tree after being desintegrated. 

## Input

First line will contain two integers *h* and *q* (1 ≤ *h* ≤ 30, 1 ≤ *q* ≤ 105). Next *q* lines will contain a query of one of two types: 

* add *v* *e*Petya adds *e* electrons to vertex number *v* (1 ≤ *v* ≤ 2*h* + 1 - 1, 0 ≤ *e* ≤ 104). *v* and *e* are integers.

The vertices of the tree are numbered in the following way: the root is numbered with 1, the children of the vertex with number *x* are numbered with 2*x* and 2*x* + 1.
* decayPetya induces tree decay.
## Output

For each query decay solution you should output the mathematical expectation of potential of the tree after being desintegrated. The absolute or relative error in the answer should not exceed 10- 4.

## Examples

## Input


```
1 4  
add 1 3  
add 2 10  
add 3 11  
decay  

```
## Output


```
13.50000000  

```


#### tags 

#2500 #data_structures #divide_and_conquer #dp #math #probabilities 