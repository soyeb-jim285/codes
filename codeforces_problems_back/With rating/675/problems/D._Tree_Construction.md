<h1 style='text-align: center;'> D. Tree Construction</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

During the programming classes Vasya was assigned a difficult problem. However, he doesn't know how to code and was unable to find the solution in the Internet, so he asks you to help.

You are given a sequence $a$, consisting of $n$ distinct integers, that is used to construct the binary search tree. Below is the formal description of the construction process.

1. First element $a_1$ becomes the root of the tree.
2. Elements $a_2, a_3, \ldots, a_n$ are added one by one. To add element $a_i$ one needs to traverse the tree starting from the root and using the following rules:
	1. The pointer to the current node is set to the root.
	2. If $a_i$ is greater than the value in the current node, then its right child becomes the current node. Otherwise, the left child of the current node becomes the new current node.
	3. If at some point there is no required child, the new node is created, it is assigned value $a_i$ and becomes the corresponding child of the current node.
## Input

The first line of the input contains a single integer $n$ ($2 \leq n \leq 100\,000$) — the length of the sequence $a$.

The second line contains $n$ distinct integers $a_i$ ($1 \leq a_i \leq 10^9$) — the sequence $a$ itself.

## Output

## Output

 $n - 1$ integers. For all $i > 1$ print the value written in the node that is the parent of the node with value $a_i$ in it.

## Examples

## Input


```
3  
1 2 3  

```
## Output


```
1 2  

```
## Input


```
5  
4 2 3 1 6  

```
## Output


```
4 2 2 4  

```


#### tags 

#1800 #data_structures #trees 