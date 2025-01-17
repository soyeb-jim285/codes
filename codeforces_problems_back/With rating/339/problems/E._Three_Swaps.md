<h1 style='text-align: center;'> E. Three Swaps</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Xenia the horse breeder has *n* (*n* > 1) horses that stand in a row. Each horse has its own unique number. Initially, the *i*-th left horse has number *i*. That is, the sequence of numbers of horses in a row looks as follows (from left to right): 1, 2, 3, ..., *n*.

Xenia trains horses before the performance. During the practice sessions, she consistently gives them commands. Each command is a pair of numbers *l*, *r* (1 ≤ *l* < *r* ≤ *n*). The command *l*, *r* means that the horses that are on the *l*-th, (*l* + 1)-th, (*l* + 2)-th, ..., *r*-th places from the left must be rearranged. The horses that initially stand on the *l*-th and *r*-th places will swap. The horses on the (*l* + 1)-th and (*r* - 1)-th places will swap. The horses on the (*l* + 2)-th and (*r* - 2)-th places will swap and so on. In other words, the horses that were on the segment [*l*, *r*] change their order to the reverse one.

For example, if Xenia commanded *l* = 2, *r* = 5, and the sequence of numbers of horses before the command looked as (2, 1, 3, 4, 5, 6), then after the command the sequence will be (2, 5, 4, 3, 1, 6).

We know that during the practice Xenia gave at most three commands of the described form. You have got the final sequence of numbers of horses by the end of the practice. Find what commands Xenia gave during the practice. Note that you do not need to minimize the number of commands in the solution, find any valid sequence of at most three commands.

## Input

The first line contains an integer *n* (2 ≤ *n* ≤ 1000) — the number of horses in the row. The second line contains *n* distinct integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ *n*), where *a**i* is the number of the *i*-th left horse in the row after the practice.

## Output

The first line should contain integer *k* (0 ≤ *k* ≤ 3) — the number of commads Xenia gave during the practice. In each of the next *k* lines print two integers. In the *i*-th line print numbers *l**i*, *r**i* (1 ≤ *l**i* < *r**i* ≤ *n*) — Xenia's *i*-th command during the practice.

It is guaranteed that a solution exists. If there are several solutions, you are allowed to print any of them.

## Examples

## Input


```
5  
1 4 3 2 5  

```
## Output


```
1  
2 4  

```
## Input


```
6  
2 1 4 3 6 5  

```
## Output


```
3  
1 2  
3 4  
5 6  

```


#### tags 

#2700 #constructive_algorithms #dfs_and_similar #greedy 