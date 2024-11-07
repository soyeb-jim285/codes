<h1 style='text-align: center;'> F. Mice and Holes</h1>

<h5 style='text-align: center;'>time limit per test: 1.5 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

One day Masha came home and noticed *n* mice in the corridor of her flat. Of course, she shouted loudly, so scared mice started to run to the holes in the corridor.

The corridor can be represeted as a numeric axis with *n* mice and *m* holes on it. *i*th mouse is at the coordinate *x**i*, and *j*th hole — at coordinate *p**j*. *j*th hole has enough room for *c**j* mice, so not more than *c**j* mice can enter this hole.

What is the minimum sum of distances that mice have to go through so that they all can hide in the holes? If *i*th mouse goes to the hole *j*, then its distance is |*x**i* - *p**j*|.

Print the minimum sum of distances.

## Input

The first line contains two integer numbers *n*, *m* (1 ≤ *n*, *m* ≤ 5000) — the number of mice and the number of holes, respectively.

The second line contains *n* integers *x*1, *x*2, ..., *x**n* ( - 109 ≤ *x**i* ≤ 109), where *x**i* is the coordinate of *i*th mouse.

Next *m* lines contain pairs of integer numbers *p**j*, *c**j* ( - 109 ≤ *p**j* ≤ 109, 1 ≤ *c**j* ≤ 5000), where *p**j* is the coordinate of *j*th hole, and *c**j* is the maximum number of mice that can hide in the hole *j*.

## Output

Print one integer number — the minimum sum of distances. If there is no solution, print -1 instead.

## Examples

## Input


```
4 5  
6 2 8 9  
3 6  
2 1  
3 6  
4 7  
4 7  

```
## Output


```
11  

```
## Input


```
7 2  
10 20 30 40 50 45 35  
-1000000000 10  
1000000000 1  

```
## Output


```
7000000130  

```


#### tags 

#2600 #data_structures #dp #greedy #sortings 