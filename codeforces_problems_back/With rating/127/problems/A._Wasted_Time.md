<h1 style='text-align: center;'> A. Wasted Time</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Mr. Scrooge, a very busy man, decided to count the time he wastes on all sorts of useless stuff to evaluate the lost profit. He has already counted the time he wastes sleeping and eating. And now Mr. Scrooge wants to count the time he has wasted signing papers.

Mr. Scrooge's signature can be represented as a polyline *A*1*A*2... *A**n*. Scrooge signs like that: first it places a pen at the point *A*1, then draws a segment from point *A*1 to point *A*2, then he draws a segment from point *A*2 to point *A*3 and so on to point *A**n*, where he stops signing and takes the pen off the paper. At that the resulting line can intersect with itself and partially repeat itself but Scrooge pays no attention to it and never changes his signing style. As Scrooge makes the signature, he never takes the pen off the paper and his writing speed is constant — 50 millimeters per second.

Scrooge signed exactly *k* papers throughout his life and all those signatures look the same.

Find the total time Scrooge wasted signing the papers.

## Input

The first line contains two integers *n* and *k* (2 ≤ *n* ≤ 100, 1 ≤ *k* ≤ 1000). Each of the following *n* lines contains the coordinates of the polyline's endpoints. The *i*-th one contains coordinates of the point *A**i* — integers *x**i* and *y**i*, separated by a space.

All points *A**i* are different. The absolute value of all coordinates does not exceed 20. The coordinates are measured in millimeters.

## Output

Print one real number — the total time Scrooges wastes on signing the papers in seconds. The absolute or relative error should not exceed 10- 6.

## Examples

## Input


```
2 1  
0 0  
10 0  

```
## Output


```
0.200000000
```
## Input


```
5 10  
3 1  
-5 6  
-2 -1  
3 2  
10 0  

```
## Output


```
6.032163204
```
## Input


```
6 10  
5 0  
4 0  
6 0  
3 0  
7 0  
2 0  

```
## Output


```
3.000000000
```


#### tags 

#900 #geometry 