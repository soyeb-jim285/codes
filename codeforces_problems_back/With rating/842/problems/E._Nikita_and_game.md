<h1 style='text-align: center;'> E. Nikita and game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Nikita plays a new computer game. There are *m* levels in this game. In the beginning of each level a new class appears in the game; this class is a child-class of the class *y**i* (and *y**i* is called parent-class for this new class). Thus, the classes form a tree. Initially there is only one class with index 1.

Changing the class to its neighbour (child-class or parent-class) in the tree costs 1 coin. You can not change the class back. The cost of changing the class *a* to the class *b* is equal to the total cost of class changes on the path from *a* to *b* in the class tree.

Suppose that at *i* -th level the maximum cost of changing one class to another is *x*. For each level output the number of classes such that for each of these classes there exists some other class *y*, and the distance from this class to *y* is exactly *x*.

## Input

First line contains one integer number *m* — number of queries (1 ≤ *m* ≤ 3·105).

Next *m* lines contain description of queries. *i* -th line (1 ≤ *i* ≤ *m*) describes the *i* -th level and contains an integer *y**i* — the index of the parent-class of class with index *i* + 1 (1 ≤ *y**i* ≤ *i*). 

## Output

Suppose that at *i* -th level the maximum cost of changing one class to another is *x*. For each level output the number of classes such that for each of these classes there exists some other class *y*, and the distance from this class to *y* is exactly *x*.

## Examples

## Input


```
4  
1  
1  
2  
1  

```
## Output


```
2  
2  
2  
3  

```
## Input


```
4  
1  
1  
2  
3  

```
## Output


```
2  
2  
2  
2  

```


#### tags 

#2800 #binary_search #dfs_and_similar #divide_and_conquer #graphs #trees 