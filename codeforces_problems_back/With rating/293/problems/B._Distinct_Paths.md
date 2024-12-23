<h1 style='text-align: center;'> B. Distinct Paths</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

You have a rectangular *n* × *m*-cell board. Some cells are already painted some of *k* colors. You need to paint each uncolored cell one of the *k* colors so that any path from the upper left square to the lower right one doesn't contain any two cells of the same color. The path can go only along side-adjacent cells and can only go down or right.

Print the number of possible paintings modulo 1000000007 (109 + 7).

## Input

The first line contains three integers *n*, *m*, *k* (1 ≤ *n*, *m* ≤ 1000, 1 ≤ *k* ≤ 10). The next *n* lines contain *m* integers each — the board. The first of them contains *m* uppermost cells of the board from the left to the right and the second one contains *m* cells from the second uppermost row and so on. If a number in a line equals 0, then the corresponding cell isn't painted. Otherwise, this number represents the initial color of the board cell — an integer from 1 to *k*.

Consider all colors numbered from 1 to *k* in some manner.

## Output

Print the number of possible paintings modulo 1000000007 (109 + 7).

## Examples

## Input


```
2 2 4  
0 0  
0 0  

```
## Output


```
48  

```
## Input


```
2 2 4  
1 2  
2 1  

```
## Output


```
0  

```
## Input


```
5 6 10  
0 0 0 0 0 0  
0 0 0 0 0 0  
0 0 0 0 0 0  
0 0 0 0 0 0  
0 0 0 0 0 0  

```
## Output


```
3628800  

```
## Input


```
2 6 10  
1 2 3 4 5 6  
0 0 0 0 0 0  

```
## Output


```
4096  

```


#### tags 

#2700 #brute_force #combinatorics 