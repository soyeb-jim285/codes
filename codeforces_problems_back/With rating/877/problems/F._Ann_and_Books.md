<h1 style='text-align: center;'> F. Ann and Books</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

In Ann's favorite book shop are as many as *n* books on math and economics. Books are numbered from 1 to *n*. Each of them contains non-negative number of problems.

Today there is a sale: any subsegment of a segment from *l* to *r* can be bought at a fixed price. 

Ann decided that she wants to buy such non-empty subsegment that the sale operates on it and the number of math problems is greater than the number of economics problems exactly by *k*. ## Note

 that *k* may be positive, negative or zero.

Unfortunately, Ann is not sure on which segment the sale operates, but she has *q* assumptions. For each of them she wants to know the number of options to buy a subsegment satisfying the condition (because the time she spends on choosing depends on that).

Currently Ann is too busy solving other problems, she asks you for help. For each her assumption determine the number of subsegments of the given segment such that the number of math problems is greaten than the number of economics problems on that subsegment exactly by *k*.

## Input

The first line contains two integers *n* and *k* (1 ≤ *n* ≤ 100 000,  - 109 ≤ *k* ≤ 109) — the number of books and the needed difference between the number of math problems and the number of economics problems.

The second line contains *n* integers *t*1, *t*2, ..., *t**n* (1 ≤ *t**i* ≤ 2), where *t**i* is 1 if the *i*-th book is on math or 2 if the *i*-th is on economics.

The third line contains *n* integers *a*1, *a*2, ..., *a**n* (0 ≤ *a**i* ≤ 109), where *a**i* is the number of problems in the *i*-th book.

The fourth line contains a single integer *q* (1 ≤ *q* ≤ 100 000) — the number of assumptions.

Each of the next *q* lines contains two integers *l**i* and *r**i* (1 ≤ *l**i* ≤ *r**i* ≤ *n*) describing the *i*-th Ann's assumption.

## Output

Print *q* lines, in the *i*-th of them print the number of subsegments for the *i*-th Ann's assumption.

## Examples

## Input


```
4 1  
1 1 1 2  
1 1 1 1  
4  
1 2  
1 3  
1 4  
3 4  

```
## Output


```
2  
3  
4  
1  

```
## Input


```
4 0  
1 2 1 2  
0 0 0 0  
1  
1 4  

```
## Output


```
10  

```
## Note

In the first sample Ann can buy subsegments [1;1], [2;2], [3;3], [2;4] if they fall into the sales segment, because the number of math problems is greater by 1 on them that the number of economics problems. So we should count for each assumption the number of these subsegments that are subsegments of the given segment.

Segments [1;1] and [2;2] are subsegments of [1;2].

Segments [1;1], [2;2] and [3;3] are subsegments of [1;3].

Segments [1;1], [2;2], [3;3], [2;4] are subsegments of [1;4].

Segment [3;3] is subsegment of [3;4].



#### tags 

#2300 #data_structures #flows #hashing 