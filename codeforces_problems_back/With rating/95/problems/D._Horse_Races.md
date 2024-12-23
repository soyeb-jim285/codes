<h1 style='text-align: center;'> D. Horse Races</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Petya likes horse racing very much. Horses numbered from *l* to *r* take part in the races. Petya wants to evaluate the probability of victory; for some reason, to do that he needs to know the amount of nearly lucky horses' numbers. A nearly lucky number is an integer number that has at least two lucky digits the distance between which does not exceed *k*. Petya learned from some of his mates from Lviv that lucky digits are digits 4 and 7. The distance between the digits is the absolute difference between their positions in the number of a horse. For example, if *k* = 2, then numbers 412395497, 404, 4070400000070004007 are nearly lucky and numbers 4, 4123954997, 4007000040070004007 are not.

Petya prepared *t* intervals [*l**i*, *r**i*] and invented number *k*, common for all of them. Your task is to find how many nearly happy numbers there are in each of these segments. Since the answers can be quite large, output them modulo 1000000007 (109 + 7).

## Input

The first line contains two integers *t* and *k* (1 ≤ *t*, *k* ≤ 1000) — the number of segments and the distance between the numbers correspondingly. Next *t* lines contain pairs of integers *l**i* and *r**i* (1 ≤ *l* ≤ *r* ≤ 101000). All numbers are given without the leading zeroes. Numbers in each line are separated by exactly one space character.

## Output

## Output

 *t* lines. In each line print one integer — the answer for the corresponding segment modulo 1000000007 (109 + 7).

## Examples

## Input


```
1 2  
1 100  

```
## Output


```
4  

```
## Input


```
1 2  
70 77  

```
## Output


```
2  

```
## Input


```
2 1  
1 20  
80 100  

```
## Output


```
0  
0  

```
## Note

In the first sample, the four nearly lucky numbers are 44, 47, 74, 77.

In the second sample, only 74 and 77 are in the given segment.



#### tags 

#2500 #dp #math 