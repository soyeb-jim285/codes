<h1 style='text-align: center;'> D. Greg and Caves</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Greg has a pad. The pad's screen is an *n* × *m* rectangle, each cell can be either black or white. We'll consider the pad rows to be numbered with integers from 1 to *n* from top to bottom. Similarly, the pad's columns are numbered with integers from 1 to *m* from left to right.

Greg thinks that the pad's screen displays a cave if the following conditions hold:

* There is a segment [*l*, *r*] (1 ≤ *l* ≤ *r* ≤ *n*), such that each of the rows *l*, *l* + 1, ..., *r* has exactly two black cells and all other rows have only white cells.
* There is a row number *t* (*l* ≤ *t* ≤ *r*), such that for all pairs of rows with numbers *i* and *j* (*l* ≤ *i* ≤ *j* ≤ *t*) the set of columns between the black cells in row *i* (with the columns where is these black cells) is the subset of the set of columns between the black cells in row *j* (with the columns where is these black cells). Similarly, for all pairs of rows with numbers *i* and *j* (*t* ≤ *i* ≤ *j* ≤ *r*) the set of columns between the black cells in row *j* (with the columns where is these black cells) is the subset of the set of columns between the black cells in row *i* (with the columns where is these black cells).

Greg wondered, how many ways there are to paint a cave on his pad. Two ways can be considered distinct if there is a cell that has distinct colors on the two pictures.

Help Greg.

## Input

The first line contains two integers *n*, *m* — the pad's screen size (1 ≤ *n*, *m* ≤ 2000).

## Output

In the single line print the remainder after dividing the answer to the problem by 1000000007 (109 + 7).

## Examples

## Input


```
1 1  

```
## Output


```
0  

```
## Input


```
4 4  

```
## Output


```
485  

```
## Input


```
3 5  

```
## Output


```
451  

```


#### tags 

#2400 #combinatorics #dp 