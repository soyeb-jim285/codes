<h1 style='text-align: center;'> B. Two Sets</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Little X has *n* distinct integers: *p*1, *p*2, ..., *p**n*. He wants to divide all of them into two sets *A* and *B*. The following two conditions must be satisfied:

* If number *x* belongs to set *A*, then number *a* - *x* must also belong to set *A*.
* If number *x* belongs to set *B*, then number *b* - *x* must also belong to set *B*.

Help Little X divide the numbers into two sets or determine that it's impossible.

## Input

The first line contains three space-separated integers *n*, *a*, *b* (1 ≤ *n* ≤ 105; 1 ≤ *a*, *b* ≤ 109). The next line contains *n* space-separated distinct integers *p*1, *p*2, ..., *p**n* (1 ≤ *p**i* ≤ 109).

## Output

If there is a way to divide the numbers into two sets, then print "YES" in the first line. Then print *n* integers: *b*1, *b*2, ..., *b**n* (*b**i* equals either 0, or 1), describing the division. If *b**i* equals to 0, then *p**i* belongs to set *A*, otherwise it belongs to set *B*.

If it's impossible, print "NO" (without the quotes).

## Examples

## Input


```
4 5 9  
2 3 4 5  

```
## Output


```
YES  
0 0 1 1  

```
## Input


```
3 3 4  
1 2 4  

```
## Output


```
NO  

```
## Note

It's OK if all the numbers are in the same set, and the other one is empty.



#### tags 

#2000 #2-sat #dfs_and_similar #dsu #graph_matchings #greedy 