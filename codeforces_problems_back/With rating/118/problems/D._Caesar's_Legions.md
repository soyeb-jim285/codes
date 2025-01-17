<h1 style='text-align: center;'> D. Caesar's Legions</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Gaius Julius Caesar, a famous general, loved to line up his soldiers. Overall the army had *n*1 footmen and *n*2 horsemen. Caesar thought that an arrangement is not beautiful if somewhere in the line there are strictly more that *k*1 footmen standing successively one after another, or there are strictly more than *k*2 horsemen standing successively one after another. Find the number of beautiful arrangements of the soldiers. 

## Note

 that all *n*1 + *n*2 warriors should be present at each arrangement. All footmen are considered indistinguishable among themselves. Similarly, all horsemen are considered indistinguishable among themselves.

## Input

The only line contains four space-separated integers *n*1, *n*2, *k*1, *k*2 (1 ≤ *n*1, *n*2 ≤ 100, 1 ≤ *k*1, *k*2 ≤ 10) which represent how many footmen and horsemen there are and the largest acceptable number of footmen and horsemen standing in succession, correspondingly.

## Output

Print the number of beautiful arrangements of the army modulo 100000000 (108). That is, print the number of such ways to line up the soldiers, that no more than *k*1 footmen stand successively, and no more than *k*2 horsemen stand successively.

## Examples

## Input


```
2 1 1 10  

```
## Output


```
1  

```
## Input


```
2 3 1 2  

```
## Output


```
5  

```
## Input


```
2 4 1 1  

```
## Output


```
0  

```
## Note

Let's mark a footman as 1, and a horseman as 2.

In the first sample the only beautiful line-up is: 121

In the second sample 5 beautiful line-ups exist: 12122, 12212, 21212, 21221, 22121



#### tags 

#1700 #dp 