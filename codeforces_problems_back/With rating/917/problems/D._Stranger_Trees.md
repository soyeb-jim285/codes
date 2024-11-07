<h1 style='text-align: center;'> D. Stranger Trees</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Will shares a psychic connection with the Upside Down Monster, so everything the monster knows, Will knows. Suddenly, he started drawing, page after page, non-stop. Joyce, his mom, and Chief Hopper put the drawings together, and they realized, it's a labeled tree!

 ![](images/1c116a1f726c026673d4997f3fce49ed05fe4092.png) A tree is a connected acyclic graph. Will's tree has *n* vertices. Joyce and Hopper don't know what that means, so they're investigating this tree and similar trees. For each *k* such that 0 ≤ *k* ≤ *n* - 1, they're going to investigate all labeled trees with *n* vertices that share exactly *k* edges with Will's tree. Two labeled trees are different if and only if there's a pair of vertices (*v*, *u*) such that there's an edge between *v* and *u* in one tree and not in the other one.

Hopper and Joyce want to know how much work they have to do, so they asked you to tell them the number of labeled trees with *n* vertices that share exactly *k* edges with Will's tree, for each *k*. The answer could be very large, so they only asked you to tell them the answers modulo 1000000007 = 109 + 7.

## Input

The first line of input contains a single integer *n* (2 ≤ *n* ≤ 100) — the size of the tree.

The next *n* - 1 lines contain the edges of Will's tree. Each line contains two integers *v* and *u* (1 ≤ *v*, *u* ≤ *n*, *v* ≠ *u*), endpoints of an edge. It is guaranteed that the given graph is a tree.

## Output

Print *n* integers in one line. *i*-th integer should be the number of the number of labeled trees with *n* vertices that share exactly *i* - 1 edges with Will's tree, modulo 1000 000 007 = 109 + 7.

## Examples

## Input


```
3  
1 2  
1 3  

```
## Output


```
0 2 1 
```
## Input


```
4  
1 2  
2 3  
3 4  

```
## Output


```
1 7 7 1 
```
## Input


```
4  
1 2  
1 3  
1 4  

```
## Output


```
0 9 6 1 
```


#### tags 

#2600 #dp #math #matrices #trees 