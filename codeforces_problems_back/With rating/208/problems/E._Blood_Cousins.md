<h1 style='text-align: center;'> E. Blood Cousins</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Polycarpus got hold of a family relationship tree. The tree describes family relationships of *n* people, numbered 1 through *n*. Each person in the tree has no more than one parent.

Let's call person *a* a 1-ancestor of person *b*, if *a* is the parent of *b*.

Let's call person *a* a *k*-ancestor (*k* > 1) of person *b*, if person *b* has a 1-ancestor, and *a* is a (*k* - 1)-ancestor of *b*'s 1-ancestor. 

Family relationships don't form cycles in the found tree. In other words, there is no person who is his own ancestor, directly or indirectly (that is, who is an *x*-ancestor for himself, for some *x*, *x* > 0).

Let's call two people *x* and *y* (*x* ≠ *y*) *p*-th cousins (*p* > 0), if there is person *z*, who is a *p*-ancestor of *x* and a *p*-ancestor of *y*.

Polycarpus wonders how many counsins and what kinds of them everybody has. He took a piece of paper and wrote *m* pairs of integers *v**i*, *p**i*. Help him to calculate the number of *p**i*-th cousins that person *v**i* has, for each pair *v**i*, *p**i*.

## Input

The first input line contains a single integer *n* (1 ≤ *n* ≤ 105) — the number of people in the tree. The next line contains *n* space-separated integers *r*1, *r*2, ..., *r**n*, where *r**i* (1 ≤ *r**i* ≤ *n*) is the number of person *i*'s parent or 0, if person *i* has no parent. It is guaranteed that family relationships don't form cycles.

The third line contains a single number *m* (1 ≤ *m* ≤ 105) — the number of family relationship queries Polycarus has. Next *m* lines contain pairs of space-separated integers. The *i*-th line contains numbers *v**i*, *p**i* (1 ≤ *v**i*, *p**i* ≤ *n*).

## Output

Print *m* space-separated integers — the answers to Polycarpus' queries. Print the answers to the queries in the order, in which the queries occur in the input.

## Examples

## Input


```
6  
0 1 1 0 4 4  
7  
1 1  
1 2  
2 1  
2 2  
4 1  
5 1  
6 1  

```
## Output


```
0 0 1 0 0 1 1   

```


#### tags 

#2100 #binary_search #data_structures #dfs_and_similar #trees 