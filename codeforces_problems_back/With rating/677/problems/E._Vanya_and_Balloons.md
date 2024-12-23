<h1 style='text-align: center;'> E. Vanya and Balloons</h1>

<h5 style='text-align: center;'>time limit per test: 3 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 512 megabytes</h5>

Vanya plays a game of balloons on the field of size *n* × *n*, where each cell contains a balloon with one of the values 0, 1, 2 or 3. The goal is to destroy a cross, such that the product of all values of balloons in the cross is maximum possible. There are two types of crosses: normal and rotated. For example:


```
  
**o**  
**o**  
ooooo  
**o**  
**o**  

```
or


```
  
o***o  
*o*o*  
**o**  
*o*o*  
o***o  

```
Formally, the cross is given by three integers *r*, *c* and *d*, such that *d* ≤ *r*, *c* ≤ *n* - *d* + 1. The normal cross consists of balloons located in cells (*x*, *y*) (where *x* stay for the number of the row and *y* for the number of the column), such that |*x* - *r*|·|*y* - *c*| = 0 and |*x* - *r*| + |*y* - *c*| < *d*. Rotated cross consists of balloons located in cells (*x*, *y*), such that |*x* - *r*| = |*y* - *c*| and |*x* - *r*| < *d*.

Vanya wants to know the maximum possible product of the values of balls forming one cross. As this value can be large, output it modulo 109 + 7.

## Input

The first line of the input contains a single integer *n* (1 ≤ *n* ≤ 1000) — the number of rows and columns in the table with balloons.

The each of the following *n* lines contains *n* characters '0', '1', '2' or '3' — the description of the values in balloons.

## Output

Print the maximum possible product modulo 109 + 7. ## Note

, that you are not asked to maximize the remainder modulo 109 + 7, but to find the maximum value and print it this modulo.

## Examples

## Input


```
4  
1233  
0213  
2020  
0303  

```
## Output


```
108  

```
## Input


```
5  
00300  
00300  
33333  
00300  
00300  

```
## Output


```
19683  

```
## Input


```
5  
00003  
02030  
00300  
03020  
30000  

```
## Output


```
108  

```
## Input


```
5  
21312  
10003  
10002  
10003  
23231  

```
## Output


```
3  

```
## Input


```
5  
12131  
12111  
12112  
21311  
21212  

```
## Output


```
24  

```
## Note

In the first sample, the maximum product is achieved for a rotated cross with a center in the cell (3, 3) and radius 1: 2·2·3·3·3 = 108.



#### tags 

#2300 #binary_search #brute_force #dp #implementation 