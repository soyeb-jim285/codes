<h1 style='text-align: center;'> B. Vasya and Wrestling</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has become interested in wrestling. In wrestling wrestlers use techniques for which they are awarded points by judges. The wrestler who gets the most points wins.

When the numbers of points of both wrestlers are equal, the wrestler whose sequence of points is lexicographically greater, wins.

If the sequences of the awarded points coincide, the wrestler who performed the last technique wins. Your task is to determine which wrestler won.

## Input

The first line contains number *n* — the number of techniques that the wrestlers have used (1 ≤ *n* ≤ 2·105). 

The following *n* lines contain integer numbers *a**i* (|*a**i*| ≤ 109, *a**i* ≠ 0). If *a**i* is positive, that means that the first wrestler performed the technique that was awarded with *a**i* points. And if *a**i* is negative, that means that the second wrestler performed the technique that was awarded with ( - *a**i*) points.

The techniques are given in chronological order.

## Output

If the first wrestler wins, print string "first", otherwise print "second"

## Examples

## Input


```
5  
1  
2  
-3  
-4  
3  

```
## Output


```
second  

```
## Input


```
3  
-1  
-2  
3  

```
## Output


```
first  

```
## Input


```
2  
4  
-4  

```
## Output


```
second  

```
## Note

Sequence *x*  =  *x*1*x*2... *x*|*x*| is lexicographically larger than sequence *y*  =  *y*1*y*2... *y*|*y*|, if either |*x*|  >  |*y*| and *x*1  =  *y*1,  *x*2  =  *y*2, ... ,  *x*|*y*|  =  *y*|*y*|, or there is such number *r* (*r*  <  |*x*|, *r*  <  |*y*|), that *x*1  =  *y*1,  *x*2  =  *y*2,  ... ,  *x**r*  =  *y**r* and *x**r*  +  1  >  *y**r*  +  1.

We use notation |*a*| to denote length of sequence *a*.



#### tags 

#1400 #implementation 