<h1 style='text-align: center;'> D. Eternal Victory</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Valerian was captured by Shapur. The victory was such a great one that Shapur decided to carve a scene of Valerian's defeat on a mountain. So he had to find the best place to make his victory eternal!

He decided to visit all *n* cities of Persia to find the best available mountain, but after the recent war he was too tired and didn't want to traverse a lot. So he wanted to visit each of these *n* cities at least once with smallest possible traverse. Persian cities are connected with bidirectional roads. You can go from any city to any other one using these roads and there is a unique path between each two cities.

All cities are numbered 1 to *n*. Shapur is currently in the city 1 and he wants to visit all other cities with minimum possible traverse. He can finish his travels in any city.

Help Shapur find how much He should travel.

## Input

First line contains a single natural number *n* (1 ≤ *n* ≤ 105) — the amount of cities.

Next *n* - 1 lines contain 3 integer numbers each *x**i*, *y**i* and *w**i* (1 ≤ *x**i*, *y**i* ≤ *n*, 0 ≤ *w**i* ≤ 2 × 104). *x**i* and *y**i* are two ends of a road and *w**i* is the length of that road.

## Output

A single integer number, the minimal length of Shapur's travel.

Please, do not use %lld specificator to read or write 64-bit integers in C++. It is preffered to use cout (also you may use %I64d).

## Examples

## Input


```
3  
1 2 3  
2 3 4  

```
## Output


```
7  

```
## Input


```
3  
1 2 3  
1 3 3  

```
## Output


```
9  

```


#### tags 

#1800 #dfs_and_similar #graphs #greedy #shortest_paths #trees 