<h1 style='text-align: center;'> C. Break Up</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Again, there are hard times in Berland! Many towns have such tensions that even civil war is possible. 

There are *n* towns in Reberland, some pairs of which connected by two-way roads. It is not guaranteed that it is possible to reach one town from any other town using these roads. 

Towns *s* and *t* announce the final break of any relationship and intend to rule out the possibility of moving between them by the roads. Now possibly it is needed to close several roads so that moving from *s* to *t* using roads becomes impossible. Each town agrees to spend money on closing no more than one road, therefore, the total number of closed roads will be no more than two.

Help them find set of no more than two roads such that there will be no way between *s* and *t* after closing these roads. For each road the budget required for its closure was estimated. Among all sets find such that the total budget for the closure of a set of roads is minimum.

## Input

The first line of the input contains two integers *n* and *m* (2 ≤ *n* ≤ 1000, 0 ≤ *m* ≤ 30 000) — the number of towns in Berland and the number of roads.

The second line contains integers *s* and *t* (1 ≤ *s*, *t* ≤ *n*, *s* ≠ *t*) — indices of towns which break up the relationships.

Then follow *m* lines, each of them contains three integers *x**i*, *y**i* and *w**i* (1 ≤ *x**i*, *y**i* ≤ *n*, 1 ≤ *w**i* ≤ 109) — indices of towns connected by the *i*-th road, and the budget on its closure.

All roads are bidirectional. It is allowed that the pair of towns is connected by more than one road. Roads that connect the city to itself are allowed. 

## Output

In the first line print the minimum budget required to break up the relations between *s* and *t*, if it is allowed to close no more than two roads.

In the second line print the value *c* (0 ≤ *c* ≤ 2) — the number of roads to be closed in the found solution.

In the third line print in any order *c* diverse integers from 1 to *m* — indices of closed roads. Consider that the roads are numbered from 1 to *m* in the order they appear in the input. 

If it is impossible to make towns *s* and *t* disconnected by removing no more than 2 roads, the output should contain a single line -1. 

If there are several possible answers, you may print any of them.

## Examples

## Input


```
6 7  
1 6  
2 1 6  
2 3 5  
3 4 9  
4 6 4  
4 6 5  
4 5 1  
3 1 3  

```
## Output


```
8  
2  
2 7  

```
## Input


```
6 7  
1 6  
2 3 1  
1 2 2  
1 3 3  
4 5 4  
3 6 5  
4 6 6  
1 5 7  

```
## Output


```
9  
2  
4 5  

```
## Input


```
5 4  
1 5  
2 1 3  
3 2 1  
3 4 4  
4 5 2  

```
## Output


```
1  
1  
2  

```
## Input


```
2 3  
1 2  
1 2 734458840  
1 2 817380027  
1 2 304764803  

```
## Output


```
-1  

```


#### tags 

#2600 #dfs_and_similar #graphs 