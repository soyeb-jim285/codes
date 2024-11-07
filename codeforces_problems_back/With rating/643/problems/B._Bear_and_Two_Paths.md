<h1 style='text-align: center;'> B. Bear and Two Paths</h1>

<h5 style='text-align: center;'>time limit per test: 2 seconds</h5>
<h5 style='text-align: center;'>memory limit per test: 256 megabytes</h5>

Bearland has *n* cities, numbered 1 through *n*. Cities are connected via bidirectional roads. Each road connects two distinct cities. No two roads connect the same pair of cities.

Bear Limak was once in a city *a* and he wanted to go to a city *b*. There was no direct connection so he decided to take a long walk, visiting each city exactly once. Formally: 

* There is no road between *a* and *b*.
* There exists a sequence (path) of *n* distinct cities *v*1, *v*2, ..., *v**n* that *v*1 = *a*, *v**n* = *b* and there is a road between *v**i* and *v**i* + 1 for ![](images/23e5d4ea4f6228395f4a124f9060fbe08e8efbfc.png).

On the other day, the similar thing happened. Limak wanted to travel between a city *c* and a city *d*. There is no road between them but there exists a sequence of *n* distinct cities *u*1, *u*2, ..., *u**n* that *u*1 = *c*, *u**n* = *d* and there is a road between *u**i* and *u**i* + 1 for ![](images/23e5d4ea4f6228395f4a124f9060fbe08e8efbfc.png).

Also, Limak thinks that there are at most *k* roads in Bearland. He wonders whether he remembers everything correctly.

Given *n*, *k* and four distinct cities *a*, *b*, *c*, *d*, can you find possible paths (*v*1, ..., *v**n*) and (*u*1, ..., *u**n*) to satisfy all the given conditions? Find any solution or print -1 if it's impossible.

## Input

The first line of the input contains two integers *n* and *k* (4 ≤ *n* ≤ 1000, *n* - 1 ≤ *k* ≤ 2*n* - 2) — the number of cities and the maximum allowed number of roads, respectively.

The second line contains four distinct integers *a*, *b*, *c* and *d* (1 ≤ *a*, *b*, *c*, *d* ≤ *n*).

## Output

Print -1 if it's impossible to satisfy all the given conditions. Otherwise, print two lines with paths descriptions. The first of these two lines should contain *n* distinct integers *v*1, *v*2, ..., *v**n* where *v*1 = *a* and *v**n* = *b*. The second line should contain *n* distinct integers *u*1, *u*2, ..., *u**n* where *u*1 = *c* and *u**n* = *d*.

Two paths generate at most 2*n* - 2 roads: (*v*1, *v*2), (*v*2, *v*3), ..., (*v**n* - 1, *v**n*), (*u*1, *u*2), (*u*2, *u*3), ..., (*u**n* - 1, *u**n*). Your answer will be considered wrong if contains more than *k* distinct roads or any other condition breaks. ## Note

 that (*x*, *y*) and (*y*, *x*) are the same road.

## Examples

## Input


```
7 11  
2 4 7 3  

```
## Output


```
2 7 1 3 6 5 4  
7 1 5 4 6 2 3  

```
## Input


```
1000 999  
10 20 30 40  

```
## Output


```
-1  

```
## Note

In the first sample test, there should be 7 cities and at most 11 roads. The provided sample solution generates 10 roads, as in the drawing. You can also see a simple path of length *n* between 2 and 4, and a path between 7 and 3.

 ![](images/58dec3e8514751ba57473ff99eae98f6a4c57658.png) 

#### tags 

#1600 #constructive_algorithms #graphs 