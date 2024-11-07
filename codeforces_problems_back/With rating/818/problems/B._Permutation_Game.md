<h1 style='text-align: center;'> B. Permutation Game</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

*n* children are standing in a circle and playing a game. Children's numbers in clockwise order form a permutation *a*1, *a*2, ..., *a**n* of length *n*. It is an integer sequence such that each integer from 1 to *n* appears exactly once in it.

The game consists of *m* steps. On each step the current leader with index *i* counts out *a**i* people in clockwise order, starting from the next person. The last one to be pointed at by the leader becomes the new leader.

You are given numbers *l*1, *l*2, ..., *l**m* — indices of leaders in the beginning of each step. Child with number *l*1 is the first leader in the game. 

Write a program which will restore a possible permutation *a*1, *a*2, ..., *a**n*. If there are multiple solutions then print any of them. If there is no solution then print -1.

## Input

The first line contains two integer numbers *n*, *m* (1 ≤ *n*, *m* ≤ 100).

The second line contains *m* integer numbers *l*1, *l*2, ..., *l**m* (1 ≤ *l**i* ≤ *n*) — indices of leaders in the beginning of each step.

## Output

Print such permutation of *n* numbers *a*1, *a*2, ..., *a**n* that leaders in the game will be exactly *l*1, *l*2, ..., *l**m* if all the rules are followed. If there are multiple solutions print any of them. 

If there is no permutation which satisfies all described conditions print -1.

## Examples

## Input


```
4 5  
2 3 1 4 4  

```
## Output


```
3 1 2 4   

```
## Input


```
3 3  
3 1 2  

```
## Output


```
-1  

```
## Note

Let's follow leadership in the first example: 

* Child 2 starts.
* Leadership goes from 2 to 2 + *a*2 = 3.
* Leadership goes from 3 to 3 + *a*3 = 5. As it's greater than 4, it's going in a circle to 1.
* Leadership goes from 1 to 1 + *a*1 = 4.
* Leadership goes from 4 to 4 + *a*4 = 8. Thus in circle it still remains at 4.


#### tags 

#1600 #implementation 