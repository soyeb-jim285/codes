<h1 style='text-align: center;'> E. Sagheer and Apple Tree</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Sagheer is playing a game with his best friend Soliman. He brought a tree with *n* nodes numbered from 1 to *n* and rooted at node 1. The *i*-th node has *a**i* apples. This tree has a special property: the lengths of all paths from the root to any leaf have the same parity (i.e. all paths have even length or all paths have odd length).

Sagheer and Soliman will take turns to play. Soliman will make the first move. The player who can't make a move loses.

In each move, the current player will pick a single node, take a non-empty subset of apples from it and do one of the following two things:

1. eat the apples, if the node is a leaf.
2. move the apples to one of the children, if the node is non-leaf.

Before Soliman comes to start playing, Sagheer will make exactly one change to the tree. He will pick two different nodes *u* and *v* and swap the apples of *u* with the apples of *v*.

Can you help Sagheer count the number of ways to make the swap (i.e. to choose *u* and *v*) after which he will win the game if both players play optimally? (*u*, *v*) and (*v*, *u*) are considered to be the same pair.

## Input

The first line will contain one integer *n* (2 ≤ *n* ≤ 105) — the number of nodes in the apple tree.

The second line will contain *n* integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 107) — the number of apples on each node of the tree.

The third line will contain *n* - 1 integers *p*2, *p*3, ..., *p**n* (1 ≤ *p**i* ≤ *n*) — the parent of each node of the tree. Node *i* has parent *p**i* (for 2 ≤ *i* ≤ *n*). Node 1 is the root of the tree.

It is guaranteed that the input describes a valid tree, and the lengths of all paths from the root to any leaf will have the same parity.

## Output

On a single line, print the number of different pairs of nodes (*u*, *v*), *u* ≠ *v* such that if they start playing after swapping the apples of both nodes, Sagheer will win the game. (*u*, *v*) and (*v*, *u*) are considered to be the same pair.

## Examples

## Input


```
3  
2 2 3  
1 1  

```
## Output


```
1  

```
## Input


```
3  
1 2 3  
1 1  

```
## Output


```
0  

```
## Input


```
8  
7 2 2 5 4 3 1 1  
1 1 1 4 4 5 6  

```
## Output


```
4  

```
## Note

In the first sample, Sagheer can only win if he swapped node 1 with node 3. In this case, both leaves will have 2 apples. If Soliman makes a move in a leaf node, Sagheer can make the same move in the other leaf. If Soliman moved some apples from a root to a leaf, Sagheer will eat those moved apples. Eventually, Soliman will not find a move.

In the second sample, There is no swap that will make Sagheer win the game.

## Note

 that Sagheer must make the swap even if he can win with the initial tree.



#### tags 

#2300 #games #trees 