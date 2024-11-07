<h1 style='text-align: center;'> A. Dreamoon and Stairs</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Dreamoon wants to climb up a stair of *n* steps. He can climb 1 or 2 steps at each move. Dreamoon wants the number of moves to be a multiple of an integer *m*. 

What is the minimal number of moves making him climb to the top of the stairs that satisfies his condition?

## Input

The single line contains two space separated integers *n*, *m* (0 < *n* ≤ 10000, 1 < *m* ≤ 10).

## Output

Print a single integer — the minimal number of moves being a multiple of *m*. If there is no way he can climb satisfying condition print  - 1 instead.

## Examples

## Input


```
10 2  

```
## Output


```
6  

```
## Input


```
3 5  

```
## Output


```
-1  

```
## Note

For the first sample, Dreamoon could climb in 6 moves with following sequence of steps: {2, 2, 2, 2, 1, 1}.

For the second sample, there are only three valid sequence of steps {2, 1}, {1, 2}, {1, 1, 1} with 2, 2, and 3 steps respectively. All these numbers are not multiples of 5.



#### tags 

#1000 #implementation #math 