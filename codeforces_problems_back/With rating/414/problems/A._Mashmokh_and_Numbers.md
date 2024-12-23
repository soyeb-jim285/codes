<h1 style='text-align: center;'> A. Mashmokh and Numbers</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

It's holiday. Mashmokh and his boss, Bimokh, are playing a game invented by Mashmokh. 

In this game Mashmokh writes sequence of *n* distinct integers on the board. Then Bimokh makes several (possibly zero) moves. On the first move he removes the first and the second integer from from the board, on the second move he removes the first and the second integer of the remaining sequence from the board, and so on. Bimokh stops when the board contains less than two numbers. When Bimokh removes numbers *x* and *y* from the board, he gets *gcd*(*x*, *y*) points. At the beginning of the game Bimokh has zero points.

Mashmokh wants to win in the game. For this reason he wants his boss to get exactly *k* points in total. But the guy doesn't know how choose the initial sequence in the right way. 

Please, help him. Find *n* distinct integers *a*1, *a*2, ..., *a**n* such that his boss will score exactly *k* points. Also Mashmokh can't memorize too huge numbers. Therefore each of these integers must be at most 109.

## Input

The first line of input contains two space-separated integers *n*, *k* (1 ≤ *n* ≤ 105; 0 ≤ *k* ≤ 108).

## Output

If such sequence doesn't exist output -1 otherwise output *n* distinct space-separated integers *a*1, *a*2, ..., *a**n* (1 ≤ *a**i* ≤ 109).

## Examples

## Input


```
5 2  

```
## Output


```
1 2 3 4 5  

```
## Input


```
5 3
```
## Output


```
2 4 3 7 1
```
## Input


```
7 2  

```
## Output


```
-1  

```
## Note

*gcd*(*x*, *y*) is greatest common divisor of *x* and *y*.



#### tags 

#1500 #constructive_algorithms #number_theory 