<h1 style='text-align: center;'> E. Domino Principle</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya is interested in arranging dominoes. He is fed up with common dominoes and he uses the dominoes of different heights. He put *n* dominoes on the table along one axis, going from left to right. Every domino stands perpendicular to that axis so that the axis passes through the center of its base. The *i*-th domino has the coordinate *x**i* and the height *h**i*. Now Vasya wants to learn for every domino, how many dominoes will fall if he pushes it to the right. Help him do that. 

Consider that a domino falls if it is touched strictly above the base. In other words, the fall of the domino with the initial coordinate *x* and height *h* leads to the fall of all dominoes on the segment [*x* + 1, *x* + *h* - 1].

![](images/6be8a0bab99fd497cc3eba6b86f7f0cf07804cea.png)## Input

The first line contains integer *n* (1 ≤ *n* ≤ 105) which is the number of dominoes. Then follow *n* lines containing two integers *x**i* and *h**i* ( - 108 ≤ *x**i* ≤ 108, 2 ≤ *h**i* ≤ 108) each, which are the coordinate and height of every domino. No two dominoes stand on one point.

## Output

Print *n* space-separated numbers *z**i* — the number of dominoes that will fall if Vasya pushes the *i*-th domino to the right (including the domino itself).

## Examples

## Input


```
4  
16 5  
20 5  
10 10  
18 2  

```
## Output


```
3 1 4 1 
```
## Input


```
4  
0 10  
1 5  
9 10  
15 10  

```
## Output


```
4 1 2 1 
```


#### tags 

#2200 #binary_search #data_structures #sortings 