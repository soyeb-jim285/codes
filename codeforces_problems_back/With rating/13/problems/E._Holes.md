<h1 style='text-align: center;'> E. Holes</h1>

<h5 style='text-align: center;'>time limit per test: 1 second</h5>
<h5 style='text-align: center;'>memory limit per test: 64 megabytes</h5>

Little Petya likes to play a lot. Most of all he likes to play a game «Holes». This is a game for one person with following rules:

There are *N* holes located in a single row and numbered from left to right with numbers from 1 to *N*. Each hole has it's own power (hole number *i* has the power *a**i*). If you throw a ball into hole *i* it will immediately jump to hole *i* + *a**i*, then it will jump out of it and so on. If there is no hole with such number, the ball will just jump out of the row. On each of the *M* moves the player can perform one of two actions: 

* Set the power of the hole *a* to value *b*.
* Throw a ball into the hole *a* and count the number of jumps of a ball before it jump out of the row and also write down the number of the hole from which it jumped out just before leaving the row.

Petya is not good at math, so, as you have already guessed, you are to perform all computations.

## Input

The first line contains two integers *N* and *M* (1 ≤ *N* ≤ 105, 1 ≤ *M* ≤ 105) — the number of holes in a row and the number of moves. The second line contains *N* positive integers not exceeding *N* — initial values of holes power. The following *M* lines describe moves made by Petya. Each of these line can be one of the two types: 

* 0 *a* *b*
* 1 *a*

 Type 0 means that it is required to set the power of hole *a* to *b*, and type 1 means that it is required to throw a ball into the *a*-th hole. Numbers *a* and *b* are positive integers do not exceeding *N*.## Output

For each move of the type 1 output two space-separated numbers on a separate line — the number of the last hole the ball visited before leaving the row and the number of jumps it made.

## Examples

## Input


```
8 5  
1 1 1 1 1 2 8 2  
1 1  
0 1 3  
1 1  
0 3 4  
1 2  

```
## Output


```
8 7  
8 5  
7 3  

```


#### tags 

#2700 #data_structures #dsu 