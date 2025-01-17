<h1 style='text-align: center;'> D. Developing Game</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Pavel is going to make a game of his dream. However, he knows that he can't make it on his own so he founded a development company and hired *n* workers of staff. Now he wants to pick *n* workers from the staff who will be directly responsible for developing a game.

Each worker has a certain skill level *v**i*. Besides, each worker doesn't want to work with the one whose skill is very different. In other words, the *i*-th worker won't work with those whose skill is less than *l**i*, and with those whose skill is more than *r**i*.

Pavel understands that the game of his dream isn't too hard to develop, so the worker with any skill will be equally useful. That's why he wants to pick a team of the maximum possible size. Help him pick such team.

## Input

The first line contains a single integer *n* (1 ≤ *n* ≤ 105) — the number of workers Pavel hired.

Each of the following *n* lines contains three space-separated integers *l**i*, *v**i*, *r**i* (1 ≤ *l**i* ≤ *v**i* ≤ *r**i* ≤ 3·105) — the minimum skill value of the workers that the *i*-th worker can work with, the *i*-th worker's skill and the maximum skill value of the workers that the *i*-th worker can work with.

## Output

In the first line print a single integer *m* — the number of workers Pavel must pick for developing the game.

In the next line print *m* space-separated integers — the numbers of the workers in any order.

If there are multiple optimal solutions, print any of them.

## Examples

## Input


```
4  
2 8 9  
1 4 7  
3 6 8  
5 8 10  

```
## Output


```
3  
1 3 4  

```
## Input


```
6  
3 5 16  
1 6 11  
4 8 12  
7 9 16  
2 10 14  
8 13 15  

```
## Output


```
4  
1 2 3 5  

```


#### tags 

#2400 #data_structures 