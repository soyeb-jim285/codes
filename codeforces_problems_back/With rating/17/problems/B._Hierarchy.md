<h1 style='text-align: center;'> B. Hierarchy</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

Nick's company employed *n* people. Now Nick needs to build a tree hierarchy of «supervisor-surbodinate» relations in the company (this is to say that each employee, except one, has exactly one supervisor). There are *m* applications written in the following form: «employee *a**i* is ready to become a supervisor of employee *b**i* at extra cost *c**i*». The qualification *q**j* of each employee is known, and for each application the following is true: *q**a**i* > *q**b**i*. 

Would you help Nick calculate the minimum cost of such a hierarchy, or find out that it is impossible to build it.

## Input

The first input line contains integer *n* (1 ≤ *n* ≤ 1000) — amount of employees in the company. The following line contains *n* space-separated numbers *q**j* (0 ≤ *q**j* ≤ 106)— the employees' qualifications. The following line contains number *m* (0 ≤ *m* ≤ 10000) — amount of received applications. The following *m* lines contain the applications themselves, each of them in the form of three space-separated numbers: *a**i*, *b**i* and *c**i* (1 ≤ *a**i*, *b**i* ≤ *n*, 0 ≤ *c**i* ≤ 106). Different applications can be similar, i.e. they can come from one and the same employee who offered to become a supervisor of the same person but at a different cost. For each application *q**a**i* > *q**b**i*.

## Output

## Output

 the only line — the minimum cost of building such a hierarchy, or -1 if it is impossible to build it.

## Examples

## Input


```
4  
7 2 3 1  
4  
1 2 5  
2 4 1  
3 4 1  
1 3 5  

```
## Output


```
11  

```
## Input


```
3  
1 2 3  
2  
3 1 2  
3 1 3  

```
## Output


```
-1  

```
## Note

In the first sample one of the possible ways for building a hierarchy is to take applications with indexes 1, 2 and 4, which give 11 as the minimum total cost. In the second sample it is impossible to build the required hierarchy, so the answer is -1.



#### tags 

#1500 #dfs_and_similar #dsu #greedy #shortest_paths 