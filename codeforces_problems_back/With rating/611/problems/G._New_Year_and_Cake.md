<h1 style='text-align: center;'> G. New Year and Cake</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Limak is a little polar bear. According to some old traditions, his bear family prepared a New Year cake. And Limak likes cakes.

As you may know, a New Year cake is a strictly convex polygon with *n* vertices.

Parents won't allow Limak to eat more than half of a cake because he would get sick. After some thinking they decided to cut a cake along one of *n*·(*n* - 3) / 2 diagonals. Then Limak will get a non-greater piece.

Limak understands rules but he won't be happy if the second piece happens to be much bigger. Limak's disappointment will be equal to the difference between pieces' areas, multiplied by two. It can be proved that it will be integer for the given constraints.

There are *n*·(*n* - 3) / 2 possible scenarios. Consider them all and find the sum of values of Limak's disappointment, modulo 109 + 7.

## Input

The first line of the input contains a single integer *n* (4 ≤ *n* ≤ 500 000) — the number of vertices in the polygon denoting the cake.

Each of the next *n* lines contains two integers *x**i* and *y**i* (|*x**i*|, |*y**i*| ≤ 109) — coordinates of the *i*-th point.

It's guaranteed that all points are distinct, polygon is strictly convex and points are given in the clockwise order.

## Output

Print the sum of values of Limak's disappointment over all possible scenarios modulo 109 + 7.

## Examples

## Input


```
5  
2 4  
2 7  
5 7  
5 4  
3 -2  

```
## Output


```
90  

```
## Input


```
4  
-1000000000 -5000000  
0 1234567  
1 1  
-5 -100000000  

```
## Output


```
525185196  

```
## Input


```
8  
-10 0  
-6 6  
0 10  
6 6  
10 0  
6 -6  
0 -10  
-6 -6  

```
## Output


```
5216  

```
## Note

In the first sample possible values of Limak's disappointment are 0, 18, 18, 24, 30.



#### tags 

#2900 #geometry #two_pointers 