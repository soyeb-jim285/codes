<h1 style='text-align: center;'> E. Empty Rectangles</h1>

<h5 style='text-align: center;'>time limit per test: 12 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

You've got an *n* × *m* table (*n* rows and *m* columns), each cell of the table contains a "0" or a "1".

Your task is to calculate the number of rectangles with the sides that are parallel to the sides of the table and go along the cell borders, such that the number one occurs exactly *k* times in the rectangle. 

## Input

The first line contains three space-separated integers *n*, *m* and *k* (1 ≤ *n*, *m* ≤ 2500, 0 ≤ *k* ≤ 6) — the sizes of the table and the required number of numbers one.

Next *n* lines each contains *m* characters "0" or "1". The *i*-th character of the *j*-th line corresponds to the character that is in the *j*-th row and the *i*-th column of the table.

## Output

Print a single number — the number of rectangles that contain exactly *k* numbers one.

Please, do not write the %lld specifier to read or write 64-bit integers in С++. It is preferred to use the cin, cout streams or the %I64d specifier.

## Examples

## Input


```
3 3 2  
101  
000  
101  

```
## Output


```
8  

```
## Input


```
5 5 1  
00000  
00000  
00100  
00000  
00000  

```
## Output


```
81  

```
## Input


```
5 5 6  
01010  
10101  
01010  
10101  
01010  

```
## Output


```
12  

```
## Input


```
3 3 0  
001  
010  
000  

```
## Output


```
15  

```
## Input


```
4 4 0  
0000  
0101  
0000  
0000  

```
## Output


```
52  

```


#### tags 

#3000 #divide_and_conquer #two_pointers 