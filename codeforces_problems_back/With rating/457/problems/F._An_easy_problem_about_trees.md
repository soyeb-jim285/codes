<h1 style='text-align: center;'> F. An easy problem about trees</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pieguy and Piegirl are playing a game. They have a rooted binary tree, that has a property that each node is either a leaf or has exactly two children. Each leaf has a number associated with it.

On his/her turn a player can choose any two leafs that share their immediate parent, remove them, and associate either of their values with their parent, that now became a leaf (the player decides which of the two values to associate). The game ends when only one node (the one that was the root of the tree) is left.

Pieguy goes first, and his goal is to maximize the value that will be associated with the root when the game ends. Piegirl wants to minimize that value. Assuming that both players are playing optimally, what number will be associated with the root when the game ends?

## Input

First line contains a single integer *t* (1 ≤ *t* ≤ 100) — number of test cases. Then *t* test cases follow. Each test case begins with an empty line, followed by a line with a single integer *n* (1 ≤ *n* ≤ 250), followed by *n* lines describing *n* nodes of the tree. Each of those *n* lines either contains a non-negative number *a**i*, indicating a leaf node with value *a**i* (0 ≤ *a**i* ≤ 1000) associated with it, or  - 1 followed by integers *l* and *r*, indicating a non-leaf node with children *l* and *r* (0 ≤ *l*, *r* ≤ *n* - 1). Nodes are numbered from 0 to *n* - 1. The root is always node 0.

## Output

For each test case print one line with one integer on it — the number that will be associated with the root when the game ends.

## Examples

## Input


```
4  
  
3  
-1 1 2  
10  
5  
  
5  
-1 1 2  
-1 3 4  
10  
5  
20  
  
7  
-1 1 2  
-1 3 4  
-1 5 6  
1  
2  
3  
4  
  
11  
-1 1 2  
-1 3 4  
-1 5 6  
-1 7 8  
15  
7  
-1 9 10  
7  
8  
9  
11  

```
## Output


```
10  
10  
4  
8  

```


#### tags 

#3200 #dp #games #greedy #trees 