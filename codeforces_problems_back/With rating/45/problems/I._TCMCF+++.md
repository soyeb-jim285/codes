<h1 style='text-align: center;'> I. TCMCF+++</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Vasya has gotten interested in programming contests in TCMCF+++ rules. On the contest *n* problems were suggested and every problem had a cost — a certain integral number of points (perhaps, negative or even equal to zero). According to TCMCF+++ rules, only accepted problems can earn points and the overall number of points of a contestant was equal to the product of the costs of all the problems he/she had completed. If a person didn't solve anything, then he/she didn't even appear in final standings and wasn't considered as participant. Vasya understood that to get the maximal number of points it is not always useful to solve all the problems. Unfortunately, he understood it only after the contest was finished. Now he asks you to help him: find out what problems he had to solve to earn the maximal number of points.

## Input

The first line contains an integer *n* (1 ≤ *n* ≤ 100) — the number of the suggested problems. The next line contains *n* space-separated integers *c**i* ( - 100 ≤ *c**i* ≤ 100) — the cost of the *i*-th task. The tasks' costs may coinсide.

## Output

Print space-separated the costs of the problems that needed to be solved to get the maximal possible number of points. Do not forget, please, that it was necessary to solve at least one problem. If there are several solutions to that problem, print any of them.

## Examples

## Input


```
5  
1 2 -3 3 3  

```
## Output


```
3 1 2 3   

```
## Input


```
13  
100 100 100 100 100 100 100 100 100 100 100 100 100  

```
## Output


```
100 100 100 100 100 100 100 100 100 100 100 100 100   

```
## Input


```
4  
-2 -2 -2 -2  

```
## Output


```
-2 -2 -2 -2   

```
  


#### tags 

#1400 #greedy 