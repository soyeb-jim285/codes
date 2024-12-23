<h1 style='text-align: center;'> D. Roads not only in Berland</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Berland Government decided to improve relations with neighboring countries. First of all, it was decided to build new roads so that from each city of Berland and neighboring countries it became possible to reach all the others. There are *n* cities in Berland and neighboring countries in total and exactly *n* - 1 two-way roads. Because of the recent financial crisis, the Berland Government is strongly pressed for money, so to build a new road it has to close some of the existing ones. Every day it is possible to close one existing road and immediately build a new one. Your task is to determine how many days would be needed to rebuild roads so that from each city it became possible to reach all the others, and to draw a plan of closure of old roads and building of new ones.

## Input

The first line contains integer *n* (2 ≤ *n* ≤ 1000) — amount of cities in Berland and neighboring countries. Next *n* - 1 lines contain the description of roads. Each road is described by two space-separated integers *a**i*, *b**i* (1 ≤ *a**i*, *b**i* ≤ *n*, *a**i* ≠ *b**i*) — pair of cities, which the road connects. It can't be more than one road between a pair of cities. No road connects the city with itself.

## Output

## Output

 the answer, number *t* — what is the least amount of days needed to rebuild roads so that from each city it became possible to reach all the others. Then output *t* lines — the plan of closure of old roads and building of new ones. Each line should describe one day in the format i j u v — it means that road between cities i and j became closed and a new road between cities u and v is built. Cities are numbered from 1. If the answer is not unique, output any.

## Examples

## Input


```
2  
1 2  

```
## Output


```
0  

```
## Input


```
7  
1 2  
2 3  
3 1  
4 5  
5 6  
6 7  

```
## Output


```
1  
3 1 3 7  

```


#### tags 

#1900 #dsu #graphs #trees 