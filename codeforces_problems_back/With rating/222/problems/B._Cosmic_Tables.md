<h1 style='text-align: center;'> B. Cosmic Tables</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

The Free Meteor Association (FMA) has got a problem: as meteors are moving, the Universal Cosmic Descriptive Humorous Program (UCDHP) needs to add a special module that would analyze this movement. 

UCDHP stores some secret information about meteors as an *n* × *m* table with integers in its cells. The order of meteors in the Universe is changing. That's why the main UCDHP module receives the following queries:

* The query to swap two table rows;
* The query to swap two table columns;
* The query to obtain a secret number in a particular table cell.

As the main UCDHP module is critical, writing the functional of working with the table has been commissioned to you.

## Input

The first line contains three space-separated integers *n*, *m* and *k* (1 ≤ *n*, *m* ≤ 1000, 1 ≤ *k* ≤ 500000) — the number of table columns and rows and the number of queries, correspondingly.

Next *n* lines contain *m* space-separated numbers each — the initial state of the table. Each number *p* in the table is an integer and satisfies the inequality 0 ≤ *p* ≤ 106.

Next *k* lines contain queries in the format "*s**i* *x**i* *y**i*", where *s**i* is one of the characters "с", "r" or "g", and *x**i*, *y**i* are two integers.

* If *s**i* = "c", then the current query is the query to swap columns with indexes *x**i* and *y**i* (1 ≤ *x*, *y* ≤ *m*, *x* ≠ *y*);
* If *s**i* = "r", then the current query is the query to swap rows with indexes *x**i* and *y**i* (1 ≤ *x*, *y* ≤ *n*, *x* ≠ *y*);
* If *s**i* = "g", then the current query is the query to obtain the number that located in the *x**i*-th row and in the *y**i*-th column (1 ≤ *x* ≤ *n*, 1 ≤ *y* ≤ *m*).

The table rows are considered to be indexed from top to bottom from 1 to *n*, and the table columns — from left to right from 1 to *m*.

## Output

For each query to obtain a number (*s**i* = "g") print the required number. Print the answers to the queries in the order of the queries in the input.

## Examples

## Input


```
3 3 5  
1 2 3  
4 5 6  
7 8 9  
g 3 2  
r 3 2  
c 2 3  
g 2 2  
g 3 2  

```
## Output


```
8  
9  
6  

```
## Input


```
2 3 3  
1 2 4  
3 1 5  
c 2 1  
r 1 2  
g 1 3  

```
## Output


```
5  

```
## Note

Let's see how the table changes in the second test case.

After the first operation is fulfilled, the table looks like that:

2 1 4

1 3 5

After the second operation is fulfilled, the table looks like that:

1 3 5

2 1 4

So the answer to the third query (the number located in the first row and in the third column) will be 5.



#### tags 

#1300 #data_structures #implementation 